<html>
<title>��̨����</title>
<body>
<center><h2>��̨����ҳ��</h2></center>
<?
session_start();
if($_SESSION['admin']=="OK")
 {
  $conn=mysql_connect ("localhost", "root", "123456");
  mysql_query("set names GB2312"); //��������������� 
  mysql_select_db("guest_book");
  $exec="select * from contents";
  $result=mysql_query($exec);
  while($rs=mysql_fetch_object($result))
     {
      echo "<table><tr><td>����:".$rs->name."</td></tr>"; 
      echo "<tr><td>����:".$rs->content."</td></tr></table><br/>";
      echo "<a href=modify.php?id=".$rs->id." >�޸�</a>      <a href=delete.php?id=".$rs->id." >ɾ��</a>";
      echo "<br><br>";
      }
 echo "<br><a href=index.php ><center>����ҳ</center></a>";
 }

   mysql_close();
?>
</body>
</html>