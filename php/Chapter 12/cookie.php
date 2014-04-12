<html>											
	<head>										
		<title>COOKIE 实现用户登录 </TITLE>			
	</head>									
	<body>									
<?php										
	$_COOKIE{"user_name"}=$_POST{"user_name"};		
	$_COOKIE{"user_pw"}=$_POST{"user_pw"};			
	if ($_COOKIE{"user_name"}=="php" && $_COOKIE{"user_pw"}=="php"){		
												
		echo "恭喜您!登录成功！";					
	}else{										
		echo  "你输入的用户名为：".$_COOKIE{"user_name"};	
		echo  "<br>口令为:".$_COOKIE{"user_pw"};		
		echo  "你输入的用户名和密码不正确，请尝试新的输入。";	
	}
?>												
	<p><a href="12-7.php">单击检测 Cookie的值是否可以页间传递</a>				
												
	</body>										
</html>							
