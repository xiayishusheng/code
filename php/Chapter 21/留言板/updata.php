<? 
  $name=$_POST['user']; 									
  $content=$_POST['post_contents']; 							
  $conn=mysql_connect("localhost", "root", "123456"); 				
   mysql_query("set names GB2312"); 							
   mysql_select_db("guest_book"); 								
  $exec="insert into contents (name,content) values ('".$_POST['user']."','".$_POST['post_contents']."')"; 
   $result=mysql_query($exec);								
if( $result>0)												
echo "������Գɹ���лл������ԣ�"  ;							
else 
echo "�������ʧ��";										
 echo "<p><a href=index.php ><center>������ҳ��</center></a>";		
   mysql_close(); 											
?>

<html><head><meta http-equiv='Refresh' content='3; URL=index.php'></head>
<body><p>лл���Ա�վ��֧�֣�������Զ����ء���</p></body></html>