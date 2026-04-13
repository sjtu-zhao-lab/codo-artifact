import torch
import torch.nn as nn
import torch.nn.functional as F

'''
10. ZFNet
ZFNet is a classic convolutional neural network that won ILSVRC 2013. 
It is an improvement on AlexNet by using smaller filters and stride 
in the first layer to retain more information.
'''

class ZFNet(nn.Module):
    def __init__(self, num_classes=1000):
        super(ZFNet, self).__init__()
        # 卷积层阶段
        self.conv1 = nn.Conv2d(3, 96, kernel_size=7, padding=1, stride=2)
        self.pool1 = nn.MaxPool2d(kernel_size=3, stride=2)
        
        self.conv2 = nn.Conv2d(96, 256, kernel_size=5, padding=1, stride=2)
        self.pool2 = nn.MaxPool2d(kernel_size=3, stride=2)
        
        self.conv3 = nn.Conv2d(256, 384, kernel_size=3, padding=1, stride=1)
        self.conv4 = nn.Conv2d(384, 384, kernel_size=3, padding=1, stride=1)
        self.conv5 = nn.Conv2d(384, 256, kernel_size=3, padding=1, stride=1)
        self.pool5 = nn.MaxPool2d(kernel_size=3, stride=2)

        # 全连接层阶段
        # 经过上述池化，224x224 最终会缩小到 5x5 的空间尺寸
        # 替代原先的 Conv2d(256, 4096, kernel_size=5)，避免编译器 DSE 崩溃
        self.fc6 = nn.Linear(256 * 5 * 5, 4096)
        self.fc7 = nn.Linear(4096, 4096)
        self.fc8 = nn.Linear(4096, num_classes)

    def forward(self, x):
        # 卷积层传播
        x = F.relu(self.conv1(x))
        x = self.pool1(x)
        x = F.relu(self.conv2(x))
        x = self.pool2(x)
        x = F.relu(self.conv3(x))
        x = F.relu(self.conv4(x))
        x = F.relu(self.conv5(x))
        x = self.pool5(x)

        # 展平处理 (Batch, 256, 5, 5) -> (Batch, 6400)
        x = torch.flatten(x, 1)

        # 全连接传播
        x = F.relu(self.fc6(x))
        x = F.relu(self.fc7(x))
        x = self.fc8(x)
        return x