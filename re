#!/bin/bash

RUN_MEMCHECK=0

if [ $# -eq 1 ]; then
    if [ "$1" == "-mem" ]; then
        RUN_MEMCHECK=1
    fi
fi


if [ $RUN_MEMCHECK -eq 1 ]; then
    make clean && make test && ./run.sh -m
else
    make clean && make test && ./run.sh
fi
