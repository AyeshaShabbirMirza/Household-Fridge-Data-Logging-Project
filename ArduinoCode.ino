#include <Wire.h>
#include <RTClib.h>
#include <SD.h>

RTC_DS3231 rtc;
File dataFile;
const int ACS712_PIN = A0;
const int mVperAmp = 66; 

void setup() {
 Serial.begin(9600);
 while (!Serial) {
 ; 
 }

 if (!SD.begin(10)) {
 Serial.println("SD CARD IS NOT INITIALIZED!");
 return;
 }

 dataFile = SD.open("data.csv", FILE_WRITE);

 if (!dataFile) {
 Serial.println("ERROR! .CSV FILE IS NOT OPENED");
 return;
 }

 if (!rtc.begin()) {
 Serial.println("COULD'NT FIND RTC");
 while (1);
 }

 if (rtc.lostPower()) {
 Serial.println("RTC LOST POWER, SETTING THE TIME...");
 rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
 }

 dataFile.println("Date,Time,Current,Power");
 dataFile.flush();
}

void loop() {
 DateTime now = rtc.now();
 
 int readValue;  
 int maxValue = 0; 
 int minValue = 1024; 

 uint32_t start_time = millis();
 while ((millis() - start_time) < 1000) 
 {
 readValue = analogRead(ACS712_PIN);
 
 if (readValue > maxValue)
 {
 
 maxValue = readValue;
 }
 if (readValue < minValue)
 {
 
 minValue = readValue;
 }
 }

 float Voltage = ((maxValue - minValue) * 5.0) / 1024.0;
 float VRMS = (Voltage / 2.0) * 0.707; 
 float AmpsRMS = (VRMS * 1000) / mVperAmp;
 float current = AmpsRMS-0.15;
 float power = current * 220.0; 

 String dataString = String(now.year()) + "-" + String(now.month()) + "-" + String(now.day()) + "," +
 String(now.hour()) + ":" + String(now.minute()) + ":" + String(now.second()) + "," +
 String(current) + "," + String(power);

 dataFile.println(dataString);
 dataFile.flush();

 Serial.println(dataString);

 delay(60000); 

 DateTime nextDay = now + TimeSpan(24 * 60 * 60);
 if (nextDay <= rtc.now()) {
 dataFile.close();
 while (1);
 }
}