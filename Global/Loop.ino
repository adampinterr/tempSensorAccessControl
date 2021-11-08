void loop() {
  if(digitalRead(PIR_SIGNAL)==HIGH){
    Serial.println("Mozgas eszlelve");
    digitalWrite(LED_PIN, HIGH);
    nfcRead();
    }
  else{
    Serial.println("-- Nincs mozgas");
    digitalWrite(LED_PIN, LOW);
    }
    delay(1000);
}
