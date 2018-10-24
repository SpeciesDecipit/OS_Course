#!/usr/bin/env bash
touch _ex3.txt
touch ex3.txt
chmod -x _ex3.txt
ls -l _ex3.txt >> ex3.txt
chmod u+w+r+x _ex3.txt
chmod o+w+r+x _ex3.txt
ls -l _ex3.txt >> ex3.txt
chmod 660 _ex3.txt
ls -l _ex3.txt >> ex3.txt
chmod 775 _ex3.txt
ls -l _ex3.txt >> ex3.txt
chmod 777 _ex3.txt
ls -l _ex3.txt >> ex3.txt