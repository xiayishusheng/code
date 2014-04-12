<?
 session_start();
 if($_SESSION['admin']=="OK")
 {
  $conn=mysql_connect ("localhost", "root", "123456");
  mysql_select_db("guest_book");
  $exec="delete from contents where id=".$_GET['id'];
  mysql_query($exec);
  mysql_close();
 }
 header("location:admin_index.php")
?>
