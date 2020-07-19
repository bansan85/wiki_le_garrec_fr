#!/bin/sh

if [ "$(clang-format -style=file "$1" -output-replacements-xml |grep -c "<replacement offset=")" -ne "0" ]; then
  if [ "$CI" = "true" ] && [ "$TRAVIS" = "true" ]
  then
    clang-format -style=file "$1" | diff -pu "$1" -
    exit 1
  else
    clang-format -style=file -i "$1"
    exit 0
  fi
fi
exit 0
