#!/usr/bin/env bash
touch file.txt >> ex2.txt
link file.txt _ex2.txt >> ex2.txt
find -inum "$(ls -i file.txt | awk '{print $1;}')" >> ex2.txt
find -inum "$(ls -i file.txt | awk '{print $1;}')" -exec rm {} \; >> ex2.txt
