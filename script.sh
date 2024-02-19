#!/bin/bash

numbers=("1" "2" "3" "4" "5")

# Function to generate all combinations
generate_combinations() {
    local prefix="$1"
    shift

    if [ "$#" -eq 0 ]; then
        echo "$prefix"
    else
        for element in "$@"; do
            generate_combinations "$prefix $element" "${@//$element/}"
        done
    fi
}

# Get all combinations
combinations=($(generate_combinations "" "${numbers[@]}"))

# Loop through combinations and pass them to pushswap
for combination in "${combinations[@]}"; do
    echo "Running pushswap with combination: $combination"
    ./pushswap $combination
done