#!/bin/bash

hexdump -v -d \
  | sed -e 's/^[^ ]* *//g ; s/  */_/g' \
  | tr _ \\012 \
  | grep -v '^$'
