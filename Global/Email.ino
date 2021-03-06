void email(char ID[]) {
  delay(500);
  if (client.connect(DBserv, 80)) {
    Serial.println("--> connected\n");
    client.print("GET /email.php?");
    client.print("ID=");
    client.print(ID);
    client.println(" HTTP/1.1"); // Part of the GET request
    client.print("Host: ");
    client.println(DBserv);
    client.println("Connection: close");
    client.println(); // Empty line
    client.stop();    // Closing connection to server
    Serial.println("--> E-mail sent\n");
  }
  else {
    Serial.println("--> connection failed\n");
  }
  delay(1000);
}
