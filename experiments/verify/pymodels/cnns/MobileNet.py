import torch
import torch.nn as nn
import torch.nn.functional as F

'''
6. MobileNet (V1)
MobileNet is based on a streamlined architecture that uses depthwise separable convolutions 
to build light weight deep neural networks.
'''

class Block(nn.Module):
    '''Depthwise conv + Pointwise conv'''
    def __init__(self, in_planes, out_planes, stride=1):
        super(Block, self).__init__()
        # Depthwise Convolution
        self.conv1 = nn.Conv2d(in_planes, in_planes, kernel_size=3,
                               stride=stride, padding=1, groups=in_planes, bias=False)
        # Pointwise Convolution
        self.conv2 = nn.Conv2d(in_planes, out_planes,
                               kernel_size=1, stride=1, padding=0, bias=False)

    def forward(self, x):
        out = F.relu(self.conv1(x))
        out = F.relu(self.conv2(out))
        return out


class MobileNet(nn.Module):
    # (planes, stride): stride=2 represents downsampling
    cfg = [64, (128, 2), 128, (256, 2), 256, (512, 2),
           512, 512, 512, 512, 512, (1024, 2), 1024]

    def __init__(self, num_classes=1000):
        super(MobileNet, self).__init__()
        # Initial standard convolution
        self.conv1 = nn.Conv2d(3, 32, kernel_size=3,
                               stride=2, padding=1, bias=False)
        
        self.layers = self._make_layers(in_planes=32)
        self.avgpool = nn.AdaptiveAvgPool2d((1, 1))
        self.linear = nn.Linear(1024, num_classes)

    def _make_layers(self, in_planes):
        layers = []
        for x in self.cfg:
            out_planes = x if isinstance(x, int) else x[0]
            stride = 1 if isinstance(x, int) else x[1]
            layers.append(Block(in_planes, out_planes, stride))
            in_planes = out_planes
        return nn.Sequential(*layers)

    def forward(self, x):
        out = F.relu(self.conv1(x))
        out = self.layers(out)
        out = self.avgpool(out)
        out = torch.flatten(out, 1)
        out = self.linear(out)
        return out