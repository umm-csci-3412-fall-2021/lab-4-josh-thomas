#!/bin/bash

variable=($(find $1 -maxdepth 16 -type d -print | wc -l | xargs))

variable2=($(find $1 -maxdepth 16 -type f -print | wc -l | xargs))

echo "There were "$variable" directories."
echo "There were "$variable2" regular files."