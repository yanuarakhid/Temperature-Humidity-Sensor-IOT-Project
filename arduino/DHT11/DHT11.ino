#include <ESP8266WiFi.h>
#define BLYNK_PRINT Serial 
#include <BlynkSimpleEsp8266.h>
#include "DHT.h"        // including the library of DHT11 temperature and humidity sensor
#define DHTTYPE DHT11   // DHT 11
#define dht_dpin D1

DHT dht(dht_dpin, DHTTYPE); 
WiFiClient client;

String req;
const char* server = "10.100.5.1";
const char* ssid     = "Kelompok 5 IOT";         // The SSID (name) of the Wi-Fi network you want to connect to
const char* password = "mantapmantap";     // The password of the Wi-Fi network
char auth[] = "LY18jV91ZsXguMt0nZAGMok9Dek7xIgG";


#define LED1_RED D2
#define LED1_BLUE D4
#define LED2_GREEN D5
#define LED2_RED D7
#define bel D8



void setup(void)
{ 
  //LED
  pinMode(LED1_RED, OUTPUT);
  pinMode(LED1_BLUE, OUTPUT);
  pinMode(LED2_GREEN, OUTPUT);
  pinMode(LED2_RED, OUTPUT);
  pinMode(bel, OUTPUT);
  
  Serial.begin(9600);
  delay(10);
  Serial.println('\n');
  

  WiFi.begin(ssid, password);             // Connect to the network
  Serial.print("Connecting to ");
  Serial.print(ssid); Serial.println(" ...");
  int i = 0;
  digitalWrite(LED1_BLUE, HIGH);
  while (WiFi.status() != WL_CONNECTED) { // Wait for the Wi-Fi to connect
     delay(1000);
     digitalWrite(LED1_RED, LOW);
     Serial.print(++i); Serial.print(' ');
  }
  
  Serial.println('\n');
  Serial.println("Connection established!");  
  Serial.print("IP address:\t");
  Serial.println(WiFi.localIP());
 
  Blynk.config(auth);
  Blynk.connect(3333);  // timeout set to 10 seconds and then continue without Blynk
  Serial.println("Connected to Blynk server");
  digitalWrite(LED1_RED, HIGH);
  digitalWrite(LED1_BLUE, LOW);
 
  dht.begin();
  Serial.println("Humidity anod temperature \n\n");
  Serial.println("==========================================");
  delay(2000);
}


void loop() {

    float h = dht.readHumidity();
    float t = dht.readTemperature(); 
    
    if (!client.connect(server,80)) {
        Serial.println("Gagal Konek ke Server");
        digitalWrite(LED1_BLUE, HIGH);
        digitalWrite(LED1_RED, LOW);
       return;
     }
     
    Blynk.virtualWrite(V0, t);
    Blynk.virtualWrite(V1, h);
    
    req = "/save?s=";
    req += t;
    req += "&k=";
    req += h;
    
    if (t>28.0){
        digitalWrite(LED2_GREEN, HIGH);
        digitalWrite(LED2_RED, LOW);  
        digitalWrite(bel, HIGH);
        delay(250);
        digitalWrite(bel, LOW);
        delay(250);
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
        digitalWrite(LED2_RED, HIGH); 
        digitalWrite(LED2_GREEN, LOW); 
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
