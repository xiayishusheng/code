<html>											
	<head>										
	<title>个人信息表单</title>						
	</head>										
	<body>										
	<form action="action.php" method="POST">		
	请选择你的学校名称:								
	<hr><p>										
	    <input type="radio" name="college" value="北京大学">  北京大学		
												
	    <input type="radio" name="college" value="清华大学">  清华大学		
												
	    <input type="radio" name="college" value="北京师大">  北京师大		
												
	    <input type="radio" name="college" value="中国人大">  中国人大		
												
	    <input type="radio" name="college" value="北京理工">  北京理工		
												
		<input type="radio" name="college" value="北航">  北航			
												
 		<input type="radio" name="college" value="其他">  其他			
												
	</p>
	<p> 姓名: <input name="student" type="text" size="20" maxlength="20"></p>
													
	<p> 学号: <input name="numb" type="text" size="20" maxlength="20"></p>	
													
	<p> <input name="submit" type="submit" value="提交">					
													
	    <input name="reset" type="reset" value="重置">	
	</p>	
	</form>											
	</body>											
</html>												