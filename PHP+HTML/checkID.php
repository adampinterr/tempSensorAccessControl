<?php

$con=mysqli_connect("localhost","arduino","zsepi32","tempsensoraccesscontrol");
if(isset($_GET['ID'])){
	$getid="SELECT cardID, Name FROM users WHERE cardID='".$_GET['ID']."'";
	$res= mysqli_query($con,$getid);
	$cardID=NULL;
	$name=NULL;
	while($row=mysqli_fetch_array($res))
	{
		$cardID=$row['cardID'];
		$name=$row['Name'] ;
	}
	if($cardID!="")
	{
		echo "|T|"; 
	}
	else{
		echo "|F|";
	}
}
?>