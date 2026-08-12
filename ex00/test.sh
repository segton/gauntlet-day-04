#!/bin/bash

# 1. Compile the project first using your Makefile
echo "Compiling project..."
make re

# 2. Check if the compilation succeeded
if [ ! -f "./roster" ]; then
    echo "Compilation failed! Exiting test."
    exit 1
fi

# 3. Run Valgrind with strict leak checking
echo -e "\nRunning Valgrind memory analysis...\n"

valgrind \
    --leak-check=full \
    --show-leak-kinds=all \
    --track-origins=yes \
    ./roster

# 4. Grab Valgrind's exit status
VALGRIND_STATUS=$?

echo -e "\n------------------------------------"
if [ $VALGRIND_STATUS -eq 0 ]; then
    echo "Test completed! Check the logs above for any leaks."
else
    echo "⚠️ Valgrind detected an issue (Exit Code: $VALGRIND_STATUS)"
fi

