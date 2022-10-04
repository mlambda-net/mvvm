#!/bin/bash
pushd .

cmake -E make_directory .build
cd build
cmake .. -G Ninja
cd ..
build-wrapper-linux-x86-64 --out-dir bw-output cmake --build .build/
sonar-scanner -X -Dsonar.cfamily.build-wrapper-output=bw-output

popd