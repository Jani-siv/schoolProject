#!/bin/bash
TESTS=$(find . -name *"Tests")
for i in ${TESTS[@]}; do
  $i
  if [ $? != "0" ]; then
    exit 1
  fi
done
