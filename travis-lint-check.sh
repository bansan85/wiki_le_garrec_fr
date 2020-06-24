#!/bin/bash
# Need bash for shopt

shopt -s globstar dotglob
for i in **/*.yml; do
  echo $i
  travis lint "$i" -x --no-interactive || exit 1
done

exit 0
