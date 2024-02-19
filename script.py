import itertools
import subprocess

numbers = ["1", "2", "3", "4", "5"]

# Generate all combinations
combinations = list(itertools.permutations(numbers))

# Loop through combinations and pass them to pushswap
for combination in combinations:
    args = ["./pushswap"] + list(combination)
    command = " ".join(args)

    print("Running pushswap with combination: {}".format(combination))
    
    try:
        subprocess.call(args)
    except subprocess.CalledProcessError as e:
        print("Error running pushswap: {}".format(e))
