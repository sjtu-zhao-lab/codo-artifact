import torch
import torch.nn as nn
import torch.nn.functional as F

class GPT2(nn.Module):
    def __init__(self, embed_dim, num_heads):
        super().__init__()
        assert embed_dim % num_heads == 0, "embed_dim must be divisible by num_heads"
        self.num_heads = num_heads
        self.head_dim = embed_dim // num_heads

        # === LayerNorm 层 ===
        self.ln_1 = nn.LayerNorm(embed_dim, eps=1e-5)
        self.ln_2 = nn.LayerNorm(embed_dim, eps=1e-5)

        # === Self-Attention 层 ===
        self.query = nn.Linear(embed_dim, embed_dim)
        self.key   = nn.Linear(embed_dim, embed_dim)
        self.value = nn.Linear(embed_dim, embed_dim)
        self.out   = nn.Linear(embed_dim, embed_dim)

        # === Feed Forward 网络 ===
        self.mlp = nn.Sequential(
            nn.Linear(embed_dim, 4 * embed_dim),
            nn.GELU(), # 改为 GELU 激活函数
            nn.Linear(4 * embed_dim, embed_dim),
        )

    def forward(self, x):
        # ---------------------------
        # Step 1: Multi-Head Self-Attention (Pre-LN)
        # ---------------------------
        # GPT-2 使用 Pre-LayerNorm 结构
        residual = x
        x_norm = self.ln_1(x)

        batch_size, seq_len, embed_dim = x_norm.size()

        # Q, K, V 映射
        Q = self.query(x_norm)
        K = self.key(x_norm)
        V = self.value(x_norm)

        # 拆分 Heads
        Q = Q.view(batch_size, seq_len, self.num_heads, self.head_dim).transpose(1, 2)
        K = K.view(batch_size, seq_len, self.num_heads, self.head_dim).transpose(1, 2)
        V = V.view(batch_size, seq_len, self.num_heads, self.head_dim).transpose(1, 2)

        # 注意力分数计算
        scores = torch.matmul(Q, K.transpose(-2, -1)) / (self.head_dim ** 0.5)

        # 因果掩码 (Causal Mask)
        mask = torch.tril(torch.ones(seq_len, seq_len, device=x.device)).view(1, 1, seq_len, seq_len)
        scores = scores.masked_fill(mask == 0, float('-inf'))

        attn_weights = F.softmax(scores, dim=-1)
        context = torch.matmul(attn_weights, V)

        # 合并 Heads
        context = context.transpose(1, 2).contiguous().view(batch_size, seq_len, embed_dim)
        attn_output = self.out(context)

        # 第一个残差连接
        x = residual + attn_output

        # ---------------------------
        # Step 2: Feed Forward (Pre-LN)
        # ---------------------------
        residual = x
        x_norm = self.ln_2(x)
        mlp_out = self.mlp(x_norm)

        # 第二个残差连接
        out = residual + mlp_out

        return out