 <html> 
<head> 
<meta http-equiv="Content-Type" content="text/html; charset=gb2312"> 
<title>���Ա�</title> 
</head> 
 <body>
<div align="right"><a href="admin_login.htm" tagert="_blank" >
<font size="+1" face="����" >���԰���� </font></a> 
</div>
<div align="center"><font face="����"><h2>PHPѧϰ�������԰� </h2></font>
</div>   
   <? 
     $conn=mysql_connect ("localhost", "root", "123456"); //��MySQL���������� 
     mysql_select_db("guest_book"); //�������ݿ� 
     mysql_query("set names GB2312"); //��������������� 

	$pageSize = 2;
	$pageNumber = $_GET[ 'pageNumber' ];
	if( $pageNumber == null )$pageNumber = 1;
	$rs = mysql_fetch_row( mysql_query("select count(*) from contents") );
	$totalCount = $rs[ 0 ];

     $exec="select * from contents limit " . ( ( $pageNumber - 1 ) * $pageSize ) . ", 2" ; //sql��� 

     $result=mysql_query($exec); //ִ��sql��䣬���ؽ�� 
     while($rs=mysql_fetch_object($result))  
    { 
      echo "<table><tr><td>����:".$rs->name."</td></tr>"; 
      echo "<tr><td>����:".$rs->content."</td></tr></table><br/>";
      echo "............................................................................................................................."; 
      echo "<br />";
    }
    if( $pageNumber > 1 )
    {
    	echo "<a href=index.php?pageNumber=" . ( $pageNumber - 1 ) . ">ǰһҳ&nbsp&nbsp</a>";
	}else{
   	echo "ǰһҳ&nbsp&nbsp";
}
	    if( $pageNumber < $totalCount / $pageSize )
    {
    	echo "<a href=index.php?pageNumber=" . ( $pageNumber + 1 ) . ">��һҳ</a>";
	}else
	{
		echo "�� һҳ";

	}
       mysql_close();
 ?>
 
 <div align="CENTER"><a href="message_post.html" tagert="_blank" >
<font size="+2" face="����" ><p> ��Ҫ���� </font></a> 
</div>
</body>
</html>
