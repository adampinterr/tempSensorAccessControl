<?php
$url=$_SERVER['REQUEST_URI'];
header("Refresh: 5; URL=$url");  // Refresh the webpage every 5 seconds
?>
<html>
<head>
    <title>Temperature Sensor</title>
</head>
    <body style="background-color:#000000; color:#FFFFFF">
	<div style="margin:auto; width:50%; padding: 10px; text-align: center;">
        <h1>Temperature sensor readings</h1>
	<table border="3" cellspacing="1" cellpadding="5" style="margin:auto;">
      <tr>
            <td><b>cardID</b></td>
			<td><b>Name</b></td>
            <td><b>Temperature</b></td>
            <td><b>Time</b></td>
      </tr>
      </div>
<?php
    $con=mysqli_connect("localhost","arduino","zsepi32","tempsensoraccesscontrol");
         
    $result = mysqli_query($con,'SELECT t.cardID, u.Name, t.temperature, t.time 
								 FROM temperature t, users u 
								 WHERE t.cardID=u.cardID');

    while($row = mysqli_fetch_array($result))
    {      
        echo "<tr>";
        echo "<td>" . $row['cardID'] . "</td>";
		echo "<td>" . $row['Name'] . "</td>";
        echo "<td>" . $row['temperature'] . "</td>";
        echo "<td>" . $row['time'] . "</td>";
        echo "</tr>";
        
    }
        
    mysqli_close($con);
?>
    </table>
    </body>
</html>