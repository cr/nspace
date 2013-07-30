#/bin/sh
dim=${1:-3}
hexdump -v -d \
  | sed -e 's/^[^ ]* *//g' \
  | grep -v 00000.*00000.*00000.*00000 \
  | $(dirname $0)/nspace -b 10 -d $dim -w 65536

