@echo off
rem 批处理中有两个环境变量可以跟当前路径有关，一个是%cd%, 一个是%~dp0

rem 1. %cd% 可以用在批处理文件中，也可以用在命令行中；
rem 展开后，是驱动器盘符:+当前目录，如在dos窗口中进入c:\dir目录下面
rem 输入：echo %cd% ，则显示为：c:\dir
rem %cd%的内容是可以被改变的，其内容为命令的执行路径或批处理文件的执行路径

rem 2.%~dp0只能用在批处理文件中，它是由它所在的批处理文件的目录位置决定的，是批处理文件所在的盘符:+路径
rem 在执行这个批处理文件的过程中，它展开后的内容是不可以改变的
rem 比如在D盘下有个批处理文件，d:\path.bat，其内容为：

echo this is %%cd%% %cd%
echo this is %%~dp0 %~dp0

rem 在c:\下执行后的结果为
rem this is %cd%  c:\
rem this is %~dp0 d:\

pause