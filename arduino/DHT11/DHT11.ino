#include <ESP8266WiFi.h>
#include "DHT.h"        // including the library of DHT11 temperature and humidity sensor
#define DHTTYPE DHT11   // DHT 11
#define dht_dpin D1

WiFiClient client;
String req;
const char* server = "10.100.5.1";
const char* ssid     = "4ldioT - 2";         // The SSID (name) of the Wi-Fi network you want to connect to
const char* password = "sembarang123";     // The password of the Wi-Fi network


#define LED1 D2
#define LED2 D3
#define LED3 D5
#define LED4 D6
#define bel D7

DHT dht(dht_dpin, DHTTYPE); 

void setup(void)
{ 
  //LED
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(bel, OUTPUT);
  
  Serial.begin(9600);
  delay(10);
  
  Serial.println('\n');
  
  
  WiFi.begin(ssid, password);             // Connect to the network
  Serial.print("Connecting to ");
  Serial.print(ssid); Serial.println(" ...");
  int i = 0;
  digitalWrite(LED4, HIGH);
  while (WiFi.status() != WL_CONNECTED) { // Wait for the Wi-Fi to connect
    delay(1000);
    digitalWrite(LED3, LOW);
    Serial.print(++i); Serial.print(' ');
  }

  Serial.println('\n');
  Serial.println("Connection established!");  
  Serial.print("IP address:\t");
  Serial.println(WiFi.localIP());
  digitalWrite(LED3, HIGH);
  digitalWrite(LED4, LOW);

  dht.begin();
  Serial.println("Humidity and temperature \n\n");
  Serial.println("==========================================");
  delay(2000);

}
void loop() {
  
    float h = dht.readHumidity();
    float t = dht.readTemperature(); 
    if (!client.connect(server,80)) {
      Serial.println("Gagal Konek ke Server");
      return;
    }
    req = "/save?s=";
    req += t;
    req += "&k=";
    req += h;
    
    if (t>33.0){
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, HIGH);// turn the LED off.(Note that LOW is the voltage level but actually

    digitalWrite(bel, HIGH);
    delay(250);
    digitalWrite(bel, LOW);
    delay(250);
    client.print(String("GET ") + req + "HTTP/1.1\r\n" + "Host: " + server + "\r\n" + "Connection: close\r\n\r\n");
    Serial.print("Kelembapan = ");
    Serial.print(h);
    Serial.print("%  ");
    Serial.print("Suhu = ");
    Serial.print(t); 
    Serial.println("C  ");
    }else { 
      
    digitalWrite(LED2, LOW);
    digitalWrite(LED1, HIGH);
    client.print(String("GET ") + req + "HTTP/1.1\r\n" + "Host: " + server + "\r\n" + "Connection: close\r\n\r\n");
    Serial.print("Kelembapan = ");
    Serial.print(h);
    Serial.print("%  ");
    Serial.print("suhu = ");
    Serial.print(t); 
    Serial.println("C  ");
      }
    delay(5000);
}
