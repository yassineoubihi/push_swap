from itertools import permutations

numbers = [1, 2, 3, 4, 5]

# Generate all permutations using itertools.permutations
combinations = permutations(numbers)

# Print all combinations
for combo in combinations:
    print(' '.join(map(str, combo)))
