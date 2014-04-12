<html>
<title>修改留言</title>
<body>
<h2><center>留言修改</center></h2>
<?
 session_start();
 if($_SESSION['admin']=="OK")
 {
  $conn=mysql_connect ("localhost", "root", "123456");
 mysql_query("set names GB2312"); //解决中文乱码问题 
  mysql_select_db("guest_book");

  $exec="select * from contents where id=".$_GET['id'];  /*这里这个$_GET['id']就是取得从那个连接传递过来的参数拉 */
  $result=mysql_query($exec);
  $rs=mysql_fetch_object($result);
  $name=$rs->name;
  $content=$rs->content;
  $id=$rs->id;
 ?>

  <form action="modify2.php" method="post" name="name1">
    I D  : <?=$id?><input type=hidden name=id value=<?=$id?> > <br>
    姓名: <?=$name?><br> 
    留言: <textarea name="post_contents" rows="10" cols="50"><?=$content?></textarea> 
    <input type="submit" value="提交修改"> 
   </form>
 <?
  }
mysql_close();
?>
</body>
</html>
