void sendtoDB()
{
  if (client.connect(server, 80)) {
    client.print("GET /write_data.php?");
    client.print("ID=");
    for (int i = 0; i < mfrc522.uid.size; ++i) {
    client.print(mfrc522.uid.uidByte[i], HEX);
    }
    client.print("&");
    client.print("temp=");
    client.print(avgTemp);
    client.println(" HTTP/1.1"); // Part of the GET request
    client.println("Host: x.x.x.x"); // find out the IP address of your computer and put it here
    client.println("Connection: close");
    client.println(); // Empty line
    client.stop();    // Closing connection to server

  }

  else {
    Serial.println("--> connection failed\n");
  }
}
