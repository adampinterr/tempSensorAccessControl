void getCard()
{
  lcd.setCursor(0,0);
  lcd.print("Erintsen kartyat");
  lcd.setCursor(2,1);
  lcd.print("az olvasohoz");
  nfcRead();
}
void lcdprintID(char ID[])
{
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print("ID: ");
  lcd.print(ID);
}
void lcdTempchk()
{  
  lcd.setCursor(3,1);
  lcd.print("Homeres...");
}
void lcdprintCels()
{
  lcd.setCursor(3,1);
  lcd.print(" ");
  lcd.print(avgTemp);
  lcd.print(" ");
  lcd.write(byte(0));
  lcd.print("C");
  lcd.print(" ");
  if(avgTemp<THRES)
  {
    digitalWrite(LED, LOW);
  }
  delay(5000);
}
void lcdClear()
{
  lcd.clear();
}
void lcdWrongCard()
{
  lcd.clear();
  lcd.setCursor(5,0);
  lcd.print("Kartya");
  lcd.setCursor(3,1);
  lcd.print("elutasitva");
  delay(5000);
}
