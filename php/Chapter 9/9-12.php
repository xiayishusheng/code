	<?php
		$email="php@163.com";
<?php											
	$email="php@163.com";							
	if(empty($email))								
	{
		echo "邮件地址不能为空";						
	}
	elseif(!ereg ("([0-9a-zA-Z]+)([@])([0-9a-zA-Z]+)(.)([0-9a-zA-Z]+)", $email)								
	{
		echo "电子邮件不合法，请重新输！" 				
	}
	else											
	{
		echo "邮件地址为：$email";					
	}
?>
