<html>
<title>�޸�����</title>
<body>
<h2><center>�����޸�</center></h2>
<?
 session_start();
 if($_SESSION['admin']=="OK")
 {
  $conn=mysql_connect ("localhost", "root", "123456");
 mysql_query("set names GB2312"); //��������������� 
  mysql_select_db("guest_book");

  $exec="select * from contents where id=".$_GET['id'];  /*�������$_GET['id']����ȡ�ô��Ǹ����Ӵ��ݹ����Ĳ����� */
  $result=mysql_query($exec);
  $rs=mysql_fetch_object($result);
  $name=$rs->name;
  $content=$rs->content;
  $id=$rs->id;
 ?>

  <form action="modify2.php" method="post" name="name1">
    I D  : <?=$id?><input type=hidden name=id value=<?=$id?> > <br>
    ����: <?=$name?><br> 
    ����: <textarea name="post_contents" rows="10" cols="50"><?=$content?></textarea> 
    <input type="submit" value="�ύ�޸�"> 
   </form>
 <?
  }
mysql_close();
?>
</body>
</html>
