#include <config.h>
#include <coolant_control.h>
#include <cpu_map.h>
#include <defaults.h>
#include <eeprom.h>
#include <gcode.h>
#include <grbl.h>
#include <jog.h>
#include <limits.h>
#include <motion_control.h>
#include <nuts_bolts.h>
#include <planner.h>
#include <print.h>
#include <probe.h>
#include <protocol.h>
#include <report.h>
#include <serial.h>
#include <settings.h>
#include <sleep.h>
#include <spindle_control.h>
#include <stepper.h>
#include <system.h>


// Fill-in information from your Blynk Template here
#define BLYNK_TEMPLATE_ID "TMPLsT3AjV3d"
#define BLYNK_DEVICE_NAME "Quickstart Template"

#define BLYNK_FIRMWARE_VERSION        "0.1.0"

#define BLYNK_PRINT Serial
//#define BLYNK_DEBUG

#define APP_DEBUG

// Uncomment your board, or configure a custom board in Settings.h
//#define USE_WROVER_BOARD
//#define USE_TTGO_T7

#include "BlynkEdgent.h"
const byte ledint = 2;

void setup()
{
  Serial.begin(115200);
  delay(100);
  pinMode(ledint, OUTPUT);
  BlynkEdgent.begin();
}

void loop() {
  BlynkEdgent.run();
  BLYNK_WRITE(V){
    int state = param.asInt();
    digitalWrite(ledint, state);
  }
}
