//This example code is in the Public Domain (or CC0 licensed, at your option.)
//By Evandro Copercini - 2018
//
//This example creates a bridge between Serial and Classical Bluetooth (SPP)
//and also demonstrate that SerialBT have the same functionalities of a normal Serial

#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

#if !defined(CONFIG_BT_SPP_ENABLED)
#error Serial Bluetooth not available or not enabled. It is only available for the ESP32 chip.
#endif
BluetoothSerial SerialBT;
int received;
String receivedChar;
String FClases;
String FVacas;
const char ConfigC ='A';
const char ConfigV ='B';
const char Ver ='C';
const int LEDpin = 15;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32test"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
   pinMode(LEDpin, OUTPUT);
}

void loop() {
    receivedChar =SerialBT.readStringUntil('\n');

  if (Serial.available()) {
    SerialBT.write(Serial.read());
  
  }
  if (SerialBT.available()) {
    
//    SerialBT.print(receivedChar);// write on BT app   
    Serial.print(receivedChar);//print on serial monitor    
    if(receivedChar == "A")
    {
      FClases =SerialBT.readStringUntil('\n');
//     SerialBT.println("LED ON:");// write on BT app
//     Serial.println("LED ON:");//write on serial monitor
     digitalWrite(LEDpin, HIGH);// turn the LED ON
       
    }
    if(receivedChar == "B")
    {
      FVacas =SerialBT.readStringUntil('\n');
//     SerialBT.println("LED OFF:");// write on BT app
//     Serial.println("LED OFF:");//write on serial monitor
     digitalWrite(LEDpin, LOW);// turn the LED off 
    }
    if(receivedChar == "C")
    {
    Serial.println(FVacas);
    Serial.println(FClases);
    }   
  }
  delay(20);
}
