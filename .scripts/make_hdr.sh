#!/bin/bash

cd $2
find $3/ -regex ".*\.\(h\|hpp\|hxx\|H\|h++\|hh\)" ! -name "$1" -fprintf hpp.tmp "#include \"%p\"\n"
uc_name=$(echo $3 | tr [:lower:] [:upper:])
printf "#ifndef %s_TOP_INC\n" $uc_name > $1
printf "#define %s_TOP_INC\n" $uc_name >> $1
cat hpp.tmp >> $1
printf "#endif //%s_TOP_INC" $uc_name >> $1
rm hpp.tmp
