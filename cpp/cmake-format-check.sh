#!/bin/sh

echo "Checking format $1"

if ! cmake-format "$1" --check;
then
  cmake-format "$1" | diff -pu "$1" -
  exit 1
else
  touch "$1.stamp"
  exit 0
fi
