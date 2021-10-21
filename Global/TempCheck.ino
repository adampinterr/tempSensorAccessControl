void tempCheck(){
  
  sensorValue = analogRead(sensorPin); 
  voltage = sensorValue * (3300/1024); // in milliVolt 
  Serial.print(" voltage = "); 
  Serial.print(voltage); 
  
  temperature = (voltage - 500 ) / 10; 
  Serial.print(" temperature(C) = "); 
  Serial.print(temperature);
  Serial.print("  ");

  for(int i = 0; i<10; i++)
  {
        allTemp = allTemp + temperature;
        delay(500);
  }
  avgTemp = allTemp / 10;
  Serial.print(" | avgTemp:");
  Serial.println(avgTemp);
  delay(500);
}
