<html>											
	<head>										
		<title>COOKIE ʵ���û���¼ </TITLE>			
	</head>									
	<body>									
<?php										
	$_COOKIE{"user_name"}=$_POST{"user_name"};		
	$_COOKIE{"user_pw"}=$_POST{"user_pw"};			
	if ($_COOKIE{"user_name"}=="php" && $_COOKIE{"user_pw"}=="php"){		
												
		echo "��ϲ��!��¼�ɹ���";					
	}else{										
		echo  "��������û���Ϊ��".$_COOKIE{"user_name"};	
		echo  "<br>����Ϊ:".$_COOKIE{"user_pw"};		
		echo  "��������û��������벻��ȷ���볢���µ����롣";	
	}
?>												
	<p><a href="12-7.php">������� Cookie��ֵ�Ƿ����ҳ�䴫��</a>				
												
	</body>										
</html>							
