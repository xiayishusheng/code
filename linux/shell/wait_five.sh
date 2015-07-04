#!/bin/bash

#当前路径
CURRENT_DIR=`pwd`
#要执行的程序
PROGRAM=my_exe
#执行次数
COUNTS=0

#获取所有进程号
pids=(`ps -ef | grep -v grep | grep $0 | awk '{print $2}'`)

#遍历所有进程号
for i in ${pids[*]};
do
    if [ $i -ne $$  ];then
        #杀掉非当前进程
        kill -9 $i
        killall -9 $PROGRAM
    fi
done

#开始时间，自UTC 时间 1970-01-01 00:00:00 以来所经过的秒数
time_begin=`date +%s`
echo 开始时间=$time_begin

while true
do
    #当前时间，自UTC 时间 1970-01-01 00:00:00 以来所经过的秒数
    time_current=`date +%s`
    #当前时间-开始时间（换算为分钟）
    time_diff=$[$time_current/60-$time_begin/60]

    #超过一分钟，停止
    if [ $time_diff -gt 0 ];then
        killall -9 $PROGRAM
        exit 0;
    fi

    let COUNTS=$COUNTS+1
    echo "当前时间=$time_current, 时间差=$time_diff(以分钟为单位)"
    echo -e "=======================================================第$COUNTS次准备打印乘法口诀============================================================"
    ${CURRENT_DIR}/${PROGRAM}
    echo -e "\n"
done
