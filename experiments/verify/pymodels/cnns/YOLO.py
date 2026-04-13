import torch
import torch.nn as nn
import torch.nn.functional as F

'''
9. YOLO (Tiny-YOLO Style)
This architecture is a simplified version of YOLO, using a series of 
convolutions and max-pooling layers for object detection feature extraction.
'''

class YOLO(nn.Module):
    def __init__(self):
        super(YOLO, self).__init__()
        # 特征提取阶段
        self.conv1 = nn.Conv2d(3, 16, kernel_size=3, padding=1, stride=1)
        self.pool1 = nn.MaxPool2d(kernel_size=2, stride=2)
        self.conv2 = nn.Conv2d(16, 32, kernel_size=3, padding=1, stride=1)
        self.pool2 = nn.MaxPool2d(kernel_size=2, stride=2)
        self.conv3 = nn.Conv2d(32, 64, kernel_size=3, padding=1, stride=1)
        self.pool3 = nn.MaxPool2d(kernel_size=2, stride=2)
        self.conv4 = nn.Conv2d(64, 128, kernel_size=3, padding=1, stride=1)
        self.pool4 = nn.MaxPool2d(kernel_size=2, stride=2)
        self.conv5 = nn.Conv2d(128, 256, kernel_size=3, padding=1, stride=1)
        self.pool5 = nn.MaxPool2d(kernel_size=2, stride=2)
        self.conv6 = nn.Conv2d(256, 512, kernel_size=3, padding=1, stride=1)
        self.pool6 = nn.MaxPool2d(kernel_size=2, stride=2)
        
        # 加深层
        self.conv7 = nn.Conv2d(512, 512, kernel_size=3, padding=1, stride=1)
        self.conv8 = nn.Conv2d(512, 1024, kernel_size=3, padding=1, stride=1)
        self.conv9 = nn.Conv2d(1024, 1024, kernel_size=3, padding=1, stride=1)
        
        # 全连接/稠密层 (使用卷积实现)
        # 经过 6 次池化，1280x384 变为 20x6
        self.fc10 = nn.Linear(1024*20*6, 256)
        
        # 最后的分类与回归层
        self.fc11 = nn.Linear(256, 4096)
        self.fc12 = nn.Linear(4096, 1470)

    def forward(self, x):
        # 卷积+池化链
        x = F.relu(self.conv1(x))
        x = self.pool1(x)
        x = F.relu(self.conv2(x))
        x = self.pool2(x)
        x = F.relu(self.conv3(x))
        x = self.pool3(x)
        x = F.relu(self.conv4(x))
        x = self.pool4(x)
        x = F.relu(self.conv5(x))
        x = self.pool5(x)
        x = F.relu(self.conv6(x))
        x = self.pool6(x)
        
        # 深度卷积层
        x = F.relu(self.conv7(x))
        x = F.relu(self.conv8(x))
        x = F.relu(self.conv9(x))
        
        # 转换层
        x = torch.flatten(x, 1) 
        # x = x.view(x.size(0), -1)
        x = self.fc10(x)
        # x = self.fc10_pool(x)
        # x = self.fc10_conv(x)
        x = x.view(x.size(0), -1)
        
        # 全连接层
        x = F.relu(self.fc11(x))
        x = self.fc12(x)
        return x