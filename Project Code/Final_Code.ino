#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

boolean stringComplete=false;
String inputString="";
int n=0,tb=0;
String str1="4A00A68FB7D4",str2="4A00A6922957",str3="4A00A6915924",str4="4A00A6A57B32";
String a="BISCUIT = 50",b="CHOCOLATE = 100",c="COOL DRINK = 200",d="YOGURT = 300",com;

void setup()
{
  Serial.begin(9600);
  inputString.reserve(200);
  lcd.begin(16, 2);
}
void loop()
{
      if(stringComplete)
      {
        if(inputString.equals(str1))
        {
          lcd.clear();
          Serial.print(a);
          lcd.print(a);
          tb=tb+50;
          totalbill();
        }
        else if(inputString.equals(str2))
        {
          lcd.clear();
          Serial.print(b);
          lcd.print(b);
          tb=tb+100;
          totalbill();
        }
        else if(inputString.equals(str3))
        {
          lcd.clear();
          Serial.print(c);
          lcd.print(c);
          tb=tb+200;
          totalbill();
        }
        else if(inputString.equals(str4))
        {
          lcd.clear();
          Serial.print(d);
          lcd.print(d);
          tb=tb+300;
          totalbill();
        }
        stringComplete=false;
        inputString="";  
      }
}

void totalbill()
{
  Serial.print("TOTAL BILL = ");
  Serial.println(tb);
  lcd.print("TOTAL BILL = ");
  lcd.println(tb);
}

void serialEvent()
{
  while(Serial.available())
  {
    n++;
    char inChar=(char)Serial.read();
    inputString+=inChar;
    if(n>=12)
    {
      n=0;
      stringComplete=true;
      
    }
  }
}
