void getCard()
{
  lcd.setCursor(0,0);
  lcd.print("Erintsen kartyat");
  lcd.setCursor(0,1);
  lcd.print("az olvasohoz!");
  nfcRead();
}
void lcdprintID(char ID[])
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("ID: ");
  lcd.print(ID);
  lcd.setCursor(0,1);
  lcd.print("Homeres");
}
void lcdprintCels()
{
  lcd.setCursor(0,1);
  lcd.print(avgTemp);
  lcd.setCursor(5,1);
  lcd.print(" Celsius");
  delay(5000);
}
void lcdClear()
{
  lcd.clear();
}
