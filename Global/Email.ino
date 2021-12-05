void email() {
if (temperature > 18){
  // Function send a secure email via Gmail     
  Serial.println("Attempting to connect to GMAIL server");
  if (client.connect(_GMailServer, 465) == 1) {
    Serial.println(F("Connected"));
  } else {
    Serial.print(F("Connection failed:"));
  }
  Serial.println(F("Sending Extended Hello"));
  client.println("EHLO gmail.com");
   
  Serial.println(F("Sending auth login"));
  client.println("auth login");
    
  Serial.println(F("Sending User"));
  client.println(_mailUser);
    
  Serial.println(F("Sending Password"));
  client.println(_mailPassword);
    
  Serial.println(F("Sending From"));
  // sender email address
  client.println(F("MAIL FROM: <arduinitepower@gmail.com>"));
   
  // recipient address
  Serial.println(F("Sending To"));
  client.println(F("RCPT To: <retnipadam@gmail.com>"));
  client.println(F("RCPT To: <zsedenyi.balint.adam@gmail.com>"));
  // Repeat above line for EACH recipient (if there is more than one)
    
  Serial.println(F("Sending DATA"));
  client.println(F("DATA"));
   
  client.println(F("From: tempsensoraccesscontrol@gmail.com"));
  client.println(F("Subject: TEMPERATURE ALERT"));
  client.println(F("DETECTED TEMPERATURE IS ABOVE THRESHOLD"));
    
  // IMPORTANT - must send a complete line containing just a "." to end the conversation
  client.println(F("."));
    
  Serial.println(F("Sending QUIT"));
  client.println(F("QUIT"));
   
  client.stop();
  Serial.println(F("Disconnected"));
  }
}
