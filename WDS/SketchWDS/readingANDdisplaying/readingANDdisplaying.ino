
#include <Wire.h>

#include <math.h>
#include <LPS331.h>
#include <ADXL345.h>

LPS331 PressureSensor;
ADXL345 Accelerometer;



void setup()
{
  Serial.begin(9600);
  Wire.begin();        // join i2c bus (address optional for master)
//initializing LPS331AP
  if(!PressureSensor.init()){
    while(1);
  }

  PressureSensor.enableDefault();
//initializing ADXL345
  if(!Accelerometer.begin()){
    while(1);
  }
  Accelerometer.setRange(ADXL345_RANGE_16G);
}

void loop()
{
  //data from Accelerometer
  Vector Acc_Norm = Accelerometer.readNormalize();    //Returns normalized vector of parameters
  float Pressure_hPa = PressureSensor.readPressureMillibars();  //Returns a pressure reading from the sensor in units of millibars (mbar)/hectopascals (hPa).
  double RollRad = atan(Acc_Norm.XAxis/(sqrt(square(Acc_Norm.YAxis)+square(Acc_Norm.ZAxis))))*180.00/3.141592;
  double PitchRad = atan(Acc_Norm.YAxis/(sqrt(square(Acc_Norm.XAxis)+square(Acc_Norm.ZAxis))))*180.00/3.141592;

  int AGL = PressureSensor.pressureToAltitudeMeters(Pressure_hPa,1020);;
  
  int16_t Roll =(uint16_t) RollRad;
  int16_t Pitch=(uint16_t) PitchRad;
  uint16_t Pressure1=(uint16_t)Pressure_hPa;
  Pressure_hPa-=Pressure1;
  Pressure_hPa*=100;
  uint16_t Pressure2=(uint16_t)Pressure_hPa;
  
  Serial.write(Roll);
  Serial.write(Pitch);
  Serial.write(Pressure1);
  Serial.write(Pressure2);
  delay(200);

}
