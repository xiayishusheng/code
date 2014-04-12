<?php
	setcookie("cookie[A]","2008");					
	setcookie("cookie[B]","I am a student.");		
	setcookie("cookie[C]","I am a teacher.");		
	if(isset($_COOKIE['cookie'])){					
	  foreach($_COOKIE['cookie'] as $name=>$value){	
	    echo "$name:$value<br>";					
	  }
	}
	else 										
		echo "不是数组."							
?>
