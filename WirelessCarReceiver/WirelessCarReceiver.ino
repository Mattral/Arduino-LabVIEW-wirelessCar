#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
#define DC_MOTOR1_POSITIVE 6
#define DC_MOTOR1_NEGATIVE 7
#define DC_MOTOR2_POSITIVE 8
#define DC_MOTOR2_NEGATIVE 9
void setup()
{ 
  Serial.begin(9600);
  lcd.begin(20,4);
  pinMode(DC_MOTOR1_POSITIVE, OUTPUT);
  pinMode(DC_MOTOR1_NEGATIVE, OUTPUT);
  pinMode(DC_MOTOR2_POSITIVE, OUTPUT);
  pinMode(DC_MOTOR2_NEGATIVE, OUTPUT);
  lcd.setCursor(0,0);
  lcd.print("DC motor control");
  lcd.setCursor(0,1);
  lcd.print("+ remote control");
  delay(1000);
}
void loop()
{
char LABVIEW_SERIAL_CHAR;
LABVIEW_SERIAL_CHAR=Serial.read();
  if(LABVIEW_SERIAL_CHAR=='W')
  
  {  
    lcd.clear();     
    lcd.setCursor(0,3);
 lcd.print("Motor Forward");
    digitalWrite(DC_MOTOR1_POSITIVE, HIGH);
    digitalWrite(DC_MOTOR1_NEGATIVE, LOW);
    digitalWrite(DC_MOTOR2_POSITIVE, HIGH);
    digitalWrite(DC_MOTOR2_NEGATIVE, LOW);
  } 
  else if (LABVIEW_SERIAL_CHAR=='Z')
  {
    lcd.clear(); 
    lcd.setCursor(0,3);
    lcd.print("Motor Reverse");
    digitalWrite(DC_MOTOR1_POSITIVE, LOW);
    digitalWrite(DC_MOTOR1_NEGATIVE, HIGH);
    digitalWrite(DC_MOTOR2_POSITIVE, LOW);
    digitalWrite(DC_MOTOR2_NEGATIVE, HIGH);
  }
  else if (LABVIEW_SERIAL_CHAR=='X')
  {
    lcd.clear();  
    lcd.setCursor(0,3);
    lcd.print("Motor Left"); 
    digitalWrite(DC_MOTOR1_POSITIVE, HIGH);
    digitalWrite(DC_MOTOR1_NEGATIVE, LOW);
    digitalWrite(DC_MOTOR2_POSITIVE, LOW);
    digitalWrite(DC_MOTOR2_NEGATIVE, LOW);  
  }
  else if (LABVIEW_SERIAL_CHAR=='Y')
  {
    lcd.clear(); 
    lcd.setCursor(0,3);
    lcd.print("Motor Right");
    digitalWrite(DC_MOTOR1_POSITIVE, LOW);
    digitalWrite(DC_MOTOR1_NEGATIVE, LOW);
    digitalWrite(DC_MOTOR2_POSITIVE, HIGH);
    digitalWrite(DC_MOTOR2_NEGATIVE, LOW);  
  }
  else if (LABVIEW_SERIAL_CHAR=='E')
  {
    lcd.clear(); 
    lcd.setCursor(0,3);
    lcd.print("STOP");
    digitalWrite(DC_MOTOR2_POSITIVE, LOW);
    digitalWrite(DC_MOTOR1_NEGATIVE, LOW);
    digitalWrite(DC_MOTOR2_POSITIVE, LOW);
    digitalWrite(DC_MOTOR2_NEGATIVE, LOW);  
  }
  
   delay(10);      
}
