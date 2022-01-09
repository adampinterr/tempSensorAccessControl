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
        sensorValue = analogRead(TEMPSENSOR); 
        voltage = sensorValue * (3300/1024); // in milliVolt 
        temperature = (voltage - 500 ) / 10;
        allTemp = allTemp + temperature;
        delay(500);

  }
  avgTemp = allTemp / 10;
  lcdprintCels();
  Serial.print(" | avgTemp:");
  Serial.println(avgTemp);
}
