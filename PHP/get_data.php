<?php
$url=$_SERVER['REQUEST_URI'];
header("Refresh: 5; URL=$url");  // Refresh the webpage every 5 seconds
?>
<html>
<head>
    <title>Temperature Sensor</title>
</head>
    <body>
        <h1>Temperature sensor readings</h1>
    <table border="0" cellspacing="0" cellpadding="4">
      <tr>
            <td>cardID</td>
            <td>temperature</td>
            <td>time</td>
      </tr>
      
<?php
    $con=mysqli_connect("localhost","arduino","zsepi32","tempsensoraccesscontrol");
         
    $result = mysqli_query($con,'SELECT * FROM temperature');

    while($row = mysqli_fetch_array($result))
    {      
        echo "<tr>";
        echo "<td>" . $row['cardID'] . "</td>";
        echo "<td>" . $row['temperature'] . "</td>";
        echo "<td>" . $row['time'] . "</td>";
        echo "</tr>";
        
    }
        
    mysqli_close($con);
?>
    </table>
    </body>
</html>