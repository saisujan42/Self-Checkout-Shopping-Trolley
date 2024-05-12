boolean stringComplete=false;
String inputString="";
int n=0,tb=0;
String str1="4A00A68FB7D4",str2="4A00A6922957",str3="4A00A6915924",str4="4A00A6A57B32";
String a="BISCUIT = 50",b="CHOCOLATE = 100",c="COOL DRINK = 200",d="YOGURT = 300",com;

void setup()
{
  Serial.begin(9600);
  inputString.reserve(200);
}
void loop()
{
      if(stringComplete)
      {
        if(inputString.equals(str1))
        {
          Serial.println(a);
          tb=tb+50;
          totalbill();
        }
        else if(inputString.equals(str2))
        {
          Serial.println(b);
          tb=tb+100;
          totalbill();
        }
        else if(inputString.equals(str3))
        {
          Serial.println(c);
          tb=tb+200;
          totalbill();
        }
        else if(inputString.equals(str4))
        {
          Serial.println(d);
          tb=tb+300;
          totalbill();
        }
        stringComplete=false;
        inputString="";  
      }
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

void totalbill()
{
  Serial.print("TOTAL BILL = ");
  Serial.println(tb);
}
