#!/bin/bash

#使用方法
function usage()
{
    echo -e "usage:"
    echo -e "\t`basename $0` key_word1 key_word2 work_dir replace_str"
    echo -e "for example:"
    echo -e "\t`basename $0` word1 word2 /tmp/code \"this is replaced string!\""
}

#替换包含指定字符串的行内容
function replace_strings()
{
    key_word1="$1"
    key_word2="$2"
    work_dir="$3"
    replace_str="$4"

    #整词匹配
    files=(`grep -rn "\<${key_word1}\>" ${work_dir} | grep "\<${key_word2}\>" | cut -d ":" -f 1`)
    lines=(`grep -rn "\<${key_word1}\>" ${work_dir} | grep "\<${key_word2}\>" | cut -d ":" -f 2`)
    infos=(`grep -rn "\<${key_word1}\>" ${work_dir} | grep "\<${key_word2}\>"`)

    length=${#files[@]};echo "length=${length}"

    echo "------------------------------"

    for((i=0;i<${length};i++))
    do
        #echo files[$i]=${files[$i]};
        echo ""${infos[$i]}" ---> ${replace_str}";
        sed -n ''${lines[$i]}'c\'"${replace_str}"'' ${files[$i]}
        #echo sed -n ''${lines[$i]}'c\'"${replace_str}"'' ${files[$i]}
    done;
}

if [ $# -ne 4 ];then
    usage
    exit;
else
    replace_strings "$1" "$2" "$3" "$4"
fi
