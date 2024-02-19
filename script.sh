#!/bin/bash

# Get all permutations of the numbers
permutations=$(echo {1..5} | tr ' ' '\n' | permutations)

# Loop through each permutation
for permutation in $permutations; do
  # Separate numbers and build argument string
  args=($permutation)
  argument_string="${args[0]}"
  for ((i=1; i<${#args[@]}; i++)); do
    argument_string="$argument_string ${args[$i]}"
  done

  # Run pushswap with the current permutation
  ./pushswap $argument_string &

  # Wait for pushswap to finish before next iteration
  wait
done

echo "Finished generating all combinations."
