ROOT_DIR := $(notdir $(CURDIR))
ifndef QCONFIG
QCONFIG=qconfig.mk
endif
include $(QCONFIG)

HOST_MKIFS := mkifs

#SUFFIXES := .build .ifs .bin
SUFFIXES :=  .bin

.PHONY: all clean

all: ifs-bcm2836.bin 

clean: 
	$(RM_HOST) ifs-*.* bcm2836.build

ifs-bcm2836.bin: bcm2836.build
	$(HOST_MKIFS) -r../install -v $(MKIFSFLAGS) $^ $@

