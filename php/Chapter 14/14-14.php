<?php
$j = ""; 
print("Lets retrieve all the variables submitted to this.<br> "); 
print("script via a GET request:<br>");
foreach($_GET as $key => $i){ 
print("Correct data? " . $_GET[$key] ."<br>"); 
print("$key=$j<br>"); 
} 
if($_GET['Submit'] == "Send GET Request")
$j = "done!<br>"; 
?> 
<form method="GET"> 
&nbspName: <input name="name"><br> 
Email: <input name="email" ><p> 
<input name="Submit" type="submit" value="Send Request"> 
</form>
