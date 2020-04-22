/* Temperature Sensing Device

This device measures the temperature of the surrounding.

It works on the concept of temperature dependence of voltages of diodes.

It takes an input from the TMP36 sensor in analog pin A0. 

After taking this analog value, it converts the data into final voltage by calibrating.

Digital pins-

* 2 = rs (register select)
* 3 = en  (enable)
* 4,5,6,7

Ground and Power pin of LCD is sent to 5V and Gnd of Arduino

terminal-1 (contrast) is attached with a resistance and then gnd to adjust the contrast.

read/write= GND for write and 5V for read 

TMP36 Sensor- 

*It has 0.5V offset so, in line 39, voltage is calibrated accordingly.

*0.0048828125 denotes the resolution of the Arduino Voltage (5/1024). 

*Resolution=(5-0)/(1024-0). It is the smallest real life voltage that can be measured.

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
  
  voltage= analogRead(A0) * 0.00488758553;   //value of input values in range of 0-5
  temp= (voltage-0.5)* 100;   
  lcd.setCursor(0,0);
  lcd.print("Temp=");
  lcd.setCursor(5,0);
  lcd.print(temp);
  lcd.print("C");
  
}
