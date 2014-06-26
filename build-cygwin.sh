#!/bin/sh
chmod a+x ./llvm-trunk/autoconf/AutoRegen.sh
chmod a+x ./llvm-trunk/autoconf/config.guess
chmod a+x ./llvm-trunk/autoconf/config.sub
chmod a+x ./llvm-trunk/autoconf/install-sh
chmod a+x ./llvm-trunk/autoconf/missing
chmod a+x ./llvm-trunk/autoconf/mkinstalldirs
chmod a+x ./llvm-trunk/configure
chmod a+x ./llvm-trunk/examples/Kaleidoscope/MCJIT/cached/genk-timing.py
chmod a+x ./llvm-trunk/examples/Kaleidoscope/MCJIT/cached/split-lib.py
chmod a+x ./llvm-trunk/examples/Kaleidoscope/MCJIT/complete/genk-timing.py
chmod a+x ./llvm-trunk/examples/Kaleidoscope/MCJIT/complete/split-lib.py
chmod a+x ./llvm-trunk/examples/Kaleidoscope/MCJIT/lazy/genk-timing.py
cd llvm-trunk
./configure CC=gcc CXX=g++ --enable-optimized
make
#make unittests
#make install
