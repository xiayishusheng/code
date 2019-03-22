# 预处理阶段，生成中间文件
gcc -E chengfa.c -o chengfa.i
# 编译阶段，生成汇编文件
gcc -S chengfa.i -o chengfa.s
# 汇编阶段，生成二进制机器码
gcc -c chengfa.s -o chengfa.o
# 链接阶段，二进制文件
gcc chengfa.o -o chengfa

# 以上过程可简化为：
## gcc chengfa.c -o chengfa

# rm chengfa chengfa.i chengfa.s chengfa.o
