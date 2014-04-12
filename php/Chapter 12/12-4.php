<?php										
	session_start();							
	$_SESSION['count']=2008;					
	$_SESSION['user']="Hello ";				
?>											
<html>										
	<title>调用Session</title>					
	<body>									
<?php										
	echo "访问前 <br>";						
	echo "count= ".$_SESSION['count']."<BR>";	
	echo "user= ".$_SESSION['user']."<P>";		
	$_SESSION['count']++;						
	$_SESSION['user'].="My friend.";			
	echo "访问后<br>";							
	echo "count= ".$_SESSION['count']."<BR>";	
	echo "user= ".$_SESSION['user']."<BR>";		
?>											
</BODY>										
</HTML>										
