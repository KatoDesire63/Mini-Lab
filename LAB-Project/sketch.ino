#include "DHT.h"

#define DHTPIN 4       // GPIO4 for DHT22
#define DHTTYPE DHT22  // DHT22 sensor type
#define GAS_SENSOR_PIN 34 // Analog input for gas sensor

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();
}

void loop() {
  // Read DHT22
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
  } else {
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.print(" °C\tHumidity: ");
    Serial.print(humidity);
    Serial.println(" %");
  }

  //Read Gas Sensor
  int sensorValue = analogRead(GAS_SENSOR_PIN);
  float voltage = sensorValue * (3.3 / 4095.0); // Convert ADC reading to voltage
  Serial.print("Gas Sensor Value: ");
  Serial.print(sensorValue);
  Serial.print(" | Voltage: ");
  Serial.println(voltage);

  delay(2000); // Wait before next reading
}


