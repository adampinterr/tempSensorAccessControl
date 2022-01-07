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
  tempCheck();
  if (avgTemp > 18){
    email(ID);
  }
  sendtoDB(ID);
  mfrc522.PICC_HaltA();
}
