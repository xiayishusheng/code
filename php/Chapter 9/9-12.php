	<?php
		$email="php@163.com";
<?php											
	$email="php@163.com";							
	if(empty($email))								
	{
		echo "�ʼ���ַ����Ϊ��";						
	}
	elseif(!ereg ("([0-9a-zA-Z]+)([@])([0-9a-zA-Z]+)(.)([0-9a-zA-Z]+)", $email)								
	{
		echo "�����ʼ����Ϸ����������䣡" 				
	}
	else											
	{
		echo "�ʼ���ַΪ��$email";					
	}
?>
