#!/bin/sh
cd llvm-trunk
sed -i -e "s/off_t offset/_off_t  offset/g" ./include/llvm-c/lto.h
sed -i -e "s/static std::once_flag LibclangGlobalInitFlag;/static bool LibclangGlobalInitFlag=false;/g" ./tools/clang/tools/libclang/CIndex.cpp
sed -i -e "s/std::call_once(LibclangGlobalInitFlag, initializeLibClang);/if(\!LibclangGlobalInitFlag){LibclangGlobalInitFlag=true;initializeLibClang();}/g" ./tools/clang/tools/libclang/CIndex.cpp
sed -i -e "s/include lib tools runtime docs unittests/include lib tools runtime unittests/g" ./tools/clang/Makefile
./configure CC=gcc CXX=g++ --enable-optimized
make CXXFLAGS="-D_GLIBCXX_HAVE_FENV_H"
#make unittests
#make install
