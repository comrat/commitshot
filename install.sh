#!/bin/bash

if [[ $_ == $0 ]]; then
	echo "Run script via "source" command:"
	echo "\$ source install.sh"
	exit 1
fi

make clean
make all
if [[ $? == 0 ]]; then
	echo 'commitshot build successfully'
	alias commitshot='commitshot && git commit'
else
	echo "Failed to build commitshot"
fi;
