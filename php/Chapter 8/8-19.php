<?php											
	echo "通过空格分隔字符串：<br>";					
	$pizza="a1 a2 a3 a4 a5 a6";					
		//通过空格分隔
	$pieces=explode(" ",$pizza);					
		//输出返回数组的头两个元素
	echo $pieces[0]."<br>";						
	echo $pieces[1]."<br>";						
		//将分隔后的元素保存到list变量中
	echo "将分隔后的元素保存到list变量中：<br>";		
	$data="localhost/root/123456";					
	list($host,$user,$password)=explode("/",$data);
	echo "\$host=".$host. "<br>";					
	echo "\$user=".$user. "<br>";					
	echo "\$password=".$password. "<br>";
	echo "限制分隔的字符串数：<br>";					
	$limit="a;b;c;d;e;f;";						
	$back=explode(";",$limit,3);					
	print_r($back);								
?>												
