#!/bin/sh

retval=0

mkdir buildcppgcc
cd buildcppgcc || exit 1
CC=/usr/bin/gcc-10 CXX=/usr/bin/g++-10 CXXFLAGS="-Wall -Werror -Wextra -Wpedantic -fanalyzer -O2 -P" cmake ../cpp || { retval=1 && echo "Failure retval"; }
make || { retval=1 && echo "Failure retval"; }
if [ "$CI" = "true" ] && [ "$TRAVIS" = "true" ]
then
  git clone ssh://git@github.com/bansan85/wiki_le_garrec_fr_travis.git || { retval=1 && echo "Failure retval"; }
else
  mkdir -p wiki_le_garrec_fr_travis
fi
make data_for_travis || { retval=1 && echo "Failure retval"; }
iwyu_tool -p . -- -Xiwyu --mapping_file="$(pwd)/../cpp/iwyu.imp" > iwyu_tool.log
if [ "$(grep -c -e "should add these lines" -e "should remove these lines" < iwyu_tool.log)" -ne "0" ]
then
  cat iwyu_tool.log
  retval=1
  echo "Failure retval"
fi
cd .. || exit 1

mkdir buildcppclang;
cd buildcppclang || exit 1
CC=/usr/bin/clang-10 CXX=/usr/bin/clang++-10 CXXFLAGS="-isystem /usr/lib/llvm-10/lib/clang/10.0.0/include -Weverything -Werror -O2 -Wno-c++98-compat -Wno-padded -Wno-c++98-compat-pedantic" cmake ../cpp || { retval=1 && echo "Failure retval"; }
make || { retval=1 && echo "Failure retval"; }
python3 /usr/lib/llvm-*/share/clang/run-clang-tidy.py || { retval=1 && echo "Failure retval"; }
make clean; scan-build -v -v -v -o . make || { retval=1 && echo "Failure retval"; }
cppcheck --inconclusive --enable=all --project=compile_commands.json --error-exitcode=1 --inline-suppr --template="{file},{line},{severity},{id},{message}" --suppressions-list=../cpp/cppcheck-suppressions.txt || { retval=1 && echo "Failure retval"; }
iwyu_tool -p . -- -Xiwyu --mapping_file=/home/travis/build/bansan85/wiki_le_garrec_fr/cpp/iwyu.imp > iwyu_tool.log
if [ "$(grep -c -e "should add these lines" -e "should remove these lines" < iwyu_tool.log)" -ne "0" ]
then
  cat iwyu_tool.log
  retval=1
  echo "Failure retval"
fi
cd .. || exit 1

if [ $retval -eq 0 ] && [ "$CI" = "true" ] && [ "$TRAVIS" = "true" ]
then
  cd buildcppgcc || exit 1
  cd wiki_le_garrec_fr_travis || exit 1
  git config --global user.name "Travis"
  git config --global user.email "travis-ci@le-garrec.fr"
  git add .
  if [ -n "$(git diff-index --name-only HEAD --)" ]
  then
    git commit -m "$TRAVIS_COMMIT_MESSAGE" -m "Update from $TRAVIS_COMMIT"
    git push
  fi
  cd ../.. || exit 1
fi

exit $retval
