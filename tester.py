import itertools
import subprocess
import sys
import os
import random

# Function to run push_swap executable with a given combination
def run_push_swap(combination):
    push_swap_command = ['./push_swap'] + [str(num) for num in combination]
    checker_command = ['./checker_Mac'] + [str(num) for num in combination]
    
    push_swap_process = subprocess.Popen(push_swap_command, stdout=subprocess.PIPE)
    checker_process = subprocess.Popen(checker_command, stdin=push_swap_process.stdout, stdout=subprocess.PIPE)
    
    push_swap_process.stdout.close()
    
    output = checker_process.communicate()[0].decode()
    
    print(f"Combination: {' '.join(str(num) for num in combination)}")
    print("Output:")
    print(output)

if __name__ == "__main__":
    # Check if push_swap executable exists
    if not os.path.exists('./push_swap'):
        print("Error: No push_swap executable found")
        sys.exit(1)
    
    # Check if checker_Mac executable exists
    if not os.path.exists('./checker_Mac'):
        print("Error: No checker_Mac executable found")
        sys.exit(1)

    # Check if checker_Mac has execute permission
    if not os.access('./checker_Mac', os.X_OK):
        print("Error: Need Execute permission for checker_Mac")
        sys.exit(1)

    if len(sys.argv) != 3:
        print("Usage: python tester.py <number_of_digits> <number_of_tests>")
        sys.exit(1)

    try:
        num_digits = int(sys.argv[1])
        num_tests = int(sys.argv[2])
        
        if num_digits not in [3, 4, 5, 100, 200, 300, 500]:
            print("Error: Number of digits must be 3, 4, 5, 100, 200, 300, or 500")
            sys.exit(1)

        # Define logical limits for different number of digits
        logical_limits = {
            3: 6,
            4: 24,
            5: 120,
            100: 1000,
            200: 1000,
            300: 1000,
            500: 1000,
            # Add other limits as needed
        }
        
        if num_tests > logical_limits.get(num_digits, 0):
            print(f"Error: Number of tests exceeds the logical limit for {num_digits} digits, can't generate more than {logical_limits.get(num_digits)} tests")
            sys.exit(1)
            
    except ValueError:
        print("Error: Number of digits and number of tests must be integers")
        sys.exit(1)

    # Generate combinations
    if num_digits == 100 or num_digits == 200 or num_digits == 300 or num_digits == 500:
        numbers = list(range(1, num_digits + 1))
        combinations = [random.sample(numbers, num_digits) for _ in range(num_tests)]
    else:
        numbers = list(range(1, num_digits + 1))
        combinations = itertools.permutations(numbers)

    # Run push_swap and checker for each combination
    for combination in combinations:
        run_push_swap(combination)
