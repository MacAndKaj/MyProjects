#include <Wire.h>

#include <math.h>
#include <LPS331.h>
#include <ADXL345.h>

LPS331 PressureSensor;
ADXL345 Accelerometer;
float Static_Pressure;

uint8_t Start = 0x0A;
byte array[8];
uint8_t CRC=0;

void setup()
{
  Serial.begin(9600);

  Wire.begin();        // join i2c bus (address optional for master)
  //initializing LPS331AP
  if (!PressureSensor.init()) {
    while (1);
  }

  PressureSensor.enableDefault();
  //initializing ADXL345
  if (!Accelerometer.begin()) {
    while (1);
  }
  Accelerometer.setRange(ADXL345_RANGE_16G);
  Static_Pressure = PressureSensor.readPressureMillibars();  //Returns a pressure reading from the sensor in units of millibars (mbar)/hectopascals (hPa).

}

void loop()
{
  //data from Accelerometer
  Vector Acc_Norm = Accelerometer.readNormalize();    //Returns normalized vector of parameters
  float Pressure_hPa = PressureSensor.readPressureMillibars();  //Returns a pressure reading from the sensor in units of millibars (mbar)/hectopascals (hPa).
  double RollRad = atan(Acc_Norm.XAxis / (sqrt(square(Acc_Norm.YAxis) + square(Acc_Norm.ZAxis)))) * 180.00 / 3.141592;
  double PitchRad = atan(Acc_Norm.YAxis / (sqrt(square(Acc_Norm.XAxis) + square(Acc_Norm.ZAxis)))) * 180.00 / 3.141592;
  int8_t Roll = (int16_t) RollRad;
  int8_t Pitch = (int16_t) PitchRad;
  float npz = PressureSensor.pressureToAltitudeMeters(Pressure_hPa, Static_Pressure);
  float npm = PressureSensor.pressureToAltitudeMeters(Pressure_hPa);
  uint16_t HASL = (uint16_t) npm;
  uint16_t HAGL = (uint16_t) npz;
  if (HASL > 1000) HASL = 0;
  if (HAGL > 1000) HAGL = 0;

  

  array[0] = Start;
  array[1] = Roll;
  array[2] = Pitch;
  array[3] = HASL >> 8;
  array[4] = HASL;
  array[5] = HAGL >> 8;
  array[6] = HAGL;
  for(int i=0;i<7;++i){
    CRC+=array[i];
  } 
  array[7] = CRC;
    Serial.write(array, 8);
//  Serial.println(CRC,HEX);
  CRC=0;
  delay(50);

}

