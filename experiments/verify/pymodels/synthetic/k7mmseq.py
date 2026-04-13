import torch
import torch.nn as nn

class k7mmseq(nn.Module):
  def __init__(self):
    super(k7mmseq, self).__init__()

  def forward(self, a, b, c, d, e, f, g, h):
    i = torch.mm(a, b)
    j = torch.mm(i, c)
    k = torch.mm(j, d)
    l = torch.mm(k, e)
    m = torch.mm(l, f)
    n = torch.mm(m, g)
    o = torch.mm(n, h)
    return o
