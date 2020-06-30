#!/bin/bash
# Need bash for shopt

travis login --pro --github-token $GITHUB_PERSONAL_TOKEN || exit 1

shopt -s globstar dotglob
for i in **/*.yml; do
  echo $i
  travis lint --pro "$i" -x --no-interactive || exit 1
done

exit 0
