void email() {
if (temperature >= 18){
  if (client.connect(server, 80)) {
    client.println("POST /MEMS/emailNotification.php HTTP/1.1");
    client.println("Host: www.adampinterr.hu");
    client.println("Content-Type: application/x-www-form-urlencoded");
    client.print("Content-Length: ");
    client.println(postData.length());
    client.println();
    client.print(postData);

    Serial.println("Email Sent");
    Serial.println(postData);
  }

  if (client.connected()) {
    client.stop();
  }

  delay(2000);
}

  Serial.println(postData);

  delay(3000);
}
