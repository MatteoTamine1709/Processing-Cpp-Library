#!/bin/bash

BINARYNAME=ProcessingCpp
Color_Off='\033[0m'       # Text Reset
BIPurple='\033[1;95m'     # Purple

echo -e "${BIPurple}Choose an option${Color_Off}"
echo "1: Clear"
echo "2: Build"
read option


if [ $option == "1" ]
then
    rm -f BINARYNAME
    rm -rf build
elif [ $option == "2" ]
then
    mkdir build
    cd build
        cmake .. -G "Unix Makefiles"
        cmake -build .
        make

    cp -r ./$BINARYNAME ../$BINARYNAME
fi