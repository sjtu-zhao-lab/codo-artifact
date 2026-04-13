import torch
import torch.nn as nn


class atax(nn.Module):
  def __init__(self):
    super(atax, self).__init__()

  def forward(self, A, x):
    tmp = A @ x
    y = A.T @ tmp
    return y