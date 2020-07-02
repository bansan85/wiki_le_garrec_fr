#!/bin/sh

echo "Checking format $1"
$(cmake-format $1 --check)
if [ $? -ne "0" ]
then
  cmake-format $1 | diff -pu $1 -
  exit 1
else
  touch $1.stamp
  exit 0
fi
