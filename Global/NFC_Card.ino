void nfcRead() {
  
  if ( ! mfrc522.PICC_IsNewCardPresent() ) {
      return; 
  } 
  if ( ! mfrc522.PICC_ReadCardSerial() ) {
      return;
  }
  char ID[32] = "";
  array_to_string(mfrc522.uid.uidByte, 4, ID);
  Serial.print("Card ID: ");
  Serial.println(ID);
  lcdprintID(ID);
  IDcheck(ID);
  if(data=='T')
  {
    tempCheck();
    if (avgTemp > THRES){
      email(ID);
    }
    sendtoDB(ID);
  }
  else if(data=='F')
  {
    lcdWrongCard();
  }
  else
  {
    Serial.println("Wrong cardcheck, please fix");
  }
  mfrc522.PICC_HaltA();
  digitalWrite(LED, HIGH);
}
