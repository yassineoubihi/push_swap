import itertools
import subprocess

numbers = ["1", "2", "3", "4", "5"]

# Initialize max and min counters
max_lines = float('-inf')
min_lines = float('inf')

# Generate all combinations
combinations = list(itertools.permutations(numbers))

# Loop through combinations and pass them to pushswap
for combination in combinations:
    args = ["./pushswap"] + list(combination)

    print("Running pushswap with combination: {}".format(combination))
    
    try:
        # Use check_output to capture the output
        output = subprocess.check_output(args, universal_newlines=True)
        
        # Count the number of lines in the output
        num_lines = len(output.splitlines())
        
        print("Number of instructions is: {}".format(num_lines))
        
        # Update max and min counters
        max_lines = max(max_lines, num_lines)
        min_lines = min(min_lines, num_lines)
        
        # Check if the number of lines is more than 12
        if num_lines > 12:
            print("Error: Too many instructions (more than 12).")
        
    except subprocess.CalledProcessError as e:
        print("Error running pushswap: {}".format(e))

# Print the max and min number of lines after all iterations
print("Max number of instructions: {}".format(max_lines))
print("Min number of instructions: {}".format(min_lines))
