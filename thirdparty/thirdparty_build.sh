#!/bin/bash

<<<<<<< HEAD
root_path=$(pwd)
=======
pwd_back=$(pwd)
>>>>>>> 17cd67652441dd88c5ac359ecc6b6d9a65b6b2a1

function gtest_build() {
    mkdir ./googletest/build
    cd ./googletest/build && cmake ..
    make -j$(grep -c processor /proc/cpuinfo)
<<<<<<< HEAD
    cd $root_path
=======
    cd $pwd_back
>>>>>>> 17cd67652441dd88c5ac359ecc6b6d9a65b6b2a1
}

function ffmpeg_build() {
    cd ./FFmpeg && ./configure --prefix=./build --enable-gpl --enable-static --disable-shared --enable-pthreads --enable-debug 
    make -j$(grep -c processor /proc/cpuinfo)
	make install
<<<<<<< HEAD
    cd $root_path
=======
    cd $pwd_back
>>>>>>> 17cd67652441dd88c5ac359ecc6b6d9a65b6b2a1
}

gtest_build
ffmpeg_build
