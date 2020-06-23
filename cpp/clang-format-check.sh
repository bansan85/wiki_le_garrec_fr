if [ $(clang-format -style=file $1 -output-replacements-xml |grep "<replacement offset=" | wc -l) -ne "0" ]; then clang-format -style=file $1 | diff -pu $1 - ; exit 1; fi
