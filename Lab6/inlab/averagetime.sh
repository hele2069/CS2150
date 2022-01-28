#!/bin/bash
#Yiwei He yh9vhg 10/19/2021 averagetime.sh

read dict grid
RUNNING_TIME_1=`./a.out $dict $grid | tail -1`
RUNNING_TIME_2=`./a.out $dict $grid | tail -1`
RUNNING_TIME_3=`./a.out $dict $grid | tail -1`
RUNNING_TIME_4=`./a.out $dict $grid | tail -1`
RUNNING_TIME_5=`./a.out $dict $grid | tail -1`
echo $(((RUNNING_TIME_1+RUNNING_TIME_2+RUNNING_TIME_3+RUNNING_TIME_4+RUNNING_TIME_5)/5))