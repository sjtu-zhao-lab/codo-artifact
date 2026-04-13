import torch
import torch.nn as nn

class bicg(nn.Module):
  def __init__(self):
    super(bicg, self).__init__()
  
  def forward(self, A1, A2, r, p):
    s = r @ A1
    q = A2 @ p
    return s, q
