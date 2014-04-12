<?php												
	$numb=array(1,1.2,-2.3,90.25);						
	echo "数组\$numb的元素个数：".count($numb)."<br>";		

	echo "数组元素值：<br>";  print_r($numb); echo "<br>";
	echo "数组的各元素之和：<br>".array_sum($numb)."<br>";	

	asort($numb);										

	echo "排序结果:<br>"; print_r($numb); echo "<br>";	
	rsort($numb);										

	echo "排序结果:<br>"; print_r($numb); echo "<br>";	
?>													
													