<?php									
	$large_number=1000000000;				
	var_dump($large_number);				
		//���Ϊ��int(1000000000)
	$large_number=2147483648;				
		//���Ϊ��float(2147483648)
	var_dump($large_number);				
		//ͬ��Ҳ������ʮ�����Ʊ�ʾ������
	var_dump(0x80000000);					
		//���Ϊ��float(2147483648)
	$million = 1000000;					
	$large_number = 50000*$million;		
		//���Ϊ��float(50000000000)
	var_dump($large_number);				
?>										
										
