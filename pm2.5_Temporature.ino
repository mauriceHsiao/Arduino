#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);
int DHpin = 8;
byte dat[5];
int incomeByte[7];
int data;
int z=0;
int sum;
unsigned long error;

void setup()
{
  Serial.begin(2400);
  pinMode(DHpin,OUTPUT);
  // initialize the LCD
  lcd.begin();
  // Turn on the blacklight and print a message.
  lcd.backlight();
  lcd.print("Hello, world!");
}

void loop()
{
  if (Serial.available()>0){
 
    data=Serial.read();
    if(data == 170){
      z=0;
      incomeByte[z]=data;
    }
    else{
      z++;
      incomeByte[z]=data;
    } 
    if(z==6)
    {
      sum=incomeByte[1]+ incomeByte[2]+ incomeByte[3] + incomeByte[4];
 
      if(incomeByte[5]==sum && incomeByte[6]==255 )
      {
 
        // Serial.print("Data OK! |");
        /*
        for(int k=0;k<7;k++)
        {
          Serial.print(incomeByte[k]);
          Serial.print("|");
        } 
        */
 
        Serial.print("Vo=");
        float vo=(incomeByte[1]*256.0+incomeByte[2])/1024.0*5.00;
        Serial.print(vo,3);
        Serial.print("v | ");
        float c=vo*700;
        // 這裡我修改過咯，2014年11月23日，v1.1
        // 普通Arduinio玩家也可以算出濃度啦！
        // 當然更精準的還需要自行標定哦：)  
        Serial.print(" PM2.5 = ");
        Serial.print(c,2);
        Serial.print("ug/m3 ");
        Serial.println();
        
        start_test();
        Serial.print("Hum=");
        Serial.print(dat[0], DEC);
        Serial.print('.');
        Serial.print(dat[1],DEC);
        Serial.print('%');
        Serial.print(" & Temp=");
        Serial.print(dat[2], DEC);
        Serial.print('.');
        Serial.print(dat[3],DEC);
        Serial.println('C');

        //LCD SHow Data 
         lcd.clear();
        //Line 0
        lcd.setCursor(0, 0);
        lcd.print("PM2.5=");
        lcd.print(c,2);
        lcd.print("ug/m3");
      
        //line 1
        lcd.setCursor(0, 1);
        lcd.print("Hum=");
        lcd.print(dat[0], DEC);
        lcd.print('%');
        lcd.print(" Temp=");
        lcd.print(dat[2], DEC);
        lcd.println('C');
        delay(1000);
      }
      else{
        z=0;
        Serial.flush();
        data='0';
        for(int m=0;m<7;m++){
          incomeByte[m]=0;
        }
        /* 
         error++;
         Serial.print(" ### This is ");
         Serial.print(error);
         Serial.println(" Error ###");
         */
      }
      z=0;
    }
  }
  // Do nothing here...
}

byte read_data()
{
  byte data;
  for(int i=0; i<8; i++)
  {
    if(digitalRead(DHpin) == LOW)
    {
      while(digitalRead(DHpin) == LOW);
      delayMicroseconds(30);
      if(digitalRead(DHpin) == HIGH) data |= (1<<(7-i));
      while(digitalRead(DHpin) == HIGH);
    }
  }
  return data;
}

void start_test()
{
  digitalWrite(DHpin,LOW);
  delay(30);
  digitalWrite(DHpin,HIGH);
  delayMicroseconds(40);
  pinMode(DHpin,INPUT);
  while(digitalRead(DHpin) == HIGH);
  delayMicroseconds(80);
  if(digitalRead(DHpin) == LOW);
  delayMicroseconds(80);
  for(int i=0;i<4;i++) dat[i] = read_data();
  pinMode(DHpin,OUTPUT);
  digitalWrite(DHpin,HIGH);
}
