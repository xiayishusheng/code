<?												
	echo "<h4>-10 到10的Atan函数的值<h4>";			
	print("<table border=\"1\">\n");				
	print("<tr><th>x</th><th>Atan(x)</th><th>Atan(|x|)</th></tr>\n");		
												
	for($x = -10; $x <= 10; $x += 2)				
	{
		print("<tr>");							
		print("<td>$x</td>");						
		print("<td>" . Atan($x) . "</td>");		
		print("<td>" . Atan(Abs($x)) . "</td>");	
		print("</tr>");							
}
	print("</table>");							
?>												
