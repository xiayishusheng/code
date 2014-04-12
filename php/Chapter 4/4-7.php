<?php									
	$large_number=1000000000;				
	var_dump($large_number);				
		//输出为：int(1000000000)
	$large_number=2147483648;				
		//输出为：float(2147483648)
	var_dump($large_number);				
		//同样也适用于十六进制表示的整数
	var_dump(0x80000000);					
		//输出为：float(2147483648)
	$million = 1000000;					
	$large_number = 50000*$million;		
		//输出为：float(50000000000)
	var_dump($large_number);				
?>										
										
