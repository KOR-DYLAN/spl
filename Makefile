TOPDIR			:=$(dir $(abspath $(firstword $(MAKEFILE_LIST))))
NPROC			:=$(shell nproc)
CMAKE 			:=cmake
BUILD_DIR		:=build
OUTPUT_DIR		:=output
SOURCE_DIR		:=$(TOPDIR)
V				?=0

ifeq ($(V),1)
    VERBOSE=-v
endif

TOOLCHAIN_FILE 	:=cmake/toolchain/host-gnu.cmake
# TOOLCHAIN_FILE 	:=cmake/toolchain/aarch64-none-linux-gnu.cmake

# Debug | MinSizeRel | Release | RelWithDebInfo 
BUILD_TYPE		:=Debug

all: build

phony+=config
config:
	$(CMAKE) -DCMAKE_TOOLCHAIN_FILE=$(TOOLCHAIN_FILE) \
			 -DCMAKE_BUILD_TYPE:STRING=$(BUILD_TYPE) -DCMAKE_EXPORT_COMPILE_COMMANDS:BOOL=TRUE \
			 -S$(SOURCE_DIR) -B$(BUILD_DIR)

phony+=build
build: config
	$(CMAKE) --build $(BUILD_DIR) -j $(NPROC) $(VERBOSE)

phony+=clean
clean:
	rm -f *.raw
	rm -rf $(RESULT_DIR)
	rm -rf $(OUTPUT_DIR)
	rm -rf $(BUILD_DIR)

phony+=run
run: build
	rm -f output/bin/result
	./output/bin/sample

.PHONY: $(phony)