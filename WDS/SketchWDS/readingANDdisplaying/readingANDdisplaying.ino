#include <LPS331.h>
#include <ADXL345.h>
#include <Wire.h>

LPS331 PressureSensor;
ADXL345 Accelerometer;

struct Data{
  Vector Acc_Raw;
  Vector Acc_Norm;
  float Pressure_hPa;
}dataToSend;


void setup()
{
  Serial.begin(9600);
  Serial.println("Initializing sensors\n");
  Wire.begin();        // join i2c bus (address optional for master)
//initializing LPS331AP
  if(!PressureSensor.init()){
    Serial.println("Cannot find LPS331AP!");
    while(1);
  }

  PressureSensor.enableDefault();
//initializing ADXL345
  if(!Accelerometer.begin()){
    Serial.println("Cannot find ADXL345!");
    while(1);
  }
  Accelerometer.setRange(ADXL345_RANGE_16G);
  Serial.println("Connected succesfully!");
}

void loop()
{
  //data from Accelerometer
  dataToSend.Acc_Raw = Accelerometer.readRaw();  //Returns non-normalized vector of parameters
  dataToSend.Acc_Norm = Accelerometer.readNormalize();    //Returns normalized vector of parameters
  dataToSend.Pressure_hPa = PressureSensor.readPressureMillibars();  //Returns a pressure reading from the sensor in units of millibars (mbar)/hectopascals (hPa).



  Serial.println("**********************************************");
  Serial.println("Accelerometer data normalized:");
  Serial.print("X-Axis: ");Serial.print(dataToSend.Acc_Norm.XAxis);
  Serial.print("\nY-Axis: ");Serial.print(dataToSend.Acc_Norm.YAxis);
  Serial.print("\nZ-Axis: ");Serial.print(dataToSend.Acc_Norm.ZAxis);
  Serial.println("\nPressure sensor data:");
  Serial.print("\nPressure: ");Serial.print(dataToSend.Pressure_hPa);Serial.print(" hPa\n");
  Serial.println("**********************************************\n");
  delay(1000);

}
