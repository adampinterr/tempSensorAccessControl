#include <SPI.h>
#include <MFRC522.h>
#include <WiFi101.h> //directory for connecting the arduino to wireless networks
#include <LiquidCrystal.h>

#include "secret.h" //contains the SSID and password to the wireless network, needed for sending data to database and sending alert emails
#include "emailinfo.h" //contains the information needed for the email alerts via Gmail
#define SS_PIN 11 /* Slave Select pin, maps to SDA */
#define RST_PIN 7 /* RST pin*/
#define PIR_SIGNAL 6

LiquidCrystal lcd(0, 1, 2, 3, 4, 5);
MFRC522 mfrc522(SS_PIN, RST_PIN);
int TEMPSENSOR = A0; // select the input pin for the tempsensor 
int sensorValue = 0;   // variable to store the value coming from the sensor 
float temperature = 0.0;  
float voltage = 0.0;
float avgTemp;
float allTemp = 0;
int status = WL_IDLE_STATUS;

char DBserv[]="192.168.130.142"; // find out the IP address of your computer and put it here 
WiFiClient client;
