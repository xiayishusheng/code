<?php													
	$numb=array(1,1.2,-2.3,5.4E+3,90.2);				
	$city=array(array("北京","上海","天津","重庆"),array("广州","杭州","南京","成都"));	
	for ($i=0;$i<=4;$i++){									
	   echo "\$numb[$i]=".$numb[$i]."<br>";							
	}
	echo "<br><br>";
	for ($i=0;$i<=1;$i++){									
	   for ($j=0;$j<=3;$j++){									
	   echo $city[$i][$j]."&nbsp;&nbsp;&nbsp;";		
	   }
   echo "<br>";												
	}
?>														
