#!/bin/bash

filename="$1"

# Check if the file exists
if [ ! -f "$filename" ]; then
    echo "File not found: $filename"
    exit 1
fi

# Compile the file
gcc "$filename" -o "${filename%.*}.out"
if [ -f "${filename%.*}.out" ]; then
    echo
    echo "PS ManasSingh\\2219046\\B2\\36> ./a.out"
    ./"${filename%.*}.out"
    echo
    echo "PS ManasSingh\\2219046\\B2\\36> "
    # Remove the executable
    rm -f "${filename%.*}.out"
    # Wait for enter key to be pressed
    read -p ""
fi
