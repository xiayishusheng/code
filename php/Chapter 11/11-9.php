<?php 											
												
	class user {									
												
	public $name;									
	private $password; 							
	private $lastLogin;							
												
	public function __construct($name, $password) { 
		$this->name = $name; 						
		$this->password = $password; 				
		$this->lastLogin = time(); 				
		} 
												
	function getLastLogin() { 						
		return(date("M d,Y", $this->lastLogin)); 	
		} 
	} 
												
	$user = new user("Jun", "sdf123"); 			
												
	print("����ʱ�䣺".$user->getLastLogin() ."<br>");
												
	echo  "&nbsp&nbsp�û�����".$user->name."<br>"; 	
?>												
