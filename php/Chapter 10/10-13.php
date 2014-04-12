<table border="1">							
<tr>											
	<th>文件</th>								
</tr>										
<?php										
	function Directory($dir) {					
		$dp = opendir($dir);					
		while ($file = readdir($dp)) {			
			if ($file!='.' && $file!='..') {	
			$path = $dir ."/". $file;			
			if (is_dir($path)) {				
				echo "<B>目录</B>:" .$path;	
				echo "<br>";					
				Directory($path);				
				} 
			else {							
				echo "<tr>";					
				echo "<td>" .$path."</td>";	
				echo "</tr>";					
				}
			} 
		}
		closedir($dp);						
	}
		//调用
	Directory(realpath("D:\\images"));			
?>											
