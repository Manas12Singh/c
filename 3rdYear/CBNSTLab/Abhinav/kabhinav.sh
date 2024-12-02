#!/bin/bash

filename="$1"

# Check if the file exists
if [ ! -f "$filename" ]; then
    echo "File not found: $filename"
    exit 1
fi

# Compile the file
g++ "$filename" -o "${filename%.*}.out"
if [ -f "${filename%.*}.out" ]; then
    echo
    echo "PS AbhinavPokhariyal\\2218152\\B2\\01> ./a.out"
    ./"${filename%.*}.out"
    echo
    echo "PS AbhinavPokhariyal\\2218152\\B2\\01> "
    # Remove the executable
    rm -f "${filename%.*}.out"
    # Wait for enter key to be pressed
    read -p ""
fi
