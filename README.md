# Temperature-Sensing-Device

Specifications of Device-

Ouptput Temperature Range- -40℃ to 125℃
Output Voltage Range- 0.1V to 2V
Operating Voltage - 0 to 5V

Working- 

This device has a temperature sensor that measures the temperature of the environment. This sensor use a solid-state technique to determine the temperature. It uses the fact that- As temperature increases, the voltage across a diode increases at a known rate. (Technically, this is actually the voltage drop between the base and emitter - the Vbe - of a transistor.) By precisely amplifying the voltage change, it is easy to generate an analog signal that is directly proportional to temperature. There have been some improvements on the technique but, essentially that is how temperature is measured. 

Construction-

The sensor is connected to the pin A0 of Arduino. Pins of LCD-
2 = rs (register select)
3 = en  (enable)
4,5,6,7
Ground and Power pin of LCD is sent to 5V and Gnd of Arduino
Terminal-1 (contrast) is attached with a resistance and then grounded to adjust the contrast.
Read/Write = GND for write and 5V for read

Calculation- 

analogRead(A0) inputs the voltage output of the sensor and maps it to a value between 0-1023. To convert it back to the real voltage coming from the sensor- analogRead(A0) * (5/1024)
Since the offset voltage is 0.5V, we subtract 0.5 from above result. Say this result is result1.
Resolution of the Sensor is (190/1.9), so at the end we will multiply 100 with the result1 to get the final temperature.




