void getCard()
{
  lcd.setCursor(0,0);
  lcd.print("Erintsen kartyat");
  lcd.setCursor(0,1);
  lcd.print("az olvasohoz!");
  nfcRead();
}
void lcdprintID()
{
  lcd.clear();
  lcd.setCursor(0,0);
 for (int i = 0; i < mfrc522.uid.size; ++i) {

    lcd.print(mfrc522.uid.uidByte[i], HEX);
    lcd.print(" ");
  }
  lcd.setCursor(0,1);
  lcd.print(avgTemp);
  lcd.setCursor(5,1);
  lcd.print("Celsius");
  delay(5000);
}
