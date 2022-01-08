void tempCheck(){
  lcdTempchk();
  sensorValue = analogRead(TEMPSENSOR); 
  voltage = sensorValue * (3300/1024); // in milliVolt 
  Serial.print(" voltage = "); 
  Serial.print(voltage); 
  
  temperature = (voltage - 500 ) / 10; 
  Serial.print(" temperature(C) = "); 
  Serial.print(temperature);
  Serial.print("  ");
  avgTemp=0;
  allTemp=0;
  for(int i = 0; i<10; i++)
  {
        allTemp = allTemp + temperature;
        delay(500);
        temperature = (voltage - 500 ) / 10;
  }
  avgTemp = allTemp / 10;
  lcdprintCels();
  Serial.print(" | avgTemp:");
  Serial.println(avgTemp);
  delay(500);
}
