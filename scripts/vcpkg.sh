#!/bin/bash

pushd .

mkdir -p ~/tools && cd ~/tools
git clone https://github.com/mlambda-net/vcpkg.git
cd ~/tools/vcpkg
./bootstrap-vcpkg.sh

case "$1" in
  exp) export;;
esac

popd

export() {
  echo 'export PATH=:$PATH:~/tools/vcpkg' >> ~/.profile
  echo 'export VCPKG_ROOT=~/tools/vcpkg' >> ~/.profile
  echo 'export VCPKG_DISABLE_METRICS=1' >> ~/.profile
  source ~/.profile
}