import torch

class gemm(torch.nn.Module):
  def __init__(self):
    super(gemm, self).__init__()
    self.alpha = 0.1
    self.beta = 0.5
  def forward(self, a, b, c_in):
    c = a @ b
    c = c * self.beta + c_in * self.alpha
    return c

  
