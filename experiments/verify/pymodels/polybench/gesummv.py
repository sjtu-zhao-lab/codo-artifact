import torch
import torch.nn as nn

class gesummv(nn.Module):
  def __init__(self):
    super(gesummv, self).__init__()
  
  def forward(self, A, B, x):
    tmp = A @ x
    y = B @ x
    y = 1.5 * tmp + 1.2 * y
    return y