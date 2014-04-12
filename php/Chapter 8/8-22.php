<?php												  
	$s1="abcdef";$s2="a";$s3=strcmp($s1,$s2);			   
	echo  "\$s1=$s1  \$s2=$s2 \$s3=strcmp(\$s1,\$s2) 结果是: $s3";
													 
	$s1="abcdef"; $s2=substr($s1,3,2); 				   
	echo "<br>\$s1=$s1  \$s2=substr (\$s1,3,2)  结果是:$s2"; 

	$s1="abcdefcdef"; $s2="cd"; $s3=substr_count($s1,$s2); 
	echo "<br>\$s1=$s1   \$s2=$s2   \$s3=substr_count(\$s1,\$s2)";
													  
	echo "结果是:$s3";									   

	$s1="abcdef";  $s2="cd";  $s3=strpos($s1,$s2);		 
	echo "<br> \$s1=$s1  \$s2=$s2     \$s3=strpos(\$s1,\$s2)";
													 
	echo "结果是:$s3";									 

	$s1="php@phei.com.cn"; $s2="@";$s3=strstr($s1,$s2);	  
	echo "<br>\$s1=$s1  \$s2=$s2  \$s3=strstr(\$s1,\$s2);";
	echo "  结果是:$s3";								 
	$s1="Come TO";									 
	echo "<br>$s1 用strtoupper函数变换为大写:"; echo strtoupper($s1);	
												 
	echo "<br>$s1 用strtolower函数变换为大写:"; echo strtolower($s1);		
												
?>													 
