import torch
import torch.nn as nn

class mvt(nn.Module):
  def __init__(self):
    super(mvt, self).__init__()
  
  def forward(self, A1, A2, y1, y2):
    x1 = A1 @ y1
    x2 = A2.T @ y2
    return x1, x2