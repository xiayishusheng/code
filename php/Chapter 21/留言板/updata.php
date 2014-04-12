<? 
  $name=$_POST['user']; 									
  $content=$_POST['post_contents']; 							
  $conn=mysql_connect("localhost", "root", "123456"); 				
   mysql_query("set names GB2312"); 							
   mysql_select_db("guest_book"); 								
  $exec="insert into contents (name,content) values ('".$_POST['user']."','".$_POST['post_contents']."')"; 
   $result=mysql_query($exec);								
if( $result>0)												
echo "添加留言成功，谢谢你的留言！"  ;							
else 
echo "添加留言失败";										
 echo "<p><a href=index.php ><center>返回主页面</center></a>";		
   mysql_close(); 											
?>

<html><head><meta http-equiv='Refresh' content='3; URL=index.php'></head>
<body><p>谢谢您对本站的支持，三秒后将自动返回……</p></body></html>