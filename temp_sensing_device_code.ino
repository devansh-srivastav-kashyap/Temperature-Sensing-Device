/* Temperature Sensing Device
This device measures the temperature of the surrounding.
It works on the concept of temperature dependence of resistors.
It takes an input from the tmp36 sensor in analog pin A0. 
After taking this analog value, it converts the data into final voltage by calibrating.

digital pins-
2 = rs (register select)
3 = en  (enable)
4,5,6,7

ground and power pin of LCD is sent to 5V and Gnd of Arduino

terminal-1 (contrast) is attached with a resistance and then gnd to adjust the contrast.

read/write= GND for write and 5V for read 

TMP36 Sensor- 
It has ±0.5℃ accurace on the linearity. So, in line 39, voltage is calibrated accordingly.
0.48828125 denotes (5/1023) as 1023 corresponds to 5V. 
*/

#include <LiquidCrystal.h>
LiquidCrystal lcd(3,2,4,5,6,7);

void setup() 
{
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  pinMode(A0, INPUT);
  Serial.begin(9600);
}

void loop() 
{
 
  float temp,voltage;
  voltage= analogRead(A0) * 0.48828125;   //value of input values in range of 0-5
  Serial.println(analogRead(A0));
  temp= (voltage-0.5);
  
  lcd.setCursor(0,0);
  lcd.print("Temp=");
  lcd.setCursor(5,0);
  lcd.print(temp);
  lcd.print("C");
  
}
