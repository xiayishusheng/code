<?php                                                         
/* 步骤一：设置初始变量 */
$host="127.0.0.1";    
$user="root";    
$password="root";
/* 步骤二：连接MySQL服务器 */
$conn=mysql_connect($host,$user,$password);    
//步骤三：判断连接结果
if (!$conn){
    die ("连接数据库失败 ".mysql_error());    

}   
else{
    echo  "MySQL服务器: $host <br> 用户名称：$user  <br>";
    echo  "成功连接数据库。";    

}   
?>

