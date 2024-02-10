#include <SoftwareSerial.h> 

const int gazSensorPin = A0; 
const int kirmiziLEDPin = 13; 
const int yesilLEDPin = 12; 
const int buzzerPin = 11; 
const int bluetoothPin = (2, 3) ; 

SoftwareSerial bluetooth(2, 3); 
void setup() { 

 pinMode(gazSensorPin, INPUT); 
 pinMode(kirmiziLEDPin, OUTPUT); 
 pinMode(yesilLEDPin, OUTPUT); 
 pinMode(buzzerPin, OUTPUT); 
 pinMode(bluetoothPin, OUTPUT); 
 
 bluetooth.begin(9600); 
} 
void loop() { 

 int gazDegeri = analogRead(gazSensorPin); 

 if (gazDegeri > 250) { 
 digitalWrite(kirmiziLEDPin, HIGH); 
 digitalWrite(buzzerPin, HIGH); 
 delay(500); 
 digitalWrite(kirmiziLEDPin, LOW); 
 digitalWrite(buzzerPin, LOW); 
 delay(500); 
 } 

 else { 
 digitalWrite(yesilLEDPin, HIGH); 
 delay(500); 
 digitalWrite(yesilLEDPin, LOW); 
 delay(500); 
 } 

8 
 if (gazDegeri > 250) { 
 char gazDegeri = bluetooth.read(); 
 bluetooth.println("GAZ_VAR "); 
 bluetooth.flush(); 
 delay(2000); 
 } 
 else { 
 char gazDegeri = bluetooth.read();  
 bluetooth.println("GAZ_YOK "); 
 bluetooth.flush(); 
 delay(2000); 
 } 
}
