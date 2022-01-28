#!/bin/bash
#Yiwei He yh9vhg 10/27/2021 averagetime.sh
num=1
echo "enter the exponent for counter.cpp:"
read exp
if [ $exp == "quit" ]
then
    exit 0
fi
while [ $num -lt 6 ];
do
    echo "Running iteration ${num}:"
    timing=`./a.out ${exp}`
    total=$(($total + $timing))
    echo  "time taken: ${timing} ms"
    let num=num+1
done
echo "5 iterations took ${total} ms"
averagetime=$((total/5))
echo "Average time: ${averagetime} ms" 