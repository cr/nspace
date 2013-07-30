#/bin/sh
dim=${1:-3}
hexdump -v -d | sed -e 's/^[^ ]* *//g' | $(dirname $0)/nspace -b 10 -d $dim

