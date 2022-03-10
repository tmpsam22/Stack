#!/bin/bash

if [ -d build ]
then
     rm -rf build
fi

mkdir build && \
cd build && \
cmake .. && \
cmake --build .  && \
echo $'Russian Bear Sibirovich
Dmitriev Aleksandr Dmitrievich
Wild West Cowboy
Stay Alive !' > names.txt && \
./first_lab
