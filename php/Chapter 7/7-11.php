<?php											
	$url = array('����'=>'www.sina.com',			
				'�Ż�'=>'www.yahoo.com',			
				'����'=>'www.163.com',				
				'��Ѷ'=>'www.qq.com',				
				'�ٶ�'=>'www.baidu.com'			
				);
	foreach ($url as $site => $link ) {			
		echo $site,$link ;						
		echo "<a href=http://$link>$site</a><br>";	
	}
?>												
