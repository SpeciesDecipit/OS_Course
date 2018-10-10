#!/usr/bin/env bash
cc ex2.c && ./a.out &
iostat 1 > ex2.txt