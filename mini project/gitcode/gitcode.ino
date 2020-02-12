#include <LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
int count = 0; 
char singleChar; 
String readMsg;
 
void setup()
 {
   Serial.begin(9600);
   lcd.begin(16,2); 
   lcd.setCursor (0,0);
   lcd.print("ELECTRONICS HUB");
   lcd.setCursor(0,1); 
   lcd.print("  RFID Reader  ");
   delay (2000);
 }

void loop() 
{
 if(readMsg == 0)
  {                        
   lcd.setCursor(0,0);
   lcd.print(" Swipe the Card ");
   lcd.setCursor(0,1);
   lcd.print("                ");
  }
while(Serial.available()>0)
  {      
   lcd.setCursor(0,0);
   lcd.print("   Card ID is   ");
   lcd.setCursor(0,1);
   lcd.print("                ");
 
   singleChar = Serial.read();
   count++;
   readMsg += singleChar;
   if(count == 12)  
    {
      lcd.setCursor(2,1);
      lcd.print(readMsg);
      break; 
    }
  }
readMsg="";
delay(1000);
}
