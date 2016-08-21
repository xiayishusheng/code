#!/bin/bash

#----------------------------------------
str1="a b c d e"
array1=($str1)
length1=${#array1[@]}
echo 数组1的长度=${length1}

for((i=0;i<${length1};i++))
do
    echo ${array1[$i]}
done;

#----------------------------------------
str2="A#B#C#D#E"
array2=($(echo $str2 | tr '#' ' ' | tr -s ' '))
length2=${#array2[@]}
echo 数组2的长度=${length2}

for((i=0;i<${length2};i++))
do
    echo ${array2[$i]}
done;
