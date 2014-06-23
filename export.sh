#!/bin/sh -v
rm -rf llvm-trunk
svn export -r 211495 http://llvm.org/svn/llvm-project/llvm/trunk llvm-trunk
svn export -r 211495 http://llvm.org/svn/llvm-project/cfe/trunk  llvm-trunk/tools/clang
find llvm-trunk -type f -exec textcrlf {} \; | xargs dos2unix
tar cvfz llvm-trunk-r211495.tar.gz llvm-trunk
