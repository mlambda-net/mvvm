#!/bin/bash
pushd .

export VERSION="3.25.1"
mkdir -p ~/tools/cmake
cd ~/tools/cmake
wget https://github.com/Kitware/CMake/releases/download/v$VERSION/cmake-$VERSION.tar.gz
tar -zxvf cmake-$VERSION.tar.gz
cd cmake-$VERSION
./bootstrap
make
sudo make install

popd