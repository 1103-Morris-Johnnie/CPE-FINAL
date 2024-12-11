#include <Wire.h>
#include <LiquidCrystal.h>
#include <DHT.h>
#include <RTClib.h>

#define DHTPIN 2
#define DHTTYPE DHT11
#define FAN_PIN 9
#define START_BUTTON_PIN 3
#define RESET_BUTTON_PIN 4
#define STOP_BUTTON_PIN 5
#define WATER_SENSOR_PIN A0
#define LED_YELLOW 10
#define LED_GREEN 11
#define LED_RED 12
#define LED_BLUE 13

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
DHT dht(DHTPIN, DHTTYPE);
RTC_DS1307 rtc;

enum CoolerState { DISABLED, IDLE, ERROR, RUNNING };
CoolerState currentState = DISABLED;
float tempThresholdHigh = 23;
float tempThresholdLow = 22;
bool waterLow = false;

void setup() {
  lcd.begin(16, 2);
  dht.begin();
  rtc.begin();

  pinMode(FAN_PIN, OUTPUT);
  pinMode(START_BUTTON_PIN, INPUT_PULLUP);
  pinMode(RESET_BUTTON_PIN, INPUT_PULLUP);
  pinMode(STOP_BUTTON_PIN, INPUT_PULLUP);
  pinMode(WATER_SENSOR_PIN, INPUT);

  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);

  digitalWrite(LED_YELLOW, HIGH);
  lcd.print("System Disabled");
  Serial.begin(9600);
  Serial.println("System Initialized");
}

void loop() {
  Serial.println("Entering loop...");

  switch (currentState) {
    case DISABLED:
      handleDisabledState();
      break;
    case IDLE:
      handleIdleState();
      break;
    case ERROR:
      handleErrorState();
      break;
    case RUNNING:
      handleRunningState();
      break;
  }
  delay(3000);
  Serial.print("Current State: ");
  Serial.println(currentState);
}

void handleDisabledState() {
  Serial.println("State: DISABLED");
  digitalWrite(LED_YELLOW, HIGH);
  digitalWrite(LED_GREEN, LOW);
  digitalWrite(LED_RED, LOW);
  digitalWrite(LED_BLUE, LOW);

  if (digitalRead(START_BUTTON_PIN) == HIGH) {
    currentState = IDLE;
    logEvent("2");
    Serial.println("Transition to IDLE");
  }
}

void handleIdleState() {
  Serial.println("State: IDLE");

  digitalWrite(LED_YELLOW, LOW);
  digitalWrite(LED_GREEN, HIGH);
  digitalWrite(LED_RED, LOW);
  digitalWrite(LED_BLUE, LOW);

  float temp = dht.readTemperature();
  float humidity = dht.readHumidity();
  int waterLevel = analogRead(WATER_SENSOR_PIN);

  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.print(" C, Humidity: ");
  Serial.print(humidity);
  Serial.print("%, Water level: ");
  Serial.println(waterLevel);

  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temp);
  lcd.print(" C");
  lcd.setCursor(0, 1);
  lcd.print("Humidity: ");
  lcd.print(humidity);
  lcd.print("%");

  if (waterLevel < 50) {
    waterLow = true;
    currentState = ERROR;
    logEvent("1.5");
    Serial.println("Error: Water Level Low");
  }

  if (temp > tempThresholdHigh) {
    currentState = RUNNING;
    logEvent("Transition to RUNNING");
    Serial.println("Transition to RUNNING");
  }

  if (digitalRead(STOP_BUTTON_PIN) == HIGH) {
    currentState = DISABLED;
    logEvent("Transition to DISABLED");
    Serial.println("Transition to DISABLED");
  }
}

void handleErrorState() {
  Serial.println("State: ERROR");

  digitalWrite(LED_YELLOW, LOW);
  digitalWrite(LED_GREEN, LOW);
  digitalWrite(LED_RED, HIGH);
  digitalWrite(LED_BLUE, LOW);

  lcd.clear();
  lcd.print("Error: Water Low");

  if (digitalRead(RESET_BUTTON_PIN) == HIGH) {
      waterLow = false;
      currentState = IDLE;
      logEvent("Transition to IDLE");
      Serial.println("Transition to IDLE (Reset)");
      digitalWrite(LED_RED, LOW);
  }

  int waterLevel = analogRead(WATER_SENSOR_PIN);
  if (waterLevel > 50) {
      waterLow = false;
      currentState = IDLE;
      logEvent("Transition to IDLE");
      Serial.println("Transition to IDLE (Reset)");
      digitalWrite(LED_RED, LOW);
  }
}

void handleRunningState() {
  Serial.println("State: RUNNING");

  digitalWrite(LED_YELLOW, LOW);
  digitalWrite(LED_GREEN, LOW);
  digitalWrite(LED_RED, LOW);
  digitalWrite(LED_BLUE, HIGH);

  float temp = dht.readTemperature();
  int waterLevel = analogRead(WATER_SENSOR_PIN);

  Serial.print("Temperature (Running State): ");
  Serial.print(temp);
  Serial.print(" C, Water level: ");
  Serial.println(waterLevel);

  if (temp < tempThresholdLow) {
    currentState = IDLE;
    logEvent("Transition to IDLE");
    Serial.println("Transition to IDLE (Temperature too low)");
  }
  if (temp > tempThresholdHigh) {
    digitalWrite(FAN_PIN, HIGH);
  }

  if (waterLevel < 50) {
    waterLow = true;
    currentState = ERROR;
    logEvent("Transition to ERROR");
    Serial.println("Error: Water Level Low (During Running)");
  }
}

void logEvent(String event) {
  DateTime now = rtc.now();
  Serial.print("[");
  Serial.print(now.timestamp());
  Serial.print("] ");
  Serial.println(event);
}
