<?											
	print("<B>距离星期一还有几天？</B>\n");
	print("<OL>\n");
	for($currentDate = date("U"); 				
		date("l", $currentDate) != "Monday"; 	
		$currentDate += (60 * 60 * 24))		
	{
		print("<LI>" . date("l", $currentDate) . "\n");
			
	}
	print("</OL>\n");
?>											
