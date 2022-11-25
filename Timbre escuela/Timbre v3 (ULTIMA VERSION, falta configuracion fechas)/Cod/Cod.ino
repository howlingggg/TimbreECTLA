// Date and time functions using a DS3231 RTC connected via I2C and Wire lib
#include "RTClib.h"

RTC_DS3231 rtc;

char daysOfTheWeek[7][12] = {"Domingo", "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado"};

void setup () {
  pinMode(2, OUTPUT);
  pinMode(15, OUTPUT);
  Serial.begin(57600);

#ifndef ESP8266
  while (!Serial); // wait for serial port to connect. Needed for native USB
#endif

  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    Serial.flush();
    abort();
  }

  if (rtc.lostPower()) {
    Serial.println("RTC sin batería, se ajustará la hora!");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2021, 11, 4, 13, 0, 0));
  }
  // rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  // This line sets the RTC with an explicit date & time
}

void loop () {
    DateTime now = rtc.now();

    Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);    
    Serial.print(" "); 
    Serial.print(now.day(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.year(), DEC);
    Serial.print(" ");
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();
    
    if (now.month() > 2 && now.month() < 12 && now.dayOfTheWeek() > 0 && now.dayOfTheWeek() < 6) { //Marzo a Noviembre y de Lunes a Viernes
    if (now.hour() == 8 && now.minute() == 0 && now.second() <= 3
        || now.hour() == 9 && now.minute() == 20 && now.second() <= 3
        || now.hour() == 9 && now.minute() == 30 && now.second() <= 3
        || now.hour() == 10 && now.minute() == 50 && now.second() <= 3
        || now.hour() == 11 && now.minute() == 0 && now.second() <= 3
        || now.hour() == 12 && now.minute() == 20 && now.second() <= 3
        || now.hour() == 13 && now.minute() == 0 && now.second() <= 3
        || now.hour() == 14 && now.minute() == 15 && now.second() <= 3
        || now.hour() == 14 && now.minute() == 20 && now.second() <= 3
        || now.hour() == 15 && now.minute() == 35 && now.second() <= 3
        || now.hour() == 15 && now.minute() == 40 && now.second() <= 3
        || now.hour() == 16 && now.minute() == 30 && now.second() <= 3
        || now.hour() == 16 && now.minute() == 55 && now.second() <= 3) {
      digitalWrite(2, HIGH);
    }
    else {
      digitalWrite(2, LOW);
  }
  delay(500);
}
}
