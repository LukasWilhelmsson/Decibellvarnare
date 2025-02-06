/*
* Name: Decibellvarnare
* Author: Lukas.Wilhelmsson
* Date: 06/02-2025
* Description: Decibellvarnaren is a mikrophon that checks if the voljum in the suroundings is "too loud" by chenging the collor that shines in a ring light thats conected, from green to red to yellow.
*/
// include liabery
#include <Adafruit_NeoPixel.h>
// Init constants

// Init global variables
#define NEOPIXEL_PIN 6
#define NUM_PIXELS 24
#define MIC_PIN A0

// Construct objects
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_PIXELS, NEOPIXEL_PIN, NEO_GRB + NEO_KHZ800);

uint32_t green = strip.Color(0, 255, 0);
uint32_t yellow = strip.Color(255, 255, 0);
uint32_t red = strip.Color(255, 0, 0);

void setup() {

 // init communication
 Serial.begin(9600);

 // init hardware
 strip.begin();
 strip.show();
}

/* This funktion reads the value from the KY-037 microphon and makes it to an int, then I got Serial.println to read from soundLevel to se the change in Serial Plotter.
* Then a for loop checks if i is bigger then the amount of light diods with NUM_PIXELS and afterwerds makes i+1 so that more and more lights shine.
* Then it checks if soundlevel is bigger then the inserted threeshwhold, if it is the ligt tern red if not it checks yellows threshwhold if it is then yellow light if not then the ligt terns green.
*/
void loop() {

 int soundLevel = analogRead(MIC_PIN);

 Serial.println(soundLevel);
 
 for (int i = 0; i < NUM_PIXELS; i++) {
    if (soundLevel > 90) {
  strip.setPixelColor(i, red);
    } else if (soundLevel > 75) {
  strip.setPixelColor(i, yellow);
    } else {
  strip.setPixelColor(i, green);
    } // går att ändra enkelt vid behov
 }

 // delay
 strip.show();
 delay(50);
 // delay
 Serial.println(soundLevel);
 delay(100);
}
