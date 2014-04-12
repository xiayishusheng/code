<?php											
	$name="php";									
	if(empty($name))								
	{
		echo "姓名不能为空";						
	}
		//判断长度
	elseif((strlen($name)<3) || (strlen($name)>10))	
	{
		echo "姓名长度必须在3和10之间";				
	}
	elseif(!ereg("[0-9a-zA-Z]+",$name))
		echo ""姓名格式不正确;
	else											
	{
		echo "用户名为：$name";						
	}
?>												
