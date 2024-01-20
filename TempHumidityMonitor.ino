//Author: Igor Scherer
//Date: 20/01/2024

//O seguinte codigo faaz a leitura de um sensor de temperatura e umidade do ar e mostra o resultado em uma tela lcd de 16 pinos
//This code reads the temperature and humidity using the DHT11 sensor and displays it on an 16 pin lcd screen


#include <DHT.h>
#include <LiquidCrystal.h>

#define DHTPIN 8
#define DHTTYPE DHT11 
 #define LED_GREEN 9
 #define LED_YELLOW 10 
 #define LED_RED 11

DHT dht(DHTPIN, DHTTYPE); //Setting the pins of the DHT sensor
LiquidCrystal lcd(3, 2, 4, 5, 6, 7);//Setting the pins of the lcd screen

void setup(){
  lcd.begin(16, 2); //Inicialize the lcd screen setting the ammount of columns and rows in sequence
  dht.begin(); //Inicialize the DHT sensor
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_RED, OUTPUT);

  Serial.begin(9600); //This can be deleted if you dont want to check the temperature and humidity on serial monitor
}

void loop(){
    float t = dht.readTemperature();
    float h = dht.readHumidity();
    if(h >= 50){
      digitalWrite(LED_GREEN, HIGH);
      digitalWrite(LED_YELLOW, LOW);
      digitalWrite(LED_RED, LOW);
    }
    else if(h >= 16 && h <= 49){
      digitalWrite(LED_GREEN, LOW);
      digitalWrite(LED_YELLOW, HIGH);
      digitalWrite(LED_RED, LOW);
    }
    else if(h <= 15){
      digitalWrite(LED_GREEN, LOW);
      digitalWrite(LED_YELLOW, LOW);
      digitalWrite(LED_RED, HIGH);
    }
    Serial.print("Temperatura = ");
    Serial.print(t);
    Serial.print(" *C ");
    Serial.print("       Umidade = ");
    Serial.print(h);
    Serial.println(" % ");
    lcd.setCursor(0,0);
    lcd.print("Temp= ");
    lcd.print(t);
    lcd.print(" *C");
    lcd.setCursor(0,1);
    lcd.print("Umidade= ");
    lcd.print(h);
    lcd.print("%");
    delay(3000);
    lcd.clear();
}
