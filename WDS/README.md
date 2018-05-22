Simple project using:

    * Arduino Uno R3
    * ADXL345 
    * Pololu LPS331AP


Arduino sends (using wireless connection by ESP-03) data from sensors to Qt Application where the data is wisualised.

Arduino reads sensors data using I2C and using serial port sends it to PC.

Used libraries:

    * https://github.com/jarzebski/Arduino-ADXL345.git
    * https://github.com/pololu/lps-arduino.git
