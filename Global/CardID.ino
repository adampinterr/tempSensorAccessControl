void array_to_string(byte array[], unsigned int len, char buffer[])
{
   for (unsigned int i = 0; i < len; i++)
   {
      byte nib1 = (array[i] >> 4) & 0x0F;
      byte nib2 = (array[i] >> 0) & 0x0F;
      buffer[i*2+0] = nib1  < 0xA ? '0' + nib1  : 'A' + nib1  - 0xA;
      buffer[i*2+1] = nib2  < 0xA ? '0' + nib2  : 'A' + nib2  - 0xA;
   }
   buffer[len*2] = '\0';
}

void IDcheck(char ID[])
{
  char c;
  if (client.connect(DBserv, 80)) {
    Serial.println("--> connected to check ID\n");
    client.print("GET /checkID.php?");
    client.print("ID=");
    client.print(ID);
    client.println(" HTTP/1.1"); // Part of the GET request
    client.print("Host: ");
    client.println(DBserv);
    client.println("Connection: close");
    client.println();
    while (client.connected() || client.available()) 
    {
      c = client.read(); //read first character
      while (c != '|')
      {
        c = client.read();
      }
      c = client.read();
      while (c != '|')
      { 
        data = c;
        c = client.read();
        client.stop();    // Closing connection to server
        
      }
    } 
  }
  else {
    Serial.println("--> connection failed\n");
  }
  delay(1000);
}
