# nesda 

[![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0)

CFG (control flow graph) aided NES ROM disassembler. 

with a ca65 macro assembler target. 

## Problem with Linear Dissassemblers

In a typical disassembler, da65 for example. how they typically work is in a linear way meaning from the start of the ROM to the end of the rom it will convert each byte
into assembler without any context of if its code or not. This apporach works for alot of cases but if you want an accurate source code representation this method 
wont be helpful. 


## My Approach

To get an accurate source code representation we create a data structure called a 
control flow graph and we traverse it in a depth first way.

Each node in the control flow graph is an opcode the PC will read from 
and each edge in the control flow graph is an instruction where the Program counter (PC) 
will change state such as jmp, jsr.. to name a few examples of this and invalid instructions 
for the bytes that are not in the control flow graph we can safely assume them as 
.byte macros and convert them accordingly.

## build instructions 

You only need CMake and g++ any one thats capable for C++17

```sh 
cmake -S . -B build 
cmake --build build --config Release
./nesda --help
```

