Simple project using:

    * Arduino Uno R3
    * ESP-03 Module with ESP8266
    * ADXL345 
    * Pololu LPS331AP


Arduino sends (using wireless connection by ESP-03) data from sensors to Qt Application where the data is wisualised.

Arduino reads sensors data using I2C and by UART sends frame with information to ESP-03 connected with PC.


Used libraries:
    * https://github.com/jarzebski/Arduino-ADXL345.git
    * https://github.com/pololu/lps-arduino.git
