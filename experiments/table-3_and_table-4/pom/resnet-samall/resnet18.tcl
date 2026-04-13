# Project name
set hls_prj resnet18_moti.prj

# Open/reset the project
open_project ${hls_prj} 

# Top function of the design is "top"
set_top resnet18

# Add design and testbench files
add_files resnet18.cpp
# add_files -tb resnet18_allo_tb.cpp
# add_files -tb host.cpp -cflags "-std=gnu++0x"

open_solution "small-16"
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
