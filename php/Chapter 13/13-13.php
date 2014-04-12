<?php													
	$https="http://www.phei.com.cn";						
	if (ereg ("(^http)(://)(www\.)([0-9a-zA-Z]+)+(.com)(.cn)", $https, $regs)) {		　														
		echo "$regs[1]$regs[2]$regs[3]$regs[4]$regs[5]$regs[6]";				　														
	echo "<br>";				
		} 
		else {													
			echo "你输入的网址不正确 : $Email";				
		echo "<br>";					
	}
	  $https="http://www.163.com";
		if (ereg ("(^http)(://)(www\.)([0-9a-zA-Z]+)(.)+(com|cn|net|me)", $https, $array)) {  													
			print_r($array);								
	echo "<br>";				
		} 
		else {								
			echo "你输入的网址不正确 : $Email";	
	echo "<br>";					
	}
?>

