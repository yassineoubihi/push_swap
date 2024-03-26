import itertools
import subprocess

# Function to run push_swap executable with a given combination
def run_push_swap(combination):
    push_swap_command = ['./push_swap'] + [str(num) for num in combination]
    checker_command = ['./checker_Mac'] + [str(num) for num in combination]
    
    push_swap_process = subprocess.Popen(push_swap_command, stdout=subprocess.PIPE)
    checker_process = subprocess.Popen(checker_command, stdin=push_swap_process.stdout, stdout=subprocess.PIPE)
    
    push_swap_process.stdout.close()
    
    output = checker_process.communicate()[0].decode()
    
    print(output)

# Generate all combinations of 1, 2, 3, 4, 5
numbers = [1, 2, 3, 4, 5]
combinations = itertools.permutations(numbers)

# Run push_swap and checker for each combination
for combination in combinations:
    run_push_swap(combination)
