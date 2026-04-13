VPP := $(XILINX_VITIS)/bin/v++
EMCONFIGUTIL := $(XILINX_VITIS)/bin/emconfigutil
TARGET:= hw
DEVICE:= xilinx_u280_gen3x16_xdma_1_202211_1

# kernel targets
KRNL_XO := kernel.$(TARGET).xo
XCLBIN := kernel.$(TARGET).xclbin

# host target
HOST_EXE := host.exe

# config files target
EMCONFIG_FILE := emconfig.json

VPP_OPTS := -s -t $(TARGET) --platform $(DEVICE)
VPP_OPTS += --temp_dir ./all_builds/$(TARGET)
VPP_OPTS += --report_dir ./all_logs/$(TARGET)
VPP_OPTS += --log_dir ./all_logs/$(TARGET)


VPP_LINK_OPTS := --profile.data all:all:all --config connectivity.cfg

CFLAGS := -g -std=c++1y -I$(XILINX_XRT)/include -I$(XILINX_VIVADO)/include  -I../xcl2 -I/home/tools/Vitis_2023.2/Vitis_HLS/2023.2/include/
LFLAGS := -L$(XILINX_XRT)/lib -lOpenCL -lxrt_coreutil -lrt -luuid -pthread

# run time args
CMD_ARGS:= kernel.${TARGET}.xclbin

# primary build targets
.PHONY: xclbin host all

xclbin:  $(XCLBIN)
host: $(HOST_EXE) 

all: xclbin host 

clean:
	-$(RM) $(EMCONFIG_FILE) $(HOST_EXE) $(XCLBIN) 

cleanall: clean	
	rm -rf all_* *.log *.xclbin *.compile_summary *.link_summary *.info *.xo

# kernel rules
$(KRNL_XO): ./gpt-64_16x16.cpp
	$(RM) $@
	$(VPP) $(VPP_OPTS) -c -k main_graph -I'$(<D)' -o $@ $+

$(XCLBIN): $(KRNL_XO) 
	$(VPP) $(VPP_OPTS) -l -o $@ $(KRNL_XO) $+ $(VPP_LINK_OPTS)

# host rules
$(HOST_EXE): ./host.cpp ../xcl2/xcl2.cpp
	g++ $(CFLAGS) -o $@ $+ $(LFLAGS)
	@echo 'Compiled Host Executable: $(HOST_EXE)'

$(EMCONFIG_FILE):
	$(EMCONFIGUTIL) --nd 1 --od . --platform $(DEVICE)

run: $(XCLBIN) $(HOST_EXE) $(EMCONFIG_FILE)
	./$(HOST_EXE) $(CMD_ARGS) 
