#include <ESP8266WiFi.h> //library esp8266
#include <BlynkSimpleEsp8266.h> // library blynk
#include "DHT.h"        // including the library of DHT11 temperature and humidity sensor
#define DHTTYPE DHT11   // type of DHT 11
#define BLYNK_PRINT Serial 

#define dht_dpin D1 // definisikan port D1 sebagai port dht 11
//Define semua led yang digunakan
#define LED1_RED D2
#define LED1_BLUE D4
#define LED2_BLUE D5
#define LED2_GREEN D6
#define LED2_RED D7
#define bel D8 //define port D8 buzzer

DHT dht(dht_dpin, DHTTYPE); //integrasi ke fungsi dht dengan memasukan parameter pindht dan typenya 
WiFiClient client; // alias WifiClient sebagai client

String req; //declare variabel req
const char* server = "10.100.5.1"; //alamat db dan web server
const char* ssid     = "Kelompok 5 IOT";         // The SSID (name) of the Wi-Fi network you want to connect to
const char* password = "mantapmantap";     // The password of the Wi-Fi network
char auth[] = "LY18jV91ZsXguMt0nZAGMok9Dek7xIgG"; //token auth blynk



void setup(void)
{ 
  //LED
  pinMode(LED1_RED, OUTPUT);
  pinMode(LED1_BLUE, OUTPUT);
  pinMode(LED2_BLUE, OUTPUT);
  pinMode(LED2_GREEN, OUTPUT);
  pinMode(LED2_RED, OUTPUT);
  pinMode(bel, OUTPUT);
  
  Serial.begin(9600);
  delay(10);
  Serial.println('\n');
  
  //mengkoneksikan dengan wifi
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

  //mengkoneksikan dengan blynk server
  Blynk.config(auth);
  Blynk.connect(3333);  // timeout set to 10 seconds and then continue without Blynk
  Serial.println("Connected to Blynk server");
  digitalWrite(LED1_RED, HIGH);
  digitalWrite(LED1_BLUE, LOW);

  //memulai jalankan sensor dht11
  dht.begin();
  Serial.println("Humidity anod temperature \n\n");
  Serial.println("==========================================");
  delay(2000);
}


void loop() {

    //declare variabel suhu dan temperature dan mengisinya dengan output sensor
    float h = dht.readHumidity();
    float t = dht.readTemperature(); 

    //kondisi jika tidak konek ke server maka lampu led1 akan bewarna merah
    if (!client.connect(server,80)) {
        Serial.println("Gagal Konek ke Server");
        digitalWrite(LED1_BLUE, HIGH);
        digitalWrite(LED1_RED, LOW);
       return;
     }

     // mengisi port virtual Bylnk dengan hasil dari pembacaan sensor
    Blynk.virtualWrite(V0, t);
    Blynk.virtualWrite(V1, h);

    // mengisi variabel req dengan method controller dan gabungan hasil sensor suhu dan kelembapan
    // untuk nantinya merupakan langkah awal mengirimkan data ke db
    req = "/save?s=";
    req += t;
    req += "&k=";
    req += h;

    //kondisi jika suhu ruangan lebih dari 25 derajat
    // lampu led akan berubah jadi merah dan buzzer berbunyi
    if (t>=30.0){
        digitalWrite(LED2_GREEN, HIGH);
        digitalWrite(LED2_BLUE, HIGH);
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
    }
    //kondisi jika suhu ruangan kurang dari 20 derajat
    // lampu led akan berubah jadi Biru dan buzzer berbunyi
    else if (t<=28.0){
        digitalWrite(LED2_GREEN, HIGH);
        digitalWrite(LED2_RED, HIGH);
        digitalWrite(LED2_BLUE, LOW);  
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
    }
    //kondisi jika suhu ruangan normal
    // lampu led akan berubah jadi hijau dan buzzerc berhenti berbunyi
    else {
        digitalWrite(LED2_RED, HIGH);
        digitalWrite(LED2_BLUE, HIGH); 
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
