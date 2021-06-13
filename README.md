# Source Code IOT Project Sensor Suhu & Kelembapan

## Alat dan Bahan
1. [NodeMCU](https://www.tokopedia.com/kakakstoree/nodemcu-v3-lolin-lua-wifi-board-based-esp8266-arduino-ready)
2. Sensor Suhu [DHT11](https://www.amazon.com/Breakout-DHT11-Temperature-Humidity-Sensor/dp/B01J0M3X3Y)
3. Buzzer
4. 2 Buah [LED RGB 4 Kaki](https://shopee.co.id/LED-RGB-Common-Cathode-5mm-4-kaki-Multicolor-Clear-Diode-Ultra-Bright-i.2178321.294270478)
5. Kabel Jumper
6. Papan Rangkaian
7. Library [DHT](https://github.com/adafruit/DHT-sensor-library)
8. Board Manager [ESP8266](https://arduino.esp8266.com/stable/package_esp8266com_index.json) for Arduino IDE
- Paste di File->Preferences->Addtional Board Manager Url->OK-> Kemudian Install
9. [Arduino IDE](https://www.arduino.cc/en/Main/Software)
10. Software [Scrcpy](https://github.com/Genymobile/scrcpy) untuk display android device ke pc (Optional)
11. Web Framework [Codeigniter](https://codeigniter.com/)
12. CSS Framework [Bootstrap](https://getbootstrap.com/)
13. Access Point (Diproject ini menggunakan [TP-LINK-MR3020](https://www.tp-link.com/id/home-networking/3g-4g-router/tl-mr3020/))
14. Untuk Server Menggunakan server virtual yang juga berfungsi sebagai router berikut spesifikasinya :
- [Debian 9 Stretch](http://kambing.ui.ac.id/iso/debian/9.7.0/amd64/iso-cd/)
- Database menggunakan (mariadb)
- Web Server (Apache2)
- DNS Server (bind9) -> http://kelompok5.iot
- dan FTP server (proftpd) untuk upload file web ke server
15. Agar dapat diakses dari publik kita menggunakan [Ngrok](https://ngrok.com/).
-(url web akan dinamis sesuai dengan yang digenerate oleh ngrok)

## Fitur Project

- Monitoring Suhu & Kelembapan via Web local (http://kelompok5.iot) dan Publik via [Ngrok](https://ngrok.com/)
- Simpan Data Hasil Sensor ke Database
- Monitoring Suhu & Kelembapan via Android ([Blynk](https://blynk.io/) App)
- Dilengkapi Dengan Buzzer dan LED Notification

## Project ini Dibuat dan Dikembangan Oleh : 

NAMA | NIM
------------ | -------------
Melissa Azhari          |(18.11.2097)
Ricky Chandra	        |(18.11.2031)
Dimas Priambodo	        |(18.11.2032)
I Made Aditya Pratama	|(18.11.2062)
Nindra Reza	            |(18.11.2063)
Akhid Yanuar A.F	|(18.11.2065)

## Sumber dan Inspirasi
- [Anak Agung Duwi Arsana](https://www.youtube.com/watch?v=RFJZcJATbMU)
- [Tyto Mulyono](https://www.youtube.com/watch?v=uNU_d7M3FAg)
