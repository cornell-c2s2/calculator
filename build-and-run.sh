#!bin/bash
echo "Running: .pio/build/$1/program"
echo "Building and running: pio run -e $1"
pio run -e "$1" && .pio/build/"$1"/program