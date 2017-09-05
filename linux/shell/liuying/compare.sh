#!/bin/bash

function max_num()
{
    echo  $*;
    local max;
    if [ $1 -eq $2 ];then
        echo $1 is bigger than $2;
        max=$1;
    else
        echo $1 is smaller than $2;
        max=$2;
    fi
    return $max
}

if [ $(echo "4>2" | bc) -eq 1 ];then
    echo ===
fi
