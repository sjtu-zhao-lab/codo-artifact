import torch
import torch.nn as nn
import torch.nn.functional as F

'''
8. VGG Network
VGG models are characterized by their pyramidal shape, where the bottom layers 
near the image are wide, while the top layers are deep. It uses small 3x3 filters 
with a stride of 1.
'''

class VGG16(nn.Module):
    # VGG-16 style configuration
    cfg = [32, 32, 'M', 64, 64, 'M', 128, 128, 128,
           'M', 256, 256, 256, 'M', 512, 512, 512, 'M']

    def __init__(self, num_classes=1000, num_conv_channels=512, num_fc_channels=2048):
        super(VGG16, self).__init__()
        # 自动化构建卷积层部分
        self.features = self._make_layers(self.cfg)
        
        # 中间过渡层：卷积核大小为 7x7
        self.conv = nn.Conv2d(num_conv_channels, num_fc_channels, kernel_size=7)
        
        # 分类器部分
        self.classifier = nn.Sequential(
            nn.Linear(num_fc_channels, num_fc_channels),
            nn.ReLU(True),
            nn.Linear(num_fc_channels, num_classes),
        )

    def _make_layers(self, cfg):
        layers = []
        in_channels = 3
        for v in cfg:
            if v == 'M':
                layers += [nn.MaxPool2d(kernel_size=2, stride=2)]
            else:
                conv2d = nn.Conv2d(in_channels, v, kernel_size=3, padding=1)
                layers += [conv2d, nn.ReLU(inplace=True)]
                in_channels = v
        return nn.Sequential(*layers)

    def forward(self, x):
        # 特征提取
        out = self.features(x)
        # 过渡层卷积与激活
        out = F.relu(self.conv(out))
        # 展平处理
        out = torch.flatten(out, 1)
        # 全连接层分类
        out = self.classifier(out)
        return out
