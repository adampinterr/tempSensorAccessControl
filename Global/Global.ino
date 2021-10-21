#include <SPI.h>
#include <MFRC522.h>
#include "secret.h" //contains the SSID and password to the wireless network, needed for sendin data to database and sending alert emails
#include <WiFi101.h> //directory for connecting the arduino to wireless networks
#define SS_PIN 11 /* Slave Select pin, maps to SDA */
#define RST_PIN 6 /* RST pin*/

MFRC522 mfrc522(SS_PIN, RST_PIN);
int sensorPin = A0; // select the input pin for the tempsensor 
int sensorValue = 0;   // variable to store the value coming from the sensor 
float temperature = 0.0;  
float voltage = 0.0;
float avgTemp;
float allTemp = 0;
int status = WL_IDLE_STATUS;

char server[] = "www.adampinterr.hu";
String postData;
String postVariable = "temp=";
WiFiClient client;
