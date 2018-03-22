int incomeByte[7];
int data;
int z=0;
int sum;
unsigned long error;
 
// Arduino夏普GP2Y1051AU0F的串口讀取_源代碼_Weesky維天監製
// 作者ID：Weesky ; ...
// 2014年11月23日
// v1.0 基礎版本，成功讀取數值，並且算出PM2.5濃度。
// v1.1 改進了算法，這樣看起來數值高了些。對於愛好者操作更容易了。
//請不要在採樣週期裡面添加延遲delay這樣的。不然串口寄存器只有64Byte，很可能被塞滿。
 
void setup()
{
  Serial.begin(2400);
}
 
void loop(){
 
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
        for(int k=0;k<7;k++)
        {
          Serial.print(incomeByte[k]);
          Serial.print("|");
        } 
 
        Serial.print(" Vo=");
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
 
  // 維天監製： http://blog.sina.com.cn/u/3689632602
  // 維天淘寶：http://Weesky.taobao.com
  // 本著Arduino開源硬件分享快樂的精神，請各位愛好者自由修改並分享。
  // 修改請註明版本，署上您的大名，不要刪除作者信息，謝謝！
 
}
