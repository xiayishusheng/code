<table border="1">							
<tr>											
	<th>�ļ�</th>								
</tr>										
<?php										
	function Directory($dir) {					
		$dp = opendir($dir);					
		while ($file = readdir($dp)) {			
			if ($file!='.' && $file!='..') {	
			$path = $dir ."/". $file;			
			if (is_dir($path)) {				
				echo "<B>Ŀ¼</B>:" .$path;	
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
		//����
	Directory(realpath("D:\\images"));			
?>											
