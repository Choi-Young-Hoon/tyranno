#!/bin/bash

root_path=$(pwd)

function third_party_build() {
    cd $root_path/thirdparty && ./thirdparty_build.sh
}

function project_build() {
    mkdir $root_path/build
	cd $root_path/build && cmake ..
	make
}

third_party_build
project_build

