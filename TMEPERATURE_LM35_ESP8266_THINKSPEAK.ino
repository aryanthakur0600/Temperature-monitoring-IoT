#include <ESP8266WiFi.h>;
#include <WiFiClient.h>;
#include <ThingSpeak.h>;

const char* ssid = "the_wifi";   // Your Network SSID
const char* password = "the_wifi_password";       // Your Network Password

int val;
int pin = A0; // LM35 Pin Connected at A0 Pin

WiFiClient client;

unsigned long myChannelNumber = 1835889; //Your Channel Number (Without Brackets)
const char * myWriteAPIKey = "UAL3SCN4H2806ES9"; //Your Write API Key

void setup()
{
  Serial.begin(115200);
  delay(10);
  // Connect to WiFi network
  WiFi.begin(ssid, password);
  ThingSpeak.begin(client);
}

void loop()
{
  val = analogRead(pin)*(3.3/1023); // Read Analog values and Store in val variable 
  Serial.print("Temperature: ");
  Serial.print(val); 
   Serial.println("*C");
   Serial.println(analogRead(A0)); 
  // Print on Serial Monitor
 
  delay(1000);
  ThingSpeak.writeField(myChannelNumber, 1,val, myWriteAPIKey); //Update in ThingSpeak
  delay(100);
}
