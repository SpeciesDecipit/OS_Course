#!/usr/bin/env bash
if test ! -f seq_of_numbers
then
    echo 0 > seq_of_numbers
fi

for i in `seq 1 10`;
do
	LAST_NUMBER=`tail -1 seq_of_numbers`
	LAST_NUMBER=$((LAST_NUMBER+1))

	echo $LAST_NUMBER >> seq_of_numbers
done