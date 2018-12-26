#!/bin/bash

pwd_back=$(pwd)

function gtest_build() {
    mkdir ./googletest/build
    cd ./googletest/build && cmake ..
    make -j$(grep -c processor /proc/cpuinfo)
    cd $pwd_back
}

function ffmpeg_build() {
    cd ./FFmpeg && ./configure --prefix=./build --enable-gpl --enable-static --disable-shared --enable-pthreads --enable-debug 
    make -j$(grep -c processor /proc/cpuinfo)
	make install
    cd $pwd_back
}

gtest_build
ffmpeg_build
