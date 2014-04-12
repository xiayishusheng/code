<?php 
	include("counter.php")						//调用counter.php文件
?>

<html>	
	<head>
		<title>访问者计数器</title> 					
	<body> 
		<center>								
		 <h1>访问者计数器</h1>						
	<U>											
	<FONT SIZE="6" face="隶书" >你是第</FONT> 		
	<B> 
		<FONT SIZE="9" face="verdana" COLOR="#ffcc00">	
		<?php Counter()?> 						
	</FONT> 										
	</B>
	<FONT SIZE="6" face="隶书" >个访问者</FONT> 		
	</U> 
	</center>									
	</body> 
</html>
