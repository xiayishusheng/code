<?php											
	Session_start();								
	$_SESSION['name']="PHP�����̳�";				
	$_SESSION['passwd']="php";						
	$_SESSION['time']=time();						
	echo '<a href="session.php" >ͨ��COOKIE����SESSION</a>';				
												
	echo '<p ><a href="session.php?' . SID . '">ͨ��URL����SESSION</a>'
												
?>												
