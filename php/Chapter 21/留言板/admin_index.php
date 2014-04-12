<html>
<title>后台管理</title>
<body>
<center><h2>后台管理页面</h2></center>
<?
session_start();
if($_SESSION['admin']=="OK")
 {
  $conn=mysql_connect ("localhost", "root", "123456");
  mysql_query("set names GB2312"); //解决中文乱码问题 
  mysql_select_db("guest_book");
  $exec="select * from contents";
  $result=mysql_query($exec);
  while($rs=mysql_fetch_object($result))
     {
      echo "<table><tr><td>姓名:".$rs->name."</td></tr>"; 
      echo "<tr><td>留言:".$rs->content."</td></tr></table><br/>";
      echo "<a href=modify.php?id=".$rs->id." >修改</a>      <a href=delete.php?id=".$rs->id." >删除</a>";
      echo "<br><br>";
      }
 echo "<br><a href=index.php ><center>回首页</center></a>";
 }

   mysql_close();
?>
</body>
</html>