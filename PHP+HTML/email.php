<?php
use PHPMailer\PHPMailer\PHPMailer;
use PHPMailer\PHPMailer\SMTP;
use PHPMailer\PHPMailer\Exception;

require_once __DIR__ . '/phpmailer/src/Exception.php';
require_once __DIR__ . '/phpmailer/src/PHPMailer.php';
require_once __DIR__ . '/phpmailer/src/SMTP.php';
$con=mysqli_connect("localhost","username","password","tempsensoraccesscontrol");
header('Content-type: text/plain; charset=utf-8');
if(isset($_GET['ID'])){
	$getthings="SELECT Email, Name FROM users WHERE cardID='".$_GET['ID']."'";
	$res= mysqli_query($con,$getthings);
	$email=NULL;
	$name=NULL;
	while($row=mysqli_fetch_array($res))
	{
		$email=$row['Email'];
		$name=$row['Name'] ;
	}
	// passing true in constructor enables exceptions in PHPMailer
	$mail1 = new PHPMailer(true);
	try {
		// Server settings
		$mail1->SMTPDebug = SMTP::DEBUG_SERVER; // for detailed debug output
		$mail1->isSMTP();
		$mail1->Host = 'smtp.gmail.com';
		$mail1->SMTPAuth = true;
		$mail1->SMTPSecure = PHPMailer::ENCRYPTION_STARTTLS;
		$mail1->Port = 587;

		$mail1->Username = 'example@gmail.com'; // YOUR gmail
		$mail1->Password = '********'; // YOUR gmail password

		// Sender and recipient settings
		$mail1->setFrom('example@gmail.com','Somebody');
		$mail1->addAddress($email,$name);

		// Setting the email content
		$mail1->IsHTML(true);
		$mail1->Subject = "TEMPERATURE ALERT";
		$mail1->Body = '<h1>TEMPERATURE IS ABOVE THRESHOLD</h1><br><h2>Please visit a doctor asap!</h2>';
		//$mail->AltBody = 'Plain text message for non-HTML';

		$mail1->send();
		echo "Email message sent.";
	} catch (Exception $e) {
		echo "Error in sending email. Mailer Error: {$mail->ErrorInfo}";
	}
		$mail = new PHPMailer(true);
	try {
		// Server settings
		$mail->SMTPDebug = SMTP::DEBUG_SERVER; // for detailed debug output
		$mail->isSMTP();
		$mail->Host = 'smtp.gmail.com';
		$mail->SMTPAuth = true;
		$mail->SMTPSecure = PHPMailer::ENCRYPTION_STARTTLS;
		$mail->Port = 587;

		$mail->Username = 'example@gmail.com'; // YOUR gmail
		$mail->Password = '********'; // YOUR gmail password

		// Sender and recipient settings
		$mail->setFrom('example@gmail.com','Somebody');
		$mail->addAddress("someones@gmail.com","Someone");

		// Setting the email content
		$mail->IsHTML(true);
		$mail->Subject = "ALERTED";
		$mail->Body = '<h2>Temperature is above threshold for '.$name.'</h2><br><h3>Please follow the safety instructions!</h3>';
		//$mail->AltBody = 'Plain text message for non-HTML';

		$mail->send();
		echo "Email message sent.";
	} catch (Exception $e) {
		echo "Error in sending email. Mailer Error: {$mail->ErrorInfo}";
	}
}
mysqli_close($con);


?>