#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET          A4

#define SSD1306_WHITE 1
#define SSD1306_BLACK 0
#define SSD1306_INVERSE 2

Adafruit_SSD1306 display(OLED_RESET);

int analogInput = A1;  //Sensor Input

void setup() {
  pinMode(analogInput, INPUT);

  Serial.begin(9600);
  Serial.println("VOLTMETER");

  display.begin();

  
  display.clearDisplay();

  display.display();

  display.drawRect(0, 0,  128 , 12, SSD1306_WHITE);
  display.setTextColor(SSD1306_WHITE, SSD1306_BLACK);
  display.setTextSize(1);
  display.setCursor(18, 3);
  display.println("    VOLTMETER   ");
  display.display();
}

float vout = 0.0;
float vin = 0.0;

float R1 = 30000.0;
float R2 = 7500.0;

int value = 0;

void loop() {

  value = analogRead(analogInput);
  vout = (value * 5.0) / 1024.0;
  vin = vout / (R2 / (R1 + R2));

  Serial.print("INPUT Voltage= ");
  Serial.println(vin, 2);

  display.setTextSize(2);
  display.setCursor(20, 15);
  display.println(vin, 2);
  display.setCursor(80, 15);
  display.println("V");
  display.display();

  delay(1000);


}
