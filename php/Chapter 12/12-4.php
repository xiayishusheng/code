<?php										
	session_start();							
	$_SESSION['count']=2008;					
	$_SESSION['user']="Hello ";				
?>											
<html>										
	<title>����Session</title>					
	<body>									
<?php										
	echo "����ǰ <br>";						
	echo "count= ".$_SESSION['count']."<BR>";	
	echo "user= ".$_SESSION['user']."<P>";		
	$_SESSION['count']++;						
	$_SESSION['user'].="My friend.";			
	echo "���ʺ�<br>";							
	echo "count= ".$_SESSION['count']."<BR>";	
	echo "user= ".$_SESSION['user']."<BR>";		
?>											
</BODY>										
</HTML>										
