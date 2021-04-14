#include <SD.h>
#include <SPI.h>
const int AirValue =645 ;   //you need to replace this value with Value_1
const int WaterValue = 290;  //you need to replace this value with Value_2
int soilMoistureValue = 0;
int soilmoisturepercent=0;

File fp;
int counter=0;

void setup()
{
  pinMode(10, OUTPUT);
  Serial.begin(9600);
  while (!Serial)
  {
  }
  Serial.print("Initializing SD card...");
  if (!SD.begin(10)) {
  Serial.println("initialization failed!");
  while (1);
  }
  Serial.println("good to go");
    for (int i=0;i<6;i++)
    {
    analogWrite(5, 255);
    delay(1000);
    analogWrite(5, 0);
    delay(500);
    }

}

void loop()
{
  fp= SD.open("graphs.txt", FILE_WRITE);
  if(!fp)
  Serial.println("unable to open file");
  soilMoistureValue = analogRead(A1);  //put Sensor insert into soil
  Serial.println(soilMoistureValue);
  soilmoisturepercent = map(soilMoistureValue, AirValue, WaterValue, 0, 100);
  if(soilmoisturepercent >= 100)
  {
    Serial.println("100 %");
    fp.print("100 ");
    fp.println(counter);
  }
  else if(soilmoisturepercent <=0)
  {
    Serial.println("0 %");
    fp.print("0 ");
    fp.println(counter);
  }
  else if(soilmoisturepercent >0 && soilmoisturepercent < 100)
  {
    Serial.print(soilmoisturepercent);
    Serial.println("%");
    fp.print(soilmoisturepercent);
    fp.print(" ");
    fp.println(counter);
  
  }
  fp.close();
  counter++;
  
  delay(60000);
}
