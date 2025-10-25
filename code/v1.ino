#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11
#define RELAY_PIN 9
#define BUZZER_PIN 8

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

DHT dht(DHTPIN, DHTTYPE);

const float FAN_ON_TEMP = 30.0;
const float BUZZER_ON_TEMP = 40.0;

// 4 fan animation frames
const unsigned char PROGMEM fanFrames[4][24] = {
  {0b00000000,0b00000000,0b00000000,
   0b00011000,0b00011000,0b00000000,
   0b00001000,0b00111000,0b00010000,
   0b00000100,0b11111100,0b00100000,
   0b00000011,0b11111111,0b11000000,
   0b00000001,0b11111111,0b10000000,
   0b00000000,0b01111110,0b00000000},

  {0b00000000,0b00000000,0b00000000,
   0b00010000,0b00000010,0b00010000,
   0b00001000,0b00000100,0b00100000,
   0b00000100,0b00001000,0b01000000,
   0b00000010,0b00010000,0b10000000,
   0b00000100,0b00100001,0b00000000,
   0b00001000,0b01000010,0b00000000},

  {0b00000000,0b00000000,0b00000000,
   0b00000000,0b01111110,0b00000000,
   0b00000001,0b11111111,0b10000000,
   0b00000011,0b11111111,0b11000000,
   0b00000100,0b11111100,0b00100000,
   0b00001000,0b00111000,0b00010000,
   0b00011000,0b00011000,0b00000000},

  {0b00000000,0b00000000,0b00000000,
   0b00001000,0b01000010,0b00000000,
   0b00000100,0b00100001,0b00000000,
   0b00000010,0b00010000,0b10000000,
   0b00000100,0b00001000,0b01000000,
   0b00001000,0b00000100,0b00100000,
   0b00010000,0b00000010,0b00010000}
};

// small °C symbol bitmap (7x7)
const unsigned char PROGMEM degreeCBitmap[] = {
  0b01110000,
  0b10001000,
  0b10000000,
  0b10000000,
  0b10001000,
  0b01110000,
  0b00000000
};

int frame = 0;

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH);
  digitalWrite(BUZZER_PIN, LOW);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED init failed");
    while (1);
  }

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);
  display.setCursor(20, 25);
  display.println("Smart Temp Room");
  display.display();
  delay(1500);
}

void loop() {
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  if (isnan(temp) || isnan(hum)) {
    Serial.println("Sensor fail");
    delay(1000);
    return;
  }

  bool fanOn = false;
  bool alarmOn = false;

  const int RELAY_ON = LOW;
  const int RELAY_OFF = HIGH;

  if (temp >= BUZZER_ON_TEMP) {
    digitalWrite(RELAY_PIN, RELAY_ON);
    digitalWrite(BUZZER_PIN, HIGH);
    fanOn = true;
    alarmOn = true;
  } else if (temp >= FAN_ON_TEMP) {
    digitalWrite(RELAY_PIN, RELAY_ON);
    digitalWrite(BUZZER_PIN, LOW);
    fanOn = true;
  } else {
    digitalWrite(RELAY_PIN, RELAY_OFF);
    digitalWrite(BUZZER_PIN, LOW);
  }

  // ===== OLED DISPLAY SECTION =====
  display.clearDisplay();

  // Highlight box behind header
  display.fillRect(0, 0, 128, 10, SSD1306_WHITE);
  display.setTextColor(SSD1306_BLACK);
  display.setCursor(2, 1);
  display.print("TEMP ROOM | ");
  display.print(fanOn ? "FAN ON" : "FAN OFF");
  display.setTextColor(SSD1306_WHITE);

  // Highlight for temperature reading
  display.fillRect(0, 15, 70, 22, SSD1306_WHITE);
  display.setTextColor(SSD1306_BLACK);
  display.setTextSize(2);
  display.setCursor(4, 18);
  display.print(temp, 1);

  // Custom °C symbol
  display.drawBitmap(54, 18, degreeCBitmap, 7, 7, SSD1306_BLACK);
  display.setTextColor(SSD1306_BLACK);
  display.setCursor(62, 18);
  display.setTextSize(1);
  display.print("C");
  display.setTextColor(SSD1306_WHITE);

  // Humidity text
  display.setTextSize(1);
  display.setCursor(0, 42);
  display.print("Humidity: ");
  display.print(hum, 0);
  display.print("%");

  // Thermometer bar (right side)
  int barHeight = map(temp, 0, 50, 0, 40);
  display.drawRect(110, 20, 10, 40, SSD1306_WHITE);
  display.fillRect(110, 60 - barHeight, 10, barHeight, SSD1306_WHITE);

  // Fan animation
  if (fanOn) {
    display.drawBitmap(85, 25, fanFrames[frame], 24, 7, SSD1306_WHITE);
    frame = (frame + 1) % 4;
  } else {
    display.drawBitmap(85, 25, fanFrames[0], 24, 7, SSD1306_WHITE);
  }

  // Comfort message
  display.setCursor(0, 55);
  if (temp < 25) display.print("Comfort: Cool");
  else if (temp < 35) display.print("Comfort: Warm");
  else display.print("Comfort: Hot");

  // Alert if temp too high
  if (alarmOn) {
    display.fillRect(75, 53, 50, 10, SSD1306_WHITE);
    display.setTextColor(SSD1306_BLACK);
    display.setCursor(80, 55);
    display.print("!! ALERT !!");
    display.setTextColor(SSD1306_WHITE);
  }

  display.display();
  delay(150);
}
