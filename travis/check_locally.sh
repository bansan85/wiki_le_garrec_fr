#!/bin/sh

cmake ../cpp
make -j8
mkdir -p wiki_le_garrec_fr_travis
make data_for_travis
make clang_fmt
cppcheck --enable=all --project=compile_commands.json --error-exitcode=1 --inline-suppr --template="{file},{line},{severity},{id},{message}" --suppressions-list=../cpp/cppcheck-suppressions.txt
make cmake_fmt
python3 /usr/lib/llvm/*/share/clang/run-clang-tidy.py
shellcheck -- **/*.sh
