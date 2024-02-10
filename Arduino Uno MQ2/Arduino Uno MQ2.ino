#include <SoftwareSerial.h> 

const int gasSensorPin = A0; 
const int redLEDPin = 13; 
const int greenLEDPin = 12; 
const int buzzerPin = 11; 
const int bluetoothPin = (2, 3) ; 

SoftwareSerial bluetooth(2, 3); 
void setup() { 

 pinMode(gasSensorPin, INPUT); 
 pinMode(redLEDPin, OUTPUT); 
 pinMode(greenLEDPin, OUTPUT); 
 pinMode(buzzerPin, OUTPUT); 
 pinMode(bluetoothPin, OUTPUT); 
 
 bluetooth.begin(9600); 
} 
void loop() { 

 int gasValue = analogRead(gasSensorPin); 

 if (gasValue > 250) { 
 digitalWrite(redLEDPin, HIGH); 
 digitalWrite(buzzerPin, HIGH); 
 delay(500); 
 digitalWrite(redLEDPin, LOW); 
 digitalWrite(buzzerPin, LOW); 
 delay(500); 
 } 

 else { 
 digitalWrite(greenLEDPin, HIGH); 
 delay(500); 
 digitalWrite(greenLEDPin, LOW); 
 delay(500); 
 } 

8 
 if (gasValue > 250) { 
 char gasValue = bluetooth.read(); 
 bluetooth.println("GAZ_VAR "); 
 bluetooth.flush(); 
 delay(2000); 
 } 
 else { 
 char gasValue = bluetooth.read();  
 bluetooth.println("GAZ_YOK "); 
 bluetooth.flush(); 
 delay(2000); 
 } 
}
