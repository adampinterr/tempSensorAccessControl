<?php
    $dbusername = "username";
    $dbpassword = "password";
    $server = "localhost";
	$datab = "tempsensoraccesscontrol";
	
    $dbconnect = mysqli_connect($server, $dbusername, $dbpassword);
    $dbselect = mysqli_select_db($dbconnect,$datab);
	if(isset($_GET['temp'])&&isset($_GET['ID'])){
		echo("Written to database. Temperature: ");
		echo($_GET['temp']);
		echo("°C cardID: ");
		echo($_GET['ID']);
		$sql = "INSERT INTO tempsensoraccesscontrol.temperature (cardID,temperature) VALUES ('".$_GET['ID']."','".$_GET['temp']."')";
		mysqli_query($dbconnect,$sql);
		
	}
	mysqli_close($dbconnect);
?>