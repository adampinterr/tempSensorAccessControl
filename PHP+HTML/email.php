<?php
use PHPMailer\PHPMailer\PHPMailer;
use PHPMailer\PHPMailer\SMTP;
use PHPMailer\PHPMailer\Exception;

require_once __DIR__ . '/phpmailer/src/Exception.php';
require_once __DIR__ . '/phpmailer/src/PHPMailer.php';
require_once __DIR__ . '/phpmailer/src/SMTP.php';
$con=mysqli_connect("localhost","arduino","zsepi32","tempsensoraccesscontrol");
header('Content-type: text/plain; charset=utf-8');
if(isset($_GET['ID'])){
	$getthings="SELECT Email, Name FROM users WHERE cardID='".$_GET['ID']."'";
	$res= mysqli_query($con,$getthings);
	$email;
	$name;
	while($row=mysqli_fetch_array($res))
	{
		$email=$row['Email'];
		$name=$row['Name'] ;
	}
	// passing true in constructor enables exceptions in PHPMailer
	$mail = new PHPMailer(true);
	try {
		// Server settings
		$mail->SMTPDebug = SMTP::DEBUG_SERVER; // for detailed debug output
		$mail->isSMTP();
		$mail->Host = 'smtp.gmail.com';
		$mail->SMTPAuth = true;
		$mail->SMTPSecure = PHPMailer::ENCRYPTION_STARTTLS;
		$mail->Port = 587;

		$mail->Username = '-----@-----.---'; // YOUR gmail email
		$mail->Password = '-----'; // YOUR gmail password

		// Sender and recipient settings
		$mail->setFrom('tempSensorAccessControl@gmail.com','Arduino TempCheck');
		$mail->addAddress($email,$name);
		//$mail->addReplyTo('tempSensorAccessControl@gmail.com'); // to set the reply to

		// Setting the email content
		$mail->IsHTML(true);
		$mail->Subject = "TEMPERATURE ALERT";
		$mail->Body = '<h1>TEMPERATURE IS ABOVE THRESHOLD</h1><br><h2>Please visit a doctor asap!</h2>';
		//$mail->AltBody = 'Plain text message for non-HTML';

		$mail->send();
		echo "Email message sent.";
	} catch (Exception $e) {
		echo "Error in sending email. Mailer Error: {$mail->ErrorInfo}";
	}
}
mysqli_close($con);


?>