import torch
import torch.nn as nn


class k2mm(nn.Module):
  def __init__(self):
    super(k2mm, self).__init__()
    self.alpha = 0.1
    self.beta = 0.5
  def forward(self, a, b, c, d_in):
    tmp = a @ b
    tmp2 = tmp @ c
    d = tmp2 * self.beta + d_in * self.alpha
    return d
    