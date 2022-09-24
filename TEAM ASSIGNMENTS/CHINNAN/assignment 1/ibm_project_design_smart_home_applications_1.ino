#include <LiquidCrystal.h>
LiquidCrystal lcd(7,6, 5, 4, 3, 2);
#define echoPin 8
#define trigPin 9

long duration;
int distance;

void setup()
{
  pinMode(10,OUTPUT);
  lcd.begin(16, 2); 
  lcd.setCursor(0,0);
  lcd.print("CHINNAN");
  lcd.setCursor(0,1);
  lcd.print("PROJECT 1");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("START DEVICE ");
  lcd.setCursor(0,1);
  lcd.print("MONITORING");
  delay(1000); 
  lcd.clear();
  pinMode(echoPin,INPUT);
  pinMode(trigPin,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  Serial.begin(9600);
  }

void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; 
  
  int signal=analogRead(A3);
  float voltage=(signal*5.0)/1024;
  float temC=(voltage-0.5)*100;
  lcd.setCursor(0,0);
  lcd.print("Temperature:");
  lcd.print(temC);//temprature moniter
  
  
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  lcd.setCursor(0,1);
  lcd.print("O-distance:");
  lcd.print(distance);
 
  if (temC>100){
  digitalWrite(12,HIGH);
  digitalWrite(10,HIGH);
  }
  else{
  digitalWrite(12,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,HIGH);
  }
   if (distance<100){
  digitalWrite(12,HIGH);
  digitalWrite(10,HIGH);
  }
  else{
  digitalWrite(12,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,HIGH);
  }
  
  
  
}