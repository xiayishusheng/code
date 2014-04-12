<?php											
	$result=preg_match("/\bstudent \b/","many students have received praise ");
											
	if($result){									
		echo "匹配成功<br>";						
	}
	else											
		echo "匹配不成功"							
?>												
