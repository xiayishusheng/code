#!/bin/bash
help () {
        echo "用法: $0 -w <WARNING阀值,单位:秒> -c <CRITICAL阀值,单位:秒>"
        exit 2
}
while getopts "w:c:h" OPT
do
        case $OPT in
        "w") warning=$OPTARG;;
        "c") critical=$OPTARG;;
        "h") help;;
        esac
done

#delay_time1=`pt-heartbeat -D test --check -u repl -p 'repl123$' -P 3306 -h 10.1.18.50 --master-server-id=1`
#delay_time2=`pt-heartbeat -D test --check -u repl -p 'repl123$' -P 3306 -h 10.1.18.50 --master-server-id=2`
#delay_time3=`pt-heartbeat -D test --check -u repl -p 'repl123$' -P 3306 -h 10.1.18.50 --master-server-id=3`
delay_time1=`echo 20.00`
delay_time2=`echo 0.00`
delay_time3=`echo 10.00`


func(){
jd=$1
case $jd in
"delay_time1")
jd_name="aa1";;
"delay_time2")
jd_name="bb2";;
"delay_time3")
jd_name="cc3";;
esac
if [ $(echo "$jd >= ${critical}"|bc) = 1 ] ; then
msg="CRITICAL"
status=2
elif [ $(echo "$jd >= ${warning}"|bc) = 1 ] ; then
msg="WARNING"
status=1
else
msg="OK"
status=0
fi
echo "$jd_name延时$jd状态$msg"
exit $status
}

jd1_OUT=$(func $delay_time1)
jd2_OUT=$(func $delay_time2)
jd3_OUT=$(func $delay_time3)
wait
echo "${jd1_OUT},${jd2_OUT},${jd3_OUT}."
exit $status

exit
