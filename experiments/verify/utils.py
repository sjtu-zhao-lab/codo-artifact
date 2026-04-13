import os

import torch_mlir
import torch_mlir.torchscript 
import torch 
import time


def convertTorchToMLIR(model, inputs, outPath, output_type="linalg-on-tensors", print_weights=False):
  model.train(False)
  model.eval()
  module = torch_mlir.torchscript.compile(model, inputs, output_type=output_type, use_tracing=True)
  with open(outPath, "w") as f:
    if print_weights:
      print(module.operation.get_asm(), file=f)
    else:
      print(module.operation.get_asm(large_elements_limit=1), file=f)



def generateGoldenResults(model, inputs, outPath):
    print(f"--- Debugging Golden Results ---")
    print(f"Target Path: {os.path.abspath(outPath)}")
    
    model.eval()
    with torch.no_grad():
        for i, tensor in enumerate(inputs):
            bin_data = tensor.detach().cpu().numpy().tobytes()
            print(f"Input {i} shape: {tensor.shape}, Bytes to write: {len(bin_data)}")
            
            file_path = os.path.join(outPath, f"input_{i}.bin")
            with open(file_path, "wb") as f:
                f.write(bin_data)
                f.flush()
                os.fsync(f.fileno())
        
        start = time.time()
        outputs = model(*inputs)
        end = time.time()
        
        if not isinstance(outputs, (list, tuple)):
            outputs = [outputs]
            
        for i, tensor in enumerate(outputs):
            bin_data = tensor.detach().cpu().numpy().tobytes()
            print(f"Output {i} shape: {tensor.shape}, Bytes to write: {len(bin_data)}")
            
            file_path = os.path.join(outPath, f"output_{i}.bin")
            with open(file_path, "wb") as f:
                f.write(bin_data)
                f.flush()
                os.fsync(f.fileno())
                
    print(f"--- Debugging Finished ---")
    return end - start

  
def randTensor(*shape, dtype=torch.float32):
  if dtype.is_floating_point:
    return torch.rand(*shape, dtype=dtype) * 2 - 1
  elif dtype == torch.bool:
    return torch.randint(0, 2, shape, dtype=dtype)
  else:
    if dtype.is_signed:
      return torch.randint(-10, 10, shape, dtype=dtype)
    else:
      return torch.randint(0, 10, shape, dtype=dtype)

  