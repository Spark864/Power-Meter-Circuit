# Power-Meter-Circuit
![alt text](https://github.com/Spark864/Power-Meter-Circuit/blob/main/PowerMeterSchematic.png?raw=true?=2690x1501)
The circuit operates by measuring the input voltage and current indirectly. It measures the voltage by using a voltage divider to reduce the input voltage to levels the microcontroller ADC can handle (< 5V). The original input voltage can later be found by performing calculations using software. Current is measured by measuring the voltage drop across a 0.1ohm resistor. The op amp amplifies the voltage at the top of the 0.1ohm resistor by eleven times. The output of the op amp is then fed into the ADC of the microcontroller. Further calculations are performed using software to determine the current. An op amp was used because small currents cannot be measured by the 10-bit ADC in the microcontroller, as it can only measure in ~5mV steps, making the ADC capable of only determining current in 50mA steps. The op amp reduces this value by eleven times to approximately 4.54mA steps. This makes our circuit good for measuring small currents, such as those suitable for use on a breadboard. A mosfet is used for toggling the load, it toggles the load on once a certain threshold voltage is reached. 

The power is computed on the microcontroller by using the equation current * voltage. To calculate power in watt hours, the equation used was current * voltage / 3600 and is measured in 1 second intervals. The intervals could be adjusted in software to be more or less frequent. The measured voltage, current, instantaneous power, and power consumed values are printed to an LCD display using the I2C bus. 
