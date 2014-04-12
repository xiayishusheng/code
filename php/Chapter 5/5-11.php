<?php											
	print("<table border=1>"); 					
	for($row=1; $row <= 9; $row ++)				
	{
		print("<tr>\n"); 							
		for($column=1; $column <= $row; $column ++)	
	{
		print("<td>");							
		print($row * $column);					
		print("</td>");							
	}											
		print("</tr>"); 							
	}
	print("</table>"); 							
?>												
