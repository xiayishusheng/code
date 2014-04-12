<?php											
	session_start();								
	$_SESSION['name']="王军";						
	$_SESSION['math']="85";						
	$_SESSION['chinese']="96";						
	$sessionID= session_id();						
	echo "ID=$sessionID<P> ";						
?>												

<html>											
	<title>调用Session</title>						
	<body>										
<?php											
	echo "<B>学生信息</B> <P>";						
	echo "name= ".$_SESSION['name']."<BR>";			
	echo "math= ".$_SESSION['math']."<BR>";			
	echo "chinese= ".$_SESSION['chinese']."<P>";	
	echo "<B>平均成绩</B><P>";						
	echo "average=";								
	echo ($_SESSION['math']+$_SESSION['chinese'])/2;
?>												
</BODY>											
</HTML>											
