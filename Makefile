#
# stm8s - STM8 SDCC cooperative multitasking operating system
# Copyright (c) 2022 rksdna
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.
#

# Project files

TARGET = app

HEX = $(TARGET).ihx
MAP = $(TARGET).map
CDB = $(TARGET).cdb
LNK = $(TARGET).lk

SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.rel)
SYM = $(SRC:.c=.sym)
LST = $(SRC:.c=.lst)
RST = $(SRC:.c=.rst)
ASM = $(SRC:.c=.asm)
DEP = $(SRC:.c=.dep)

# Tools and flags

CC = sdcc
AS = sdasstm8
SZ = stm8-size
RM = rm -f

CFLAGS = -mstm8 --opt-code-size -DSTM8S103
LFLAGS = -mstm8 --opt-code-size -DSTM8S103 --out-fmt-ihx

# Targets

.PHONY: all clean install

all : $(HEX)

$(HEX): $(OBJ) $(DEP)
	@echo "Linking $(HEX)..."
	$(CC) $(LFLAGS) $(OBJ) -o $(HEX)

%.dep: %.c
	@echo "Dependancy $@..."
	$(CC) $(CFLAGS) -M $< > $@

%.rel: %.c
	@echo "Compiling $@..."
	$(CC) $(CFLAGS) -c $< -o $@

install: $(HEX)
	@echo "Installing $(HEX)..."
	stm8flash -c stlinkv2 -p stm8s003f3 -w $(HEX)

prepare:
	@echo "Preparing"
	stm8flash -c stlinkv2 -p stm8s003f3 -u

clean:
	@echo "Cleaning..."
	$(RM) $(OBJ) $(SYM) $(LST) $(RST) $(ASM) $(DEP) $(HEX) $(MAP) $(CDB) $(LNK)

-include $(DEP)
