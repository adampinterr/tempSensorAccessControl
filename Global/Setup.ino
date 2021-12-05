void setup() {
  pinMode(2, INPUT);
  pinMode(PIR_SIGNAL, INPUT);
  Serial.begin(9600);
  analogReadResolution(10);
  SPI.begin();
  mfrc522.PCD_Init();
  while (!Serial) 
  {
    ; // wait for serial port to connect.
  }
  Serial.println("Serial initialized...");
  
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present");
    // don't continue:
    while (true);
  }
  while (status != WL_CONNECTED) 
  {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(mySSID);
    //Connect to WPA/WPA2 network.Change this line if using open/WEP network
    status = WiFi.begin(mySSID,PASSWORD);
    // wait 10 seconds for connection:
    delay(10000);
  }
  Serial.println("Connected to wifi");
  printWifiStatus();
  lcd.begin(16, 2); 
}
