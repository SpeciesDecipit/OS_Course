#!/usr/bin/env bash
sysctl -a | grep machdep.cpu | ./tee -a ex2.txt