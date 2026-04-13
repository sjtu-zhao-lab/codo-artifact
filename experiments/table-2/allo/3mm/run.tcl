# Project name
set hls_prj kernel_3mm.prj
# Open/reset the project
open_project -reset ${hls_prj}
# Top function of the design is "main_graph"
set_top kernel_3mm
# Add design and testbench files
add_files "k3mm.cpp"
# Create a solution
open_solution "kernel_3mm" -flow_target vitis
# Use Alveo U280 device
set_part {xcu280-fsvh2892-2L-e}
# Target clock period is 5ns (200MHz)
create_clock -period 5
# Synthesize the design
csynth_design
# Exit Vitis HLS
exit
