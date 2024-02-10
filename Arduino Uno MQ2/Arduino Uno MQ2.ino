#include <SoftwareSerial.h> 
// MG2 gaz sensörünün pinlerini tanımlayalım 
const int gazSensorPin = A0; 
const int kirmiziLEDPin = 13; 
const int yesilLEDPin = 12; 
const int buzzerPin = 11; 
const int bluetoothPin = (2, 3) ; 
// Bluetooth modülünü tanımlayalım 
SoftwareSerial bluetooth(2, 3); 
void setup() { 
 // Giriş/çıkış pinlerini tanımlayalım 
 pinMode(gazSensorPin, INPUT); 
 pinMode(kirmiziLEDPin, OUTPUT); 
 pinMode(yesilLEDPin, OUTPUT); 
 pinMode(buzzerPin, OUTPUT); 
 pinMode(bluetoothPin, OUTPUT); 
 // Bluetooth modülünü başlatalım 
 bluetooth.begin(9600); 
} 
void loop() { 
 // Gaz sensörünü okuyalım 
 int gazDegeri = analogRead(gazSensorPin); 
 // Eğer gaz değeri belirli bir eşik değerin üzerindeyse, 
 // kırmızı LED'i yanıp söndürüp buzzer'ı çalıştıralım 
 if (gazDegeri > 250) { 
 digitalWrite(kirmiziLEDPin, HIGH); 
 digitalWrite(buzzerPin, HIGH); 
 delay(500); 
 digitalWrite(kirmiziLEDPin, LOW); 
 digitalWrite(buzzerPin, LOW); 
 delay(500); 
 } 
 // Eğer gaz değeri belirli bir eşik değerin altındaysa, 
 // yeşil LED'i yanıp söndürelim 
 else { 
 digitalWrite(yesilLEDPin, HIGH); 
 delay(500); 
 digitalWrite(yesilLEDPin, LOW); 
 delay(500); 
 } 
 // Bluetooth modülünü kullanarak sensörün gaz tespit edip etmediğini iletelim 
8 
 if (gazDegeri > 250) { 
 char gazDegeri = bluetooth.read(); // Veriyi al 
 bluetooth.println("GAZ_VAR "); 
 bluetooth.flush(); 
 delay(2000); 
 } 
 else { 
 char gazDegeri = bluetooth.read(); // Veriyi al 
 bluetooth.println("GAZ_YOK "); 
 bluetooth.flush(); 
 delay(2000); 
 } 
}