import os
import importlib
import argparse as ap
from utils import convertTorchToMLIR, generateGoldenResults
from data import model_configs

# main function
if __name__ == "__main__":

  # args
  parser = ap.ArgumentParser()
  parser.add_argument("--benchmark", '-b', type=str, default="all", help="Benchmark of kernel to generate")
  parser.add_argument("--model", '-m', type=str, default="all", help="Model to generate")
  parser.add_argument("--model-folder", '-i', type=str, default="pymodels", help="Folder containing the model files")
  parser.add_argument("--output-path", '-o', type=str, default="./models", help="Path to save the generated models")
  args = parser.parse_args()
  model_folder = args.model_folder
  if(args.benchmark == "all"):
    benchmarks = model_configs.keys()
  else:
    benchmarks = [args.benchmark]
  for benchmark in benchmarks:
    if(args.model == "all"):
      models = model_configs[benchmark].keys()
    else:
      models = [args.model]

    output_path = f'{args.output_path}'

    model_path = f"./{model_folder}/{benchmark}"
    model_import_path = f"{model_folder}.{benchmark}"
    model_files = [f for f in os.listdir(model_path) if f.endswith(".py")]
    # Remove the ".py" extension to get module names
    model_modules = [f[:-3] for f in model_files]
    # Initialize an empty list to store the instantiated models
    model_instances = []
    # create model folder in {output_path} if not exist
    if not os.path.exists(f"{output_path}"):
      os.makedirs(f"{output_path}")
    # Import each module, instantiate the model, and append it to the list
    for model in models:
      try:
        if not os.path.exists(f"{output_path}/{model}"):
          os.makedirs(f"{output_path}/{model}")
          os.makedirs(f"{output_path}/{model}/mlir/input")
          os.makedirs(f"{output_path}/{model}/mlir/host")
          os.makedirs(f"{output_path}/{model}/mlir/kernel")
          os.makedirs(f"{output_path}/{model}/mlir/intermediates")
          os.makedirs(f"{output_path}/{model}/mlir/graphs")
          os.makedirs(f"{output_path}/{model}/hls/data")
          os.makedirs(f"{output_path}/{model}/hls/src")
          # os.makedirs(f"{output_path}/{model}/tapa/data")
          # os.makedirs(f"{output_path}/{model}/tapa/src")
        print(f"Model: {model}")
        # Import the module dynamically
        print(f"Importing: {model_folder}.{benchmark}.{model_configs[benchmark][model]['class']}")
        module = importlib.import_module(f"{model_folder}.{benchmark}.{model_configs[benchmark][model]['class']}")
        # Get the model class from the module
        model_class = getattr(module, model_configs[benchmark][model]['class'])

        config = model_configs[benchmark][model]['config']
        sample_input = model_configs[benchmark][model]['input']
        # Instantiate the model
        model_instance = model_class(**config)

        # Convert the model to MLIR
        convertTorchToMLIR(model_instance, sample_input, f"{output_path}/{model}/mlir/input/{model}.mlir", output_type="linalg-on-tensors", print_weights=True)
        
        # generate golden results
        inferenceTime = generateGoldenResults(model_instance, sample_input, f"{output_path}/{model}/hls/data/")
        # generateGoldenResults(model_instance, sample_input, f"{output_path}/{model}/tapa/data/golden")
        # print inference time in seconds
        # print(f"{model} inference time: {inferenceTime} seconds")
        # Append the instantiated model to the list
        # model_instances.append(model_instance)

        print(f"Model '{model}' successfully imported and initialized.")
      
      except Exception as e:
        print(f"Error importing or initializing model '{model}': {e}")


