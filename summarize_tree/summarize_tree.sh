#!/bin/bash

# finds all directories and counts them
variable=($(find $1 -maxdepth 16 -type d -print | wc -l | xargs))

# finds all files and counts them
variable2=($(find $1 -maxdepth 16 -type f -print | wc -l | xargs))

echo "There were "$variable" directories."
echo "There were "$variable2" regular files."