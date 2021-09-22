int sensorPin = A0; // select the input pin for the sensor 
int sensorValue = 0;   // variable to store the value coming from the sensor 
float temperature = 0.0;  
float voltage = 0.0;
int buttonValue = 0;
int buttonState;

float avgTemp;
float allTemp = 0;
void setup() {
  pinMode(2, INPUT); 
  Serial.begin(9600); 
  analogReadResolution(10); 
} 
  
void loop() { 
  tempCheck();
}
 
// Serial.print("sensorValue = "); 
// Serial.print(sensorValue); 


void tempCheck(){
  sensorValue = analogRead(sensorPin); 
  voltage = sensorValue * (3300/1024); // in milliVolt 
  Serial.print(" voltage = "); 
  Serial.print(voltage); 
  temperature = (voltage - 500 ) / 10; 
  Serial.print(" temperature(C) = "); 
  Serial.print(temperature);
  Serial.print("  ");
  buttonValue=digitalRead(2); //gomb beolvasas
  if(buttonValue == HIGH){ //gomb ertek valtozas figyelese
    buttonState = 1;
    delay(1000);
    for(int i = 0; i<10; i++){
        allTemp = allTemp + temperature;
      }
      avgTemp = allTemp / 10;
    }
  else{
    buttonState = 0;
    allTemp = 0;
    avgTemp = 0;
    } 
  Serial.print(buttonState); // idaig
  Serial.print(" | avgTemp:");
  Serial.println(avgTemp);
  delay(500);
}
