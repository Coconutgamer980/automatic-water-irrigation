// Header Files
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
// Variables
#define screen_width 128
#define screen_height 32

Adafruit_SSD1306 display(screen_width, screen_height);

// 1 variables
int relayPin1 = 8;
int sensor_pin1 = A0;
int output_value1;
// 2 variable
int relayPin2 = 12;
int sensor_pin2 = A1;
int output_value2;
// 3 variable
int relayPin3 = 13;
int sensor_pin3 = A2;
int output_value3;
// Bread board
int relayPin4 = 7;

void setup()
{
  SetInputAndOutput_setup();
  delay(0);
}
void loop()
{
  WaterIrrigation_Loop();
  Display_Loop();
}
void WaterIrrigation_Loop()
{
  // 1 value input
  output_value1 = analogRead(sensor_pin1);
  output_value1 = map(output_value1, 550, 10, 0, 100);
  // 2 value input
  output_value2 = analogRead(sensor_pin2);
  output_value2 = map(output_value2, 550, 10, 0, 100);
  // 3 value input
  output_value3 = analogRead(sensor_pin3);
  output_value3 = map(output_value3, 550, 10, 0, 100);

  Serial.print(output_value1);
  Serial.print("|");
  Serial.print(output_value2);
  Serial.print("|");
  Serial.print(output_value3);
  Serial.println("|");

  // 1
  if (output_value1 < 20)
  {
    digitalWrite(relayPin1, HIGH);
  }
  else
  {
    digitalWrite(relayPin1, LOW);
  }
  // 2
  if (output_value2 < 20)
  {
    digitalWrite(relayPin2, HIGH);
  }
  else
  {
    digitalWrite(relayPin2, LOW);
  }
  // 3
  if (output_value3 < 20)
  {
    digitalWrite(relayPin3, HIGH);
  }
  else
  {
    digitalWrite(relayPin3, LOW);
  }
  if (output_value1 < 20 || output_value2 < 20 || output_value3 < 20)
  {
    digitalWrite(relayPin4, HIGH);
  }
  else
  {
    digitalWrite(relayPin4, LOW);
  }

  delay(500);
}
void Display_Loop()
{
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println(output_value1);
  display.setCursor(0, 10);
  display.println(output_value2);
  display.setCursor(0, 20);
  display.println(output_value3);
  display.display();
}
void SetInputAndOutput_setup()
{
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  Serial.begin(9600);

  // 1 input and output
  pinMode(relayPin1, OUTPUT);
  pinMode(sensor_pin1, INPUT);
  // 2 input and output
  pinMode(relayPin2, OUTPUT);
  pinMode(sensor_pin2, INPUT);
  // 3 input and output
  pinMode(relayPin3, OUTPUT);
  pinMode(sensor_pin3, INPUT);
}
