#!/bin/bash

# Compile each .c file into an object file
gcc -c *.c

# Create the static library liball.a from the object files
ar -rc liball.a *.o

# Clean up by removing the object files
rm *.o

