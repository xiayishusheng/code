<?php												
	$numb=array(1,1.2,-2.3,90.25);						
	echo "����\$numb��Ԫ�ظ�����".count($numb)."<br>";		

	echo "����Ԫ��ֵ��<br>";  print_r($numb); echo "<br>";
	echo "����ĸ�Ԫ��֮�ͣ�<br>".array_sum($numb)."<br>";	

	asort($numb);										

	echo "������:<br>"; print_r($numb); echo "<br>";	
	rsort($numb);										

	echo "������:<br>"; print_r($numb); echo "<br>";	
?>													
													