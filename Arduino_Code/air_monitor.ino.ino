#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define DHTPIN 2           // Pin connected to DHT11
#define DHTTYPE DHT11      // DHT11 sensor type
#define MQ135_PIN A0       // Analog pin for MQ135

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2); // Set the LCD address to 0x27 for a 16x2 LCD

unsigned long lastUpdate = 0;
int displayToggle = 0;

void setup() {
  Serial.begin(9600);
  dht.begin();
  lcd.init();
  lcd.backlight();

 lcd.setCursor(0, 0);    // Display initial message
  lcd.print("monitoring data");
  delay(2000);
  lcd.clear();
}

void loop() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  int mq135_value = analogRead(MQ135_PIN);

  // Check if the sensor values are valid
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
    lcd.clear();
    lcd.print("DHT Error!");
    return;
  }

  // Determine air quality status
  String airQualityStatus;
  if (mq135_value < 50) {
    airQualityStatus = "low,Good";
  } else if (mq135_value < 100) {
    airQualityStatus = "Moderate";
  } else {
    airQualityStatus ="poor";
  }

  // Update the display every 3 seconds
  if (millis() - lastUpdate >= 3000) {
    lastUpdate = millis();
    lcd.clear();
    if (displayToggle == 0) {
      // Display Air Quality and Status
      lcd.setCursor(0, 0);
      lcd.print("Air quality: ");
      lcd.print(mq135_value);
      lcd.setCursor(0, 1);
      lcd.print("Status: ");
      lcd.print(airQualityStatus);
      displayToggle = 1;  // Switch to temperature and humidity on next update
    } else {
      // Display Temperature and Humidity
      lcd.setCursor(0, 0);
      lcd.print("Temp: ");
      lcd.print(temperature);
      lcd.print(" C");

      lcd.setCursor(0, 1);
      lcd.print("Humid: ");
      lcd.print(humidity);
      lcd.print(" %");
      displayToggle = 0;  // Switch back to AQI on next update
    }
  }

  // Log data to Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C, Humidity: ");
  Serial.print(humidity);
  Serial.print(" %, Air Quality: ");
  Serial.print(mq135_value);
  Serial.print(" (");
  Serial.print(airQualityStatus);
  Serial.println(")");
}
