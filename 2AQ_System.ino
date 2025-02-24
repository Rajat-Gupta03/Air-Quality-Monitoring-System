#define BLYNK_TEMPLATE_ID "TMPL3mFDHincE"
#define BLYNK_TEMPLATE_NAME "Air Quality Monitoring"
#define BLYNK_AUTH_TOKEN "uC6nDpkS-p-H-pizQXimqAus9HNc5lIt"

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128    // OLED display width, in pixels
#define SCREEN_HEIGHT 64    // OLED display height, in pixels
#define OLED_RESET -1  // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = ""; // type your wifi name
char pass[] = "";       // type your wifi password

BlynkTimer timer;

int gas = A0;
int sensorThreshold = 100;
int buzzerPin = D6;

#define DHTPIN 2 //Connect Out pin to D2 in NODE MCU
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void sendSensor()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature(); // or dht.readTemperature(true) for Fahrenheit

  if (isnan(h) || isnan(t))
  {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  int analogSensor = analogRead(gas);
  Blynk.virtualWrite(V2, analogSensor);
  Serial.print("Gas Value: ");
  Serial.println(analogSensor);
  // You can send any value at any time.
  // Please don't send more than 10 values per second.
  Blynk.virtualWrite(V0, t);
  Blynk.virtualWrite(V1, h);

  Serial.print("Temperature : ");
  Serial.print(t);
  Serial.print("    Humidity : ");
  Serial.println(h);
}

void setup()
{
  Serial.begin(115200);

  Blynk.begin(auth, ssid, pass);
  dht.begin();
  timer.setInterval(5000L, sendSensor);

  lcd.begin(16, 2);

  lcd.setCursor(3, 0);
  lcd.print("Air Quality");
  lcd.setCursor(3, 1);
  lcd.print("Monitoring");
  delay(2000);
  lcd.clear();

  pinMode(buzzerPin, OUTPUT);
}

void loop()
{
  Blynk.run();
  timer.run();
  float h = dht.readHumidity();
  float t = dht.readTemperature(); // or dht.readTemperature(true) for Fahrenheit
  int gasValue = analogRead(gas);
  lcd.setCursor(0, 0);
  lcd.print("Temperature ");
  lcd.setCursor(0, 1);
  lcd.print(t);
  lcd.setCursor(6, 1);
  lcd.write(1);
  lcd.createChar(1, degree_symbol);
  lcd.setCursor(7, 1);
  lcd.print("C");
  delay(4000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Humidity ");
  lcd.print(h);
  lcd.print("%");
  delay(4000);
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Gas Value: ");
  lcd.print(gasValue);

  // Categorize air quality based on gas value
  if (gasValue >= 0 && gasValue <= 50)
  {
    lcd.setCursor(0, 1);
    lcd.print("Good Air");
    Serial.println("Good Air");
   
  }
  else if (gasValue >= 51 && gasValue <= 100)
  {
    lcd.setCursor(0, 1);
    lcd.print("Moderate Air");
    Serial.println("Moderate Air");
    
  }
  else if (gasValue >= 101 && gasValue <= 150)
  {
    lcd.setCursor(0, 1);
    lcd.print("Unhealthy Air");
    Serial.println("Unhealthy Air");
  }
  else if (gasValue >= 151 && gasValue <= 200)
  {
    lcd.setCursor(0, 1);
    lcd.print("Bad Air");
    Serial.println("Bad Air");
     //Sound the buzzer
    digitalWrite(buzzerPin, HIGH);
    delay(3000);
    digitalWrite(buzzerPin, LOW);
    
  }

  delay(4000);
  lcd.clear();

  if (gasValue > 200)
  {
    // Blynk.email("your_email@example.com", "Alert", "Very Bad Air!");
    Blynk.logEvent("pollution_alert", "Very Bad Air");
  }
}
