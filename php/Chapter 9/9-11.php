<?php											
	$name="php";									
	if(empty($name))								
	{
		echo "��������Ϊ��";						
	}
		//�жϳ���
	elseif((strlen($name)<3) || (strlen($name)>10))	
	{
		echo "�������ȱ�����3��10֮��";				
	}
	elseif(!ereg("[0-9a-zA-Z]+",$name))
		echo ""������ʽ����ȷ;
	else											
	{
		echo "�û���Ϊ��$name";						
	}
?>												
