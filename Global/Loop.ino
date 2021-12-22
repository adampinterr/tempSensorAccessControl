void loop() {
  if(digitalRead(PIR_SIGNAL)==HIGH){
    Serial.println("--Mozgas eszlelve");
    getCard();
    }
  else{
    Serial.println("-- Nincs mozgas");
    }
    delay(1000);
}
