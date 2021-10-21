void loop() {
  
  if ( ! mfrc522.PICC_IsNewCardPresent() ) {
      return; 
  } 
  if ( ! mfrc522.PICC_ReadCardSerial() ) {
      return;
  }
  char ID[32] = "";
  array_to_string(mfrc522.uid.uidByte, 4, ID);
  tempCheck();
  printCardUid();
  mfrc522.PICC_HaltA();
}
