import torch.nn as nn

class ResMLP(nn.Module):
    def __init__(self):
        super(ResMLP, self).__init__()
        self.fc1 = nn.Linear(1024, 512)
        self.fc2 = nn.Linear(512, 512)  # Same dimensions for residual connection
        self.fc3 = nn.Linear(512, 256)
        self.fc4 = nn.Linear(256, 10)
        self.relu = nn.ReLU()

    def forward(self, x):
        x = x.view(-1, 1024)
        residual = self.fc1(x)
        out = self.relu(residual)
        out = self.fc2(out)
        out += residual  # Residual connection
        out = self.relu(out)
        out = self.fc3(out)
        out = self.fc4(out)
        return out
