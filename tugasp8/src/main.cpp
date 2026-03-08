#include <Arduino.h>
#include "esp_log.h"

const int ledPin1 = 2;
const int ledPin2 = 4;
const int ledPin3 = 16;
const int ledPin4 = 17;

void setup()
{
  Serial.begin(9600);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  ESP_LOGI("UART RECEIVE", "Serial monitor telah diinisialisasi.");
  delay(1000);
}

void loop()
{
  if (Serial.available())
  {
    char data = Serial.read();
    ESP_LOGI("UART RECEIVE", "Karakter yang dikirim: %c", data);

    // Mematikan semua LED
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin4, LOW);

    // Menggunakan karakter yang diterima untuk mengontrol LED
    switch (data)
    {
    case '1':
      digitalWrite(ledPin1, HIGH);
      delay(2000);                // Menyala selama 2 detik
      digitalWrite(ledPin1, LOW); // Matikan LED
      break;
    case '2':
      digitalWrite(ledPin2, HIGH);
      delay(2000);
      digitalWrite(ledPin2, LOW);
      break;
    case '3':
      digitalWrite(ledPin3, HIGH);
      delay(2000);
      digitalWrite(ledPin3, LOW);
      break;
    case '4':
      digitalWrite(ledPin4, HIGH);
      delay(2000);
      digitalWrite(ledPin4, LOW);
      break;
    default:
      // Handle jika data tidak sama dengan '1', '2', '3', atau '4'
      break;
    }
  }
}