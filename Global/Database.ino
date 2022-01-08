void sendtoDB(char ID[])
{
  delay(500);
  if (client.connect(DBserv, 80)) {
    Serial.println("--> connected\n");
    client.print("GET /write_data.php?");
    client.print("ID=");
    client.print(ID);
    client.print("&");
    client.print("temp=");
    client.print(avgTemp);
    client.println(" HTTP/1.1"); // Part of the GET request
    client.print("Host: ");
    client.println(DBserv);
    client.println("Connection: close");
    client.println(); // Empty line
    client.stop();    // Closing connection to server
    Serial.println("--> Data written\n");

  }
  else {
    Serial.println("--> connection failed\n");
  }
  delay(1000);
}
