<?php											
	echo "ͨ���ո�ָ��ַ�����<br>";					
	$pizza="a1 a2 a3 a4 a5 a6";					
		//ͨ���ո�ָ�
	$pieces=explode(" ",$pizza);					
		//������������ͷ����Ԫ��
	echo $pieces[0]."<br>";						
	echo $pieces[1]."<br>";						
		//���ָ����Ԫ�ر��浽list������
	echo "���ָ����Ԫ�ر��浽list�����У�<br>";		
	$data="localhost/root/123456";					
	list($host,$user,$password)=explode("/",$data);
	echo "\$host=".$host. "<br>";					
	echo "\$user=".$user. "<br>";					
	echo "\$password=".$password. "<br>";
	echo "���Ʒָ����ַ�������<br>";					
	$limit="a;b;c;d;e;f;";						
	$back=explode(";",$limit,3);					
	print_r($back);								
?>												
