# Project name
set hls_prj resnet18_paper.prj

# Open/reset the project
open_project ${hls_prj} 

# Top function of the design is "top"
set_top main_graph

# Add design and testbench files
add_files resnet18.cpp

open_solution "large-8"
# Use Zynq device
set_part {xcu280-fsvh2892-2L-e}

# Target clock period is 5ns
create_clock -period 5

# Directives 

############################################

# Simulate the C++ design
# csim_design -O
# Synthesize the design
csynth_design
# Co-simulate the design
# cosim_design
# Implement the design
#export_design -flow impl

exit
