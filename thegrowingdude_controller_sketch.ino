
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SC16IS750.h>
#include <string.h>
#include <NDIRZ16.h>
#include <DHT.h>
#include <SHT1x.h>
#include "RTClib.h"
#include <Ethernet.h>
#include <PubSubClient.h>

// Update these with values suitable for your network.
byte mac[]    = {  0xDE, 0xED, 0xBA, 0xFE, 0xFE, 0xED };
IPAddress ip(192,168,1,187);
IPAddress server(192,168,1,186);

//Data PIN Assignments
const int switchPin1 = 18;
const int switchPin2 = 17;
const int switchPin3 = 16;
const int switchPin4 = 15;
const int switchPin5 = 14;
const int switchPin6 = 2;
const int switchPin7 = 3;
const int switchPin8 = 5;

SC16IS750 i2cuart = SC16IS750(SC16IS750_PROTOCOL_I2C, SC16IS750_ADDRESS_BB);
NDIRZ16 mySensor = NDIRZ16(&i2cuart);

RTC_DS1307 rtc;

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2

#define DHTPIN 47     // what digital pin we're connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
DHT dht(DHTPIN, DHTTYPE);

// Specify data and clock connections and instantiate SHT1x object
#define dataPin  25
#define clockPin 24
SHT1x sht1x(dataPin, clockPin);

#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

void callback(char* topic, byte* payload, unsigned int length) {
//convert topic to string to make it easier to work with
 String topicStr = topic; 
 Serial.print("Message arrived [");
 Serial.print(topicStr);
 Serial.print("] ");

 //relay mapping
 if (topicStr == "garden/1")
 for (int i=0;i<length;i++) {
  char receivedChar = (char)payload[i];
  Serial.print(receivedChar);
  if (receivedChar == '0')
  digitalWrite(switchPin1, HIGH);
  if (receivedChar == '1')
   digitalWrite(switchPin1, LOW);
  }
  Serial.println();

   //relay mapping
 if (topicStr == "garden/1")
 for (int i=0;i<length;i++) {
  char receivedChar = (char)payload[i];
  Serial.print(receivedChar);
  if (receivedChar == '0')
  digitalWrite(switchPin1, HIGH);
  if (receivedChar == '1')
   digitalWrite(switchPin1, LOW);
  }
  Serial.println();

   //relay mapping
 if (topicStr == "garden/2")
 for (int i=0;i<length;i++) {
  char receivedChar = (char)payload[i];
  Serial.print(receivedChar);
  if (receivedChar == '0')
  digitalWrite(switchPin2, HIGH);
  if (receivedChar == '1')
   digitalWrite(switchPin2, LOW);
  }
  Serial.println();

   //relay mapping
 if (topicStr == "garden/3")
 for (int i=0;i<length;i++) {
  char receivedChar = (char)payload[i];
  Serial.print(receivedChar);
  if (receivedChar == '0')
  digitalWrite(switchPin3, HIGH);
  if (receivedChar == '1')
   digitalWrite(switchPin3, LOW);
  }
  Serial.println();

   //relay mapping
 if (topicStr == "garden/4")
 for (int i=0;i<length;i++) {
  char receivedChar = (char)payload[i];
  Serial.print(receivedChar);
  if (receivedChar == '0')
  digitalWrite(switchPin4, HIGH);
  if (receivedChar == '1')
   digitalWrite(switchPin4, LOW);
  }
  Serial.println();

   //relay mapping
 if (topicStr == "garden/5")
 for (int i=0;i<length;i++) {
  char receivedChar = (char)payload[i];
  Serial.print(receivedChar);
  if (receivedChar == '0')
  digitalWrite(switchPin5, HIGH);
  if (receivedChar == '1')
   digitalWrite(switchPin5, LOW);
  }
  Serial.println();

   //relay mapping
 if (topicStr == "garden/6")
 for (int i=0;i<length;i++) {
  char receivedChar = (char)payload[i];
  Serial.print(receivedChar);
  if (receivedChar == '0')
  digitalWrite(switchPin6, HIGH);
  if (receivedChar == '1')
   digitalWrite(switchPin6, LOW);
  }
  Serial.println();

   //relay mapping
 if (topicStr == "garden/7")
 for (int i=0;i<length;i++) {
  char receivedChar = (char)payload[i];
  Serial.print(receivedChar);
  if (receivedChar == '0')
  digitalWrite(switchPin7, HIGH);
  if (receivedChar == '1')
   digitalWrite(switchPin7, LOW);
  }
  Serial.println();

     //relay mapping
 if (topicStr == "garden/8")
 for (int i=0;i<length;i++) {
  char receivedChar = (char)payload[i];
  Serial.print(receivedChar);
  if (receivedChar == '0')
  digitalWrite(switchPin8, HIGH);
  if (receivedChar == '1')
   digitalWrite(switchPin8, LOW);
  }
  Serial.println();
  
  
}

EthernetClient ethClient;
PubSubClient client(ethClient);

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect("arduinoClient")) {
      Serial.println("connected");
      // Once connected, publish an announcement...
      client.publish("garden/debug","hello world -thegrowingdude");
      // ... and resubscribe
      client.subscribe("garden/1");
      client.subscribe("garden/2");
      client.subscribe("garden/3");
      client.subscribe("garden/4");
      client.subscribe("garden/5");
      client.subscribe("garden/6");
      client.subscribe("garden/7");
      client.subscribe("garden/8");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void setup()   {
  Serial.begin(115200);
  //info for mqtt sercer 
  client.setServer(server, 1883);
  //settings for mqtt 
  client.setCallback(callback);
  //start etherenet interface
  Ethernet.begin(mac, ip);
  // Allow the hardware to sort itself out
  delay(1500);
  
//  while (!Serial);             // Leonardo: wait for serial monitor
  dht.begin();
  i2cuart.begin(9600);

// if (i2cuart.ping()) {
//   Serial.println("CO2 sensor found, wait 10 seconds for sensor initialization...");
//  } else {
//    Serial.println("CO2 sensor not found.");
//    while (1);
//  }

  power(1);
  //Wait for the NDIR sensor to initialize.
  delay(10000);


    display.begin(SSD1306_SWITCHCAPVCC, 0x3c);
    display.clearDisplay();
    display.setRotation(2);

}


void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
  
  float temp_c;
  float temp_f;
  float humidity;

  
  DateTime now = rtc.now();

  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Read values from the SHT11 sensor
  temp_c = sht1x.readTemperatureC();
  temp_f = sht1x.readTemperatureF();
  humidity = sht1x.readHumidity();


  if (mySensor.measure()) {

    display.clearDisplay();
    display.setTextSize(1);
    display.setCursor(0, 0);
    display.setTextColor(WHITE);
    display.print("@thegrowingdude ");
    display.print(now.hour(), DEC);
    display.print(':');
    display.println(now.minute(), DEC);
    display.println();
    display.print("CO/2: ");
    display.print(mySensor.ppm);
    display.println(" PPM");
    display.print("RelH: ");
    display.print(h, 0);
    display.print("/");
    display.print(humidity, 0);
    display.println(" %");
    display.print("Temp: ");
    display.print(f, 0);
    display.print("/");
    display.print(temp_f, 0);
    display .println(" F");
    display.print("Temp/ppm: ");
    display.print(mySensor.temperature);
    display .println(" C");
    display.setTextColor(BLACK, WHITE); // 'inverted' text
    display.println("Controller 1.\2");
    display.display();
    Serial.print("@thegrowingdude ");
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.println(now.minute(), DEC);
    Serial.println();
    Serial.print("CO/2:  ");
    Serial.print(mySensor.ppm);
    Serial.println(" PPM");
    Serial.print("RelH: ");
    Serial.print(h, 0);
    Serial.print("/");
    Serial.print(humidity, 0);
    Serial.println(" %");
    Serial.print("Temp: ");
    Serial.print(f, 0);
    Serial.print("/");
    Serial.print(temp_f, 0);
    Serial .println(" F");
    Serial.println();


 //mqtt posts
  char buffer[10];
  dtostrf(temp_f,0, 0, buffer);
  client.publish("garden/temp",buffer);
 
  dtostrf(mySensor.ppm,0, 0, buffer);
  client.publish("garden/ppm",buffer);


  dtostrf(humidity,0, 0, buffer);
  client.publish("garden/RH",buffer);

  
  
     } else {
    Serial.println("Sensor communication error.");
  }
  delay(200);
}

//Power control function for NDIR sensor. 1=ON, 0=OFF
void power (uint8_t state) {
  i2cuart.pinMode(0, INPUT);      //set up for the power control pin

  if (state) {
    i2cuart.pinMode(0, INPUT);  //turn on the power of MH-Z16
  } else {
    i2cuart.pinMode(0, OUTPUT);
    i2cuart.digitalWrite(0, 0); //turn off the power of MH-Z16
  }

}

