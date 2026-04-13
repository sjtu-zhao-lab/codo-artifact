set script_path [file normalize [info script]]
set script_dir [file dirname $script_path]
cd $script_dir
# Project name
set hls_prj depth.prj

# Open/reset the project
open_project ${hls_prj} 

#open_solution solution1 -flow_target vivado

# Top function of the design is "top"
set_top main_graph

# Add design and testbench files
add_files depth.cpp

open_solution "solution3"
# Use Zynq device
set_part {xcu280-fsvh2892-2L-e}

# Target clock period is 3.33ns
create_clock -period 5

# Directives 

############################################

# Simulate the C++ design
#csim_design -O
# Synthesize the design
csynth_design
# Co-simulate the design
#cosim_design
# Implement the design
#export_design -flow impl

exit
