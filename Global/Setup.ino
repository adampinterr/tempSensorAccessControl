void setup() {
  pinMode(LED, OUTPUT);
  digitalWrite(LED, HIGH);
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
  //WiFi.config(ip);
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present");
    // don't continue:
    while (true);
  }
  while (status != WL_CONNECTED) 
  {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(mySSID);
    status = WiFi.begin(mySSID,PASSWORD);
    // wait 5 seconds for connection:
    delay(5000);
  }
  Serial.println("Connected to wifi");
  printWifiStatus();
  lcd.begin(16, 2); 
}
