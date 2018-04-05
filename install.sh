#!/bin/bash

if [[ $_ == $0 ]]; then
	echo "Run script via "source" command:"
	echo "\$ source install.sh"
	exit 1
fi

make clean
make all
echo 'commitshot installed'
alias gitshot='commitshot && git commit'
