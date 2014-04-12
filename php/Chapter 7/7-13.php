<?php									
	$languages=array(10=>"ASP",			
					20=>"PHP",			
					21=>"JSP");			
		list($key,$value)=each($languages);
		echo "key=$key, value=$value";		
		$next=next($languages);			
		echo "<br>next=$next";			
?>										
