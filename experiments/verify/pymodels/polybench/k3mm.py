import torch
import torch.nn as nn


class k3mm(nn.Module):
  def __init__(self):
    super(k3mm, self).__init__()

  def forward(self, a, b, c, d):
    tmp1 = a @ b
    tmp2 = c @ d
    e = tmp1 @ tmp2
    return e
    
    