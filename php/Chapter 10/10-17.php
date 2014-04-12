<?												
												
	print("<table border=\"1\">\n");				
												
	print("<tr><font color='red'>\n");				
	print("<th>文件名</th>\n");						
	print("<th>文件大小</th>\n");					
	print("<th>文件类型</th>\n");					
	print("<th>文件修改时间</th>\n");				
	print("</font></tr>\n");						
	$Directory = opendir(".");						
												
	while($eName = readdir($Directory))			
	{	
		print("<tr>");							
		print("<td>$eName</td>");					
		print("<td ALIGN=\"right\">");				
		print(filesize($eName));					
		print("</td>");							
	print("<td ALIGN=\"right\">");					
	print(filetype($eName));						
	print("</td>");								
	print ("<td>");								
	print (date("Y 年 n 月 t 日",filemtime($eName)));
	print "</td>";								
	print("</tr>\n");								
	}
	closedir($Directory);							
	print("</table>\n");							
?>												
							
