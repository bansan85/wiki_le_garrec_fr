$(cmake-format $1 | diff $1 -)
if [ $? -ne "0" ]; then cmake-format $1 | diff -pu $1 - ; exit 1; fi
