<?php											
	Session_start();								
	$_SESSION['name']="PHP基础教程";				
	$_SESSION['passwd']="php";						
	$_SESSION['time']=time();						
	echo '<a href="session.php" >通过COOKIE传递SESSION</a>';				
												
	echo '<p ><a href="session.php?' . SID . '">通过URL传递SESSION</a>'
												
?>												
