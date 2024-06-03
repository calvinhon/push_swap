#!/bin/bash


generate_random_numbers() {
    echo $(shuf -i 0-2000000 -n $1 | awk '{print $1 - 1000000}')
}

# Loop to run push_swap with valgrind for different numbers of random integers
for ((i = 1; i <= 500; i++)); do
    random_numbers=$(generate_random_numbers $i)
    echo "Running push_swap with $i random numbers: $random_numbers"
    valgrind_output=$(valgrind ./push_swap $random_numbers 2>&1)  # Redirect stderr to stdout
    echo "$valgrind_output"  # Print Valgrind output

    # Check if Valgrind output contains any indication of memory leaks or segmentation fault
    if echo "$valgrind_output" | grep -qi 'definitely lost\|indirectly lost\|Segmentation fault'; then
        if echo "$valgrind_output" | grep -qi 'Segmentation fault'; then
            echo "Segmentation fault detected. Stopping the testing."
        else
            echo "Memory leaks detected. Stopping the testing."
        fi
        break
    fi
done