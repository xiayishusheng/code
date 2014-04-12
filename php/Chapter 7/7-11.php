<?php											
	$url = array('新浪'=>'www.sina.com',			
				'雅虎'=>'www.yahoo.com',			
				'网易'=>'www.163.com',				
				'腾讯'=>'www.qq.com',				
				'百度'=>'www.baidu.com'			
				);
	foreach ($url as $site => $link ) {			
		echo $site,$link ;						
		echo "<a href=http://$link>$site</a><br>";	
	}
?>												
