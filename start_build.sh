#!/bin/bash

if [ ! -d build ]
then
     mkdir build
fi

cd build && \
cmake .. && \
cmake --build .  && \
./lab_with_person_keeper
