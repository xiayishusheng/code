#!/bin/bash
export LANG=en_US
#ifconfig $1 | sed -n '0,/^\s\+inet addr:\([0-9]\+[.][0-9]\+[.][0-9]\+[.][0-9]\+\).*$/s//\1/p'
ifconfig $1 | sed -e '/.*inet addr:/!d;s///;s/ .*//'
