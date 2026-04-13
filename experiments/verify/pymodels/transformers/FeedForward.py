import torch
import torch.nn as nn

class FeedForward(nn.Module):
    def __init__(self, embed_dim, ff_dim, dropout=0.1):
        super(FeedForward, self).__init__()
        self.fc1 = nn.Linear(embed_dim, ff_dim)
        self.fc2 = nn.Linear(ff_dim, embed_dim)
        self.relu = nn.ReLU()
        self.dropout = nn.Dropout(dropout)

    def forward(self, x):
        x = self.dropout(self.relu(self.fc1(x)))
        x = self.fc2(x)
        return x

# # Example usage
# embed_dim = 512
# ff_dim = 2048
# feed_forward = FeedForward(embed_dim, ff_dim)
# x = torch.randn(32, 10, embed_dim)  # Batch of 32, sequence length of 10, embedding dimension of 512
# out = feed_forward(x)
# print(out.shape)  # Should be (32, 10, 512)
