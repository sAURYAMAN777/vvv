#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
#define trigPin 10
#define echoPin 9
#define led 13

void setup() 
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print ("Welcome!");
  delay (5000);
    
}
float dist;
unsigned long duration;
const float uspeed=0.034;

void loop()
{
  lcd.clear();
  lcd.print("distance in cm");
    
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  dist = uspeed * (duration/2);     
  
  lcd.setCursor(0, 1);
  lcd.print(dist);
  delay (200);
  
  if(dist<10)
  {
    digitalWrite(led,HIGH);
  }
 else
  {
    digitalWrite(led,LOW);
  }
  
 delay(200);
}
