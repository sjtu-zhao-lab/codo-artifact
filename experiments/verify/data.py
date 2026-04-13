import torch
from utils import randTensor

dtype = torch.float32

# fix torch seed
torch.manual_seed(0)
# synthetic params
I, J, K, L, M, N, O, P, Q = 64, 32, 64, 64, 128, 128, 64, 32, 16
S = 64

model_configs = {
  # new benchmark
  "new_benchmark" : {
    "MNIST" : {
      "class": "MNIST",
      "config" : {},
      "input" : (
        randTensor(8, 1024, dtype=dtype),
      )
    },
  },
  # polybench medium
  "polybench" : {
    "gemm" : {
      "class": "gemm",
      "config" : {},
      "input" : (
        randTensor(200, 240, dtype=dtype),
        randTensor(240, 220, dtype=dtype),
        randTensor(200, 220, dtype=dtype)
      )
    },
    "k2mm" : {
      "class": "k2mm",
      "config" : {},
      "input" : (
        randTensor(180, 210, dtype=dtype),     # A
        randTensor(210, 190, dtype=dtype),     # B
        randTensor(190, 220, dtype=dtype),     # C
        randTensor(180, 220, dtype=dtype)      # D
      )
    },
    "k3mm" : {
      "class": "k3mm",
      "config" : {},
      "input" : (
        randTensor(180, 200, dtype=dtype),
        randTensor(200, 190, dtype=dtype),
        randTensor(190, 220, dtype=dtype),
        randTensor(220, 210, dtype=dtype)
      )
    },
    "atax" : {
      "class": "atax",
      "config" : {},
      "input" : (
        randTensor(390, 410, dtype=dtype),  # A
        randTensor(410, dtype=dtype)        # x
      )
    },
    "bicg" : {
      "class": "bicg",
      "config" : {},
      "input" : (
        randTensor(410, 390, dtype=dtype),  # A
        randTensor(410, 390, dtype=dtype),  # A copy
        randTensor(410, dtype=dtype),       # r
        randTensor(390, dtype=dtype)        # p
      )
    },
    "mvt" : {
      "class": "mvt",
      "config" : {},
      "input" : (
        randTensor(400, 400, dtype=dtype),  # A
        randTensor(400, 400, dtype=dtype),  # A copy
        randTensor(400, dtype=dtype),       # y1
        randTensor(400, dtype=dtype)        # y2
      )
    },
    "gesummv" : {
      "class": "gesummv",
      "config" : {},
      "input" : (
        randTensor(250, 250, dtype=dtype),  # A
        randTensor(250, 250, dtype=dtype),  # B
        randTensor(250, dtype=dtype)       # x
      )
    }
  },
  # mlps
  "mlps" : {
    "Autoencoder" : {
      "class": "Autoencoder",
      "config" : {},
      "input" : (
        randTensor(32, 784, dtype=dtype),
      )
    },
    "ResMLP" : {
      "class": "ResMLP",
      "config" : {},
      "input" : (
        randTensor(8, 1024, dtype=dtype),
      )
    }
  },
  # cnn
  "cnns" : {
      "ZFNet" : {
      "class": "ZFNet",
      "config" : dict(
        num_classes=1000
      ),
      "input" : (
        randTensor(1, 3, 224, 224, dtype=dtype),
      )
    },
    "YOLO" : {
      "class": "YOLO",
      "config" : dict(),
      "input" : (
        randTensor(1, 3, 1280, 384, dtype=dtype),
      )
    },
    "VGG16" : {
      "class": "VGG16",
      "config" : dict(
        num_classes=1000
      ),
      "input" : (
        randTensor(1, 3, 224, 224, dtype=dtype),
      )
    },
    "MobileNet" : {
      "class": "MobileNet",
      "config" : dict(
        num_classes=1000
      ),
      "input" : (
        randTensor(1, 3, 224, 224, dtype=dtype),
      )
    },
    "ResNet18" : {
      "class": "ResNet18",
      "config" : dict(
        num_classes=1000
      ),
      "input" : (
        randTensor(1, 3, 224, 224, dtype=dtype),
      )
    },
    "DepthwiseSeparableConvBlock" : {
      "class": "DepthwiseSeparableConvBlock",
      "config" : dict(
        in_channels=8,
        out_channels=8,
        stride=1
      ),
      "input" : (
        randTensor(1, 8, 112, 112, dtype=dtype),
      )
    },
    "ResidualBlock" : {
      "class": "ResidualBlock",
      "config" : dict(
        in_channels=16,
        out_channels=16,
        stride=1
      ),
      "input" : (
        randTensor(1, 16, 56, 56, dtype=dtype),
      )
    }
  },
  # transformers
  "transformers" : {
    "FeedForward" : {
      "class": "FeedForward",
      "config" : dict(
        embed_dim=128,
        ff_dim=256
      ),
      "input" : (
        randTensor(1, 512, 128, dtype=dtype),
      )
    },
    "GPT2": {
      "class": "GPT2",
      "config": {
        "embed_dim": 1024,          # Transformer Block 的嵌入维度
        "num_heads": 16            # 注意力头的数量
        # "dropout_rate": 0.1,       # Dropout 比率
        # "ffn_hidden_dim_multiplier": 4 # FFN 隐藏层维度是 embed_dim 的倍数
      },
      "input": (
        randTensor(1, 32, 1024, dtype=dtype), # 输入 token 序列
        # create_causal_mask(16, dtype=torch.bool)# 因果注意力掩码 (seq_length=16)
      )
    },
    "MultiHeadSelfAttention" : {
      "class": "MultiHeadSelfAttention",
      "config" : dict(
        embed_dim=128,
        num_heads=8
      ),
      "input" : (
        randTensor(1, 64, 128, dtype=dtype),
      )
    }
  },
  # synthetic
  "synthetic" : {
    "k7mmseq_balanced" : {
      "class": "k7mmseq",
      "config" : {},
      "input" : (
        randTensor(S, S, dtype=dtype),
        randTensor(S, S, dtype=dtype),
        randTensor(S, S, dtype=dtype),
        randTensor(S, S, dtype=dtype),
        randTensor(S, S, dtype=dtype),
        randTensor(S, S, dtype=dtype),
        randTensor(S, S, dtype=dtype),
        randTensor(S, S, dtype=dtype)
      )
    },
    "k7mmseq_unbalanced" : {
      "class": "k7mmseq",
      "config" : {},
      "input" : (
        randTensor(I, J, dtype=dtype),
        randTensor(J, K, dtype=dtype),
        randTensor(K, L, dtype=dtype),
        randTensor(L, M, dtype=dtype),
        randTensor(M, N, dtype=dtype),
        randTensor(N, O, dtype=dtype),
        randTensor(O, P, dtype=dtype),
        randTensor(P, Q, dtype=dtype)
      )
    }
  }
}
