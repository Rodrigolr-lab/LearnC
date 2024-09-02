#!bin/bash
# The build system for handmade Hero

mkdir ../build
pushd ../build
clang -g -o handmade ../handmade/osx_main.mm
popd
