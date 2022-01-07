<?php
  $ID=$name=$email="";
  if(isset($_POST["cardID"])&&isset($_POST["name"])&& isset($_POST["email"]))
  {
	echo "ID:", $_POST["cardID"],"<br>";
	echo "Name:", $_POST["name"],"<br>";
	echo "E-mail:", $_POST["email"],"<br>";
	$ID=$_POST["cardID"];
	$name=$_POST["name"];
	$email=$_POST["email"];
  }
  $con=mysqli_connect("localhost","arduino","zsepi32","tempsensoraccesscontrol");
  $sql = "INSERT INTO tempsensoraccesscontrol.users (cardID,Name,Email) VALUES ('".$ID."','".$name."','".$email."')";
  mysqli_query($con,$sql);
  mysqli_close($con);
?>