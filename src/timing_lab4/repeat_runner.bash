#!/bin/bash

# Define the output file
output_file="output.txt"

# Clear the output file if it already exists
> "$output_file"

# Loop 1000 times
for i in {1..1000}; do
  # Run the program and append its output to the file
  ./test_gradient ackermann_function_optimized.png asd.png 1 >> "$output_file"
done

echo "Program ran 1000 times and output was appended to $output_file"
