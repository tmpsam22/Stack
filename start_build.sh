#!/bin/bash

if [ ! -d build ]
then
     mkdir build
fi

cd build && \
cmake .. && \
cmake --build .  && \
echo $'Russian      Bear    Sibirovich
Dmitriev Aleksandr   Dmitrievich
Wild West Cowboy\n' > names.txt && \
./first_lab names.txt fromstack.txt
# names.txt is input file
# fromstack.txt is output file
