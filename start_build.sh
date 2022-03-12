#!/bin/bash

if [ -d build ]
then
     rm -rf build
fi

mkdir build && \
cd build && \
cmake .. && \
cmake --build .  && \
echo $'Russian      Bear    Sibirovich
Dmitriev Aleksandr   Dmitrievich
Wild West Cowboy\n' > names.txt && \
./first_lab names.txt fromstack.txt
# names.txt is input file
# fromstack.txt is output file