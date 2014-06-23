#!/bin/sh
chmod -R a+x llvm-trunk/
cd llvm-trunk
./configure CC=gcc CXX=g++ --enable-optimized
make
#make unittests
#make install
