#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int waterBtn = 6;
const int medicineBtn = 7;
const int foodBtn = 8;
const int nurseBtn = 9;
const int emergencyBtn = 10;
const int waterLED = A0;
const int medicineLED = A1;
const int foodLED = A2;
const int nurseLED = A3;
const int emergencyLED = A4;
const int buzzer = 13;
void setup()
{
  lcd.begin(16,2);
  pinMode(waterBtn, INPUT_PULLUP);
  pinMode(medicineBtn, INPUT_PULLUP);
  pinMode(foodBtn, INPUT_PULLUP);
  pinMode(nurseBtn, INPUT_PULLUP);
  pinMode(emergencyBtn, INPUT_PULLUP);
  pinMode(waterLED, OUTPUT);
  pinMode(medicineLED, OUTPUT);
  pinMode(foodLED, OUTPUT);
  pinMode(nurseLED, OUTPUT);
  pinMode(emergencyLED, OUTPUT);
  pinMode(buzzer, OUTPUT);
  lcd.clear();
  lcd.print("Patient System");
  delay(1500);
}
void allOFF()
{
  digitalWrite(waterLED, LOW);
  digitalWrite(medicineLED, LOW);
  digitalWrite(foodLED, LOW);
  digitalWrite(nurseLED, LOW);
  digitalWrite(emergencyLED, LOW);
  digitalWrite(buzzer, LOW);
}


void scrollMessage(String msg)
{
  lcd.clear();

  lcd.setCursor(16,0);
  lcd.print(msg);

  for(int i=0;i<16+msg.length();i++)
  {
    lcd.scrollDisplayLeft();
    delay(200);
  }

  lcd.clear();
}
void loop()
{
  if(digitalRead(waterBtn)==LOW)
  {
    allOFF();
    digitalWrite(waterLED,HIGH);
    tone(buzzer,1000,300);
    scrollMessage("Need Water");
    while(digitalRead(waterBtn)==LOW);
    delay(200);
  }
  else if(digitalRead(medicineBtn)==LOW)
  {
    allOFF();
    digitalWrite(medicineLED,HIGH);
    tone(buzzer,1000,300);
    scrollMessage("Need Medicine");
    while(digitalRead(medicineBtn)==LOW);
    delay(200);
    }
  else if(digitalRead(foodBtn)==LOW)
  {
    allOFF();
    digitalWrite(foodLED,HIGH);
    tone(buzzer,1000,300);
    scrollMessage("Need Food");
    while(digitalRead(foodBtn)==LOW);
    delay(200);
  }

  else if(digitalRead(nurseBtn)==LOW)
  {
    allOFF();
    digitalWrite(nurseLED,HIGH);
    tone(buzzer,1000,300);
    scrollMessage("Call Nurse");
    while(digitalRead(nurseBtn)==LOW);
    delay(200);
  }

  else if(digitalRead(emergencyBtn)==LOW)
  {
    allOFF();
    digitalWrite(emergencyLED,HIGH);

    lcd.clear();
    lcd.print("!! EMERGENCY !!");

    digitalWrite(buzzer,HIGH);

    while(digitalRead(emergencyBtn)==LOW);

    digitalWrite(buzzer,LOW);
    delay(200);
  }

  else
  {
    allOFF();
    lcd.setCursor(0,0);
    lcd.print("Patient System ");
    lcd.setCursor(0,1);
    lcd.print("Waiting...");
  }

  delay(100);
}