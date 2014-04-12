<?php 										
	echo "你生日的时间是:";						
	/*显示时间。*/
	if  (!empty($_POST['select1']))  			
	echo $_POST['select1']. "年"; 				
	if (!empty($_POST['select2']))  			
	echo $_POST['select2']. "月"; 				
	if (!empty($_POST['select3']))  			
	echo $_POST['select3']."日"."<p>"; 			
?>											
<a href="9-14.php" title="返回首页。">返回首页</a>	
