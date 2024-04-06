//Uses a ST7735 LCD Display
#include <Wire.h>
#include "Arduino_LED_Matrix.h"
#include <stdint.h>
#include "DHT.h"
#include <SPI.h>
#include <Adafruit_ST7735.h>
#include <Adafruit_ST77xx.h>
#include <Adafruit_GFX.h>
#define DHTTYPE DHT22


unsigned long delayTime = 2500;

//int buzzerpin = 7;
int DHTPin = 2;
int sensorPinA = A0;
int sensorPinD = 4;
int sensorDataD;
int sensorDataA;
//int rainpin = A2;

DHT dht(DHTPin, DHTTYPE);

int rain;
float Humidity;
float Temperature;
float Temp_Fahrenheit;
float hic;

// ST7735 display settings
const int TFT_CS = 10;
const int TFT_DC = 9;
const int TFT_RST = 8;
Adafruit_ST7735 display = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST); //SPI

#define TFT_MOSI 11  // Data out
#define TFT_SCLK 13  // Clock out
//Adafruit_ST7735 display = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);  //No SPI Slow hai

#define BACKGROUND_COLOR  0x000000  // Black
#define TEXT_COLOR        0xFFFFFF  // White
#define HIGHLIGHT_COLOR   0x00FFFF  // Cyan
#define RAIN_COLOR        0x0000FF  // Blue
#define HEAT_INDEX_COLOR  0xFFA500  // Orange
#define GOOD_COLOR  0x00FF00  // Green
#define MODERATE_COLOR 0xFFA500  // Orange
#define POOR_COLOR   0xFF0000  // Red
#define TEXT_INTERESAR_COLOR 0x0000FF // Blue


ArduinoLEDMatrix matrix;

const uint32_t frames[][4] = {
  { 0xe0000000,
    0x0,
    0x0,
    66 },
  { 0x400e0000,
    0x0,
    0x0,
    66 },
  { 0x400e0,
    0x0,
    0x0,
    66 },
  { 0x40,
    0xe000000,
    0x0,
    66 },
  { 0x3000000,
    0x400e000,
    0x0,
    66 },
  { 0x3003000,
    0x400e,
    0x0,
    66 },
  { 0x3003,
    0x4,
    0xe00000,
    66 },
  { 0x3,
    0x300000,
    0x400e00,
    66 },
  { 0x0,
    0x300300,
    0x400e00,
    66 },
  { 0x1c000000,
    0x300,
    0x30400e00,
    66 },
  { 0x401c000,
    0x0,
    0x30430e00,
    66 },
  { 0x401c,
    0x0,
    0x430e30,
    66 },
  { 0x4,
    0x1c00000,
    0x430e30,
    66 },
  { 0x0,
    0x401c00,
    0x430e30,
    66 },
  { 0x800000,
    0x401,
    0xc0430e30,
    66 },
  { 0x800800,
    0x0,
    0x405f0e30,
    66 },
  { 0x800800,
    0x80000000,
    0x470ff0,
    66 },
  { 0x800800,
    0x80080000,
    0x470ff0,
    66 },
  { 0x800,
    0x80080080,
    0x470ff0,
    66 },
  { 0x38000000,
    0x80080080,
    0x8470ff0,
    66 },
  { 0x10038000,
    0x80080,
    0x8478ff0,
    66 },
  { 0x10038,
    0x80,
    0x8478ff8,
    66 },
  { 0x700010,
    0x3800080,
    0x8478ff8,
    66 },
  { 0x400700,
    0x1003880,
    0x8478ff8,
    66 },
  { 0x400,
    0x70001083,
    0x88478ff8,
    66 },
  { 0xf000000,
    0x40070081,
    0x87f8ff8,
    66 },
  { 0xf000,
    0x400f1,
    0x87f8ff8,
    66 },
  { 0x8000000f,
    0xc1,
    0xf7f8ff8,
    66 },
  { 0xc0080000,
    0xf00081,
    0xc7ffff8,
    66 },
  { 0x400c0080,
    0xf81,
    0x87fcfff,
    66 },
  { 0x3400c0,
    0x8000081,
    0xf87fcfff,
    66 },
  { 0x20200340,
    0xc008081,
    0xf87fcfff,
    66 },
  { 0x38220200,
    0x3400c089,
    0xf87fcfff,
    66 },
  { 0x38220,
    0x2003408d,
    0xf8ffcfff,
    66 },
  { 0x86100038,
    0x220240bd,
    0xf8ffcfff,
    66 },
  { 0xec186100,
    0x38260ad,
    0xfbffcfff,
    66 },
  { 0x3ec186,
    0x100078af,
    0xfaffffff,
    66 },
  { 0x114003ec,
    0x186178af,
    0xfaffffff,
    66 },
  { 0x3b411400,
    0x3ec1febf,
    0xfaffffff,
    66 },
  { 0x143b411,
    0x4ec3febf,
    0xfbffffff,
    66 },
  { 0xc040143b,
    0x4fd7febf,
    0xfbffffff,
    66 },
  { 0xc60c0439,
    0x4ff7ffff,
    0xfbffffff,
    66 },
  { 0x33c60f9,
    0x4ff7ffff,
    0xffffffff,
    66 },
  { 0x3cbc33ff,
    0x4ff7ffff,
    0xffffffff,
    66 },
  { 0x8ffbff,
    0x7ff7ffff,
    0xffffffff,
    66 },
  { 0xf0cffbff,
    0xfff7ffff,
    0xffffffff,
    66 },
  { 0xfe1fffff,
    0xffffffff,
    0xffffffff,
    66 },
  { 0xffffffff,
    0xffffffff,
    0xffffffff,
    66 },
  { 0x7fffffff,
    0xffffffff,
    0xfffff7ff,
    66 },
  { 0x3fe7ffff,
    0xffffffff,
    0xff7ff3fe,
    66 },
  { 0x1fc3fe7f,
    0xfffffff7,
    0xff3fe1fc,
    66 },
  { 0xf81fc3f,
    0xe7ff7ff3,
    0xfe1fc0f8,
    66 },
  { 0x500f81f,
    0xc3fe3fe1,
    0xfc0f8070,
    66 },
  { 0x500f,
    0x81fc1fc0,
    0xf8070020,
    66 },
  { 0x5,
    0xf80f80,
    0x70020000,
    66 },
  { 0x5,
    0xa80880,
    0x50020000,
    600 },
  { 0xd812,
    0x41040880,
    0x50020000,
    200 },
  { 0x5,
    0xa80880,
    0x50020000,
    0xFFFFFFFF }
};


/*bool checkForRain() {
  int rainSensorValue = analogRead(rainpin);
  int rainThreshold = 500;
  return rainSensorValue > rainThreshold;
}*/

// Function to read air quality index
int readAirQualityIndex() {
  int sensorDataA = analogRead(sensorPinA);
  digitalWrite(13, sensorDataA > 400 ? HIGH : LOW);
  return sensorDataA;
}

// Function to display air quality information
void displayAirQuality(int airQualityIndex) {
  Serial.print(F("Air Quality Index: "));
  Serial.print(airQualityIndex, DEC);
  Serial.print(" PPM");
  if (airQualityIndex < 500) {
    Serial.println(", Fresh Air");
  } else if (airQualityIndex > 500 && airQualityIndex <= 1000) {
    Serial.println(", Poor Air");
  } else if (airQualityIndex > 1000) {
    Serial.println(", Very Poor Air");
  }
}

// Function to check for gas leak
bool checkForGasLeak() {
  return digitalRead(sensorPinD) == LOW;
}

void displaySensorData() {
  // Set text size for 1.8" display (adjust if needed)
  display.setTextSize(1); 

  int startingY = 4;
  int lineThickness = 2;  // Thickness of horizontal lines in pixels

  // Draw top separator line
  display.fillRect(0, 0, display.width(), lineThickness, TEXT_COLOR);

  // Get bounding box information for "Humidity:" (optional)
  int16_t x1, y1;
  uint16_t w, textHeight;  // Assuming textHeight is unsigned
  display.getTextBounds("Humidity:", 0, 0, &x1, &y1, &w, &textHeight);

  display.setCursor(0, startingY);
  display.setTextColor(TEXT_COLOR);
  display.print("Humidity:");
  display.print(Humidity);
  display.print("%");
  startingY += textHeight * 2;
  display.setCursor(0, startingY);
  display.print("Temp:");
  display.setTextColor(HIGHLIGHT_COLOR);
  display.print(Temperature);
  display.print("C");
  display.setTextColor(TEXT_INTERESAR_COLOR);
  display.print(" (");
  display.print(Temp_Fahrenheit);
  display.print("F)");

  startingY += textHeight * 2.4;  // Adjust spacing based on text height
  display.setCursor(0, startingY);
  display.setTextColor(HEAT_INDEX_COLOR);
  display.print("Heat Index:");
  display.print(hic);
  display.print("C");
  display.setTextColor(rain ? RAIN_COLOR : TEXT_COLOR);
  display.print("  Rain:");
  display.print(rain ? "Detected" : "No");

  // Add spacing based on font size
  startingY += textHeight * 2;

  // Draw bottom separator line
  display.fillRect(0, startingY, display.width(), lineThickness, TEXT_COLOR);

  // Draw separator line between sections
  //display.fillRect(0, startingY - lineThickness, display.width(), lineThickness, TEXT_COLOR);

  // Get bounding box information for "Air Quality:" (optional)
  // ... (similar to "Humidity:")
  startingY += textHeight * 2;
  display.setCursor(0, startingY);
  display.print("Air Quality:");
  display.setTextColor(TEXT_COLOR);
  int airQuality = readAirQualityIndex();
  display.print(airQuality);

  if (airQuality <= 200) {
    display.setTextColor(GOOD_COLOR);
    display.print(" (Good)");
   
  } else if (airQuality <= 500) {
    display.setTextColor(MODERATE_COLOR);
    display.print(" (Moderate)");
   
  } else {
    display.setTextColor(POOR_COLOR);
    display.print(" (Very Poor)");
  }
}


void setup() {
  Serial.begin(9600);
  //pinMode(buzzerpin, OUTPUT);
  pinMode(sensorPinD, INPUT);
  pinMode(DHTPin, INPUT);
  pinMode(sensorPinA, INPUT);
  //pinMode(rainpin, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);

// Initialize ST7735 display
  //display.initR(INITR_BLACKTAB);
  display.initR(INITR_BLACKTAB);
  display.setRotation(3);

  dht.begin();
  matrix.loadSequence(frames);
  matrix.begin();
  matrix.autoscroll(300);
  matrix.play(true);
  delay(100);
}

void loop() {
  display.fillScreen(ST7735_BLACK);
  /*tone(buzzerpin, 1000);
  delay(1000);       
  noTone(buzzerpin);     
  delay(1000); */
  
  /*if (checkForRain()) {
    Serial.println("Rain detected.");
    digitalWrite(LED_BUILTIN, HIGH);
  } else {
    digitalWrite(LED_BUILTIN, LOW);
  }*/

  Humidity = dht.readHumidity();
  Temperature = dht.readTemperature();
  Temp_Fahrenheit = dht.readTemperature(true);
  hic = dht.computeHeatIndex(Temperature, Humidity, false);

  if (isnan(Humidity) || isnan(Temperature) || isnan(Temp_Fahrenheit)) {
    Serial.println(F("Unable to find DHT Sensor. Check Connection!"));
    return;
  }

 // Clear the display


 /* Serial.print(F("Humidity: "));
  Serial.print(Humidity);
  Serial.print(F("%  Temperature: "));
  Serial.print(Temperature);
  Serial.print(F("°C | "));
  Serial.print(Temp_Fahrenheit);
  Serial.print(F("°F Heat index: "));
  Serial.print(hic);
  Serial.println(F("°C "));

  int airQualityIndex = readAirQualityIndex();
  displayAirQuality(airQualityIndex);

  if (checkForGasLeak()) {
    Serial.println("Gas Leak Found");
    Serial.print("AD: ");
    Serial.print(airQualityIndex * 3.3 / 1024);
    Serial.println(" V");
  } else {
    Serial.println("No Gas Leakage");
  }*/
  displaySensorData();
  delay(delayTime);
}

