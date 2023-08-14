#!/bin/bash

rm -r build
mkdir build
cd build
cmake ..
make -j
sudo make install