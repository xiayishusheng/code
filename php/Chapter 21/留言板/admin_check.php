<? 
  session_start();
  $admin_name=$_POST['admin_name'];
  $admin_password=$_POST['admin_password'];
  $conn=mysql_connect ("localhost", "root", "123456");
  mysql_select_db("guest_book");
  $exec="select * from admin where admin_name='".$admin_name."'";
  $result=mysql_query($exec);
   if ($rs=mysql_fetch_object($result))
    { if ($rs->admin_password==$admin_password)
       {$_SESSION['admin']="OK";
        header("location:admin_index.php");
        }
      else echo "密码不正确";
    }
   else echo "用户名不正确";
   
   mysql_close();
?>
