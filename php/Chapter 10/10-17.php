<?												
												
	print("<table border=\"1\">\n");				
												
	print("<tr><font color='red'>\n");				
	print("<th>�ļ���</th>\n");						
	print("<th>�ļ���С</th>\n");					
	print("<th>�ļ�����</th>\n");					
	print("<th>�ļ��޸�ʱ��</th>\n");				
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
	print (date("Y �� n �� t ��",filemtime($eName)));
	print "</td>";								
	print("</tr>\n");								
	}
	closedir($Directory);							
	print("</table>\n");							
?>												
							
