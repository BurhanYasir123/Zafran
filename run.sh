#!/bin/bash

~/Downloads/premake5 gmake
make clean
make
echo -----Running Sandbox------
./bin/Debug-linux-x86_64/Sandbox/Sandbox

