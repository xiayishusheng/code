<?php											
	session_start();								
	$_SESSION['name']="����";						
	$_SESSION['math']="85";						
	$_SESSION['chinese']="96";						
	$sessionID= session_id();						
	echo "ID=$sessionID<P> ";						
?>												

<html>											
	<title>����Session</title>						
	<body>										
<?php											
	echo "<B>ѧ����Ϣ</B> <P>";						
	echo "name= ".$_SESSION['name']."<BR>";			
	echo "math= ".$_SESSION['math']."<BR>";			
	echo "chinese= ".$_SESSION['chinese']."<P>";	
	echo "<B>ƽ���ɼ�</B><P>";						
	echo "average=";								
	echo ($_SESSION['math']+$_SESSION['chinese'])/2;
?>												
</BODY>											
</HTML>											
