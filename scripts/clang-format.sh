#!/bin/bash

SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
cd $SCRIPT_DIR/..

FILES="$(find src/ -name *.cpp -o -name *.hpp) $(find tests/ -name *.cpp -o -name *.hpp)"

if [[ $1 == "--check" ]]; then
  clang-format --dry-run -Werror $FILES
else
  clang-format -i $FILES
fi
