//Uses a 0.96 Yellow-Blue OLED Display Driver IC: SSD1306
#include "Arduino_LED_Matrix.h"
#include <stdint.h>
#include "DHT.h"
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <WiFiS3.h>
#include <ArduinoHttpClient.h>
#include "secret.h"

#define DHTTYPE DHT22

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

unsigned long delayTime = 2500;

//int buzzerpin = 8;
int DHTPin = 2;
int sensorPinA = A0;
int sensorPinD = 4;
int sensorDataD;
int sensorDataA;
int rainpin = 7;

DHT dht(DHTPin, DHTTYPE);

int rain;
float Humidity;
float Temperature;
float Temp_Fahrenheit;
float hic;
int rainSensorValue;

const char* ssid = SECRET_SSID;
const char* password = SECRET_PASS;

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


bool checkForRain() {
  rainSensorValue = digitalRead(rainpin);
  //rainSensorValue = analogRead(rainpin);
  //int rainThreshold = 500;
  //return rainSensorValue > rainThreshold;
  return rainSensorValue < 1; // Shows 1 if not raining, 0 if raining.
}

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
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  // Display humidity
  display.setCursor(0, 0);
  display.print("Humidity:");
  display.print(Humidity);
  display.println("%");

  // Display temperature
  display.print("Temp:");
  display.print(Temperature);
  display.print((char)247); // Degree symbol
  display.print("C (");
  display.print(Temp_Fahrenheit);
  display.println("F)");

  // Display heat index
  display.print("Heat Index:");
  display.print(hic);
  display.print((char)247); // Degree symbol
  display.println("C");


  // Air quality section
  display.print("Air Quality:");
  int airQuality = readAirQualityIndex();
  display.print(airQuality);

  if (airQuality <= 200) {
    display.println(" Good");
  } else if (airQuality <= 500) {
    display.println(" Mid");
  } else {
    display.println(" Poor");
  }

  // Display rain detection
  display.print("Raining:");
  display.println(checkForRain() ? "Yes" : "No");

  display.display();
}


void setup() {
  Serial.begin(9600);

  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

   WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }
  Serial.println("Connected to the WiFi network");

  display.display();
  delay(2000); // Pause for 2 seconds

  //pinMode(buzzerpin, OUTPUT);
  pinMode(sensorPinD, INPUT);
  pinMode(DHTPin, INPUT);
  pinMode(sensorPinA, INPUT);
  pinMode(rainpin, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);

  dht.begin();
  matrix.loadSequence(frames);
  matrix.begin();
  matrix.autoscroll(300);
  matrix.play(true);
  delay(100);

}

void loop() {
  /*tone(buzzerpin, 1000);
  delay(1000);       
  noTone(buzzerpin);     
  delay(1000); */
  
  if (checkForRain()) {
    Serial.println("Rain detected.");
    digitalWrite(LED_BUILTIN, HIGH);
  } else {
    digitalWrite(LED_BUILTIN, LOW);
  }

  Humidity = dht.readHumidity();
  Temperature = dht.readTemperature();
  Temp_Fahrenheit = dht.readTemperature(true);
  hic = dht.computeHeatIndex(Temperature, Humidity, false);

  if (isnan(Humidity) || isnan(Temperature) || isnan(Temp_Fahrenheit)) {
    Serial.println(F("Unable to find DHT Sensor. Check Connection!"));
    return;
  }

  Serial.print(F("Humidity: "));
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
  }
  
  Serial.print(rainSensorValue);
  Serial.println(F(" Rain "));

  displaySensorData();
  delay(delayTime);
}


