#!/bin/bash

FILES="build/bin/*"
for file in $FILES_SEQ; do
    echo "--------------------------------"
    echo $(basename $file)
    echo "--------------------------------"
    ./$file --gtest_repeat=10
done

