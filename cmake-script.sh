#!/bin/bash
cd build
export PKG_CONFIG_PATH="/usr/lib/x86_64-linux-gnu/pkgconfig:/usr/share/pkgconfig"
cmake ..
make
cd ..
