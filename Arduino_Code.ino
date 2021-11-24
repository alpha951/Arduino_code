#include <LiquidCrystal.h>
//LiquidCrystal(RS,E,D4,D5,D6,D7);
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
#define sensor A0
byte degree[8] =
{
  0b00011,
  0b00011,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};
int motorPin1 = 6;
int motorPin2 = 7;

void setup()
{
  lcd.begin(16, 2);
  lcd.createChar(1, degree);
  lcd.setCursor(0, 0);
  lcd.print("KESHAV CARPENTER");
  lcd.setCursor(0, 2);
  lcd.print(" 2OUEC068 ");
  delay(2000);
  lcd.clear();
  //  pinMode(motorPin, OUTPUT);
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
}
void loop()
{
  /*---------Temperature-------*/
  float reading = analogRead(sensor);
  float temperature = reading * (5.0 / 1023.0) * 100;
  delay(10);

  /*------Display Result------*/
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("Temperature");
  lcd.setCursor(4, 1);
  lcd.print(temperature);
  lcd.write(1);
  lcd.print("C");
  delay(1000);
  lcd.clear();
  lcd.setCursor(2, 0);
  if (temperature <= 38)
  {

    for (int positionCounter = 0; positionCounter < 26; positionCounter++)
    {
      // scroll one position left:
      lcd.scrollDisplayLeft();
      // wait a bit:
      lcd.print("Please Sanitize Your Hands");
      lcd.setCursor(2, 0);
      delay(100);

    }
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("Thank You!");

    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    delay(4000);
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
  }
  else
  {
    //    digitalWrite(motorPin1, LOW);
    for (int positionCounter = 0; positionCounter < 26; positionCounter++)
    {
      // scroll one position left:
      lcd.scrollDisplayLeft();
      // wait a bit:
      lcd.print("Sorry! Entry Denied");
      lcd.setCursor(2, 0);
      delay(250);
    }
  }
  delay(1000);
}
