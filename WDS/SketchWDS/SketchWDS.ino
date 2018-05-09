#include <LPS331.h>
#include <ADXL345.h>
#include <Wire.h>

LPS331 PressureSensor;
ADXL345 Accelerometer;

struct Data{
  Vector Acc_Norm;
  float Pressure_hPa;
}dataToSend;

struct Frame{
  byte X[4];
  byte Y[4];
  byte Z[4];
  byte MetresASL[4];
  byte MetresAGL[4];  
};

union FloatUnion
{
 int number;
 byte bytes[4];
};



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

void sendFrame(struct Frame &fr){
  for(int i=0;i<4;++i){
    Serial.write(fr.X[i]);
  }
  for(int i=0;i<4;++i){
    Serial.write(fr.Y[i]);
  }
  for(int i=0;i<4;++i){
    Serial.write(fr.Z[i]);
  }
  for(int i=0;i<4;++i){
    Serial.write(fr.MetresASL[i]);
  }
  for(int i=0;i<4;++i){
    Serial.write(fr.MetresAGL[i]);
  }  
}


void loop()
{
  struct Frame frame;
  union FloatUnion toChange;
  float temp=0;
  
  dataToSend.Acc_Norm = Accelerometer.readNormalize();    //Returns normalized vector of parameters
  dataToSend.Pressure_hPa = PressureSensor.readPressureMillibars();  //Returns a pressure reading from the sensor in units of millibars (mbar)/hectopascals (hPa).
  //-----------------------------X--------------------------------------
  temp=dataToSend.Acc_Norm.XAxis;
  toChange.number = temp;
  for(int i=0;i<4;++i){
    frame.X[i]=toChange.bytes[i];
  }  
  //-----------------------------Y--------------------------------------
  temp=dataToSend.Acc_Norm.YAxis;
  toChange.number = temp;
  for(int i=0;i<4;++i){
    frame.Y[i]=toChange.bytes[i];
  }  
  //-----------------------------Z--------------------------------------
  temp=dataToSend.Acc_Norm.ZAxis;
  toChange.number = temp;
  for(int i=0;i<4;++i){
    frame.Z[i]=toChange.bytes[i];
  }  
  //-----------------------------ASL--------------------------------------
  temp = PressureSensor.pressureToAltitudeMeters(dataToSend.Pressure_hPa);
  toChange.number = temp;
  for(int i=0;i<4;++i){
    frame.MetresAGL[i]=toChange.bytes[i];
  }
  //-------------------------------------------------------------------
  temp = PressureSensor.pressureToAltitudeMeters(dataToSend.Pressure_hPa,1000);
  toChange.number = temp;
  for(int i=0;i<4;++i){
    frame.MetresASL[i]=toChange.bytes[i];
  }
  //-----------------------------ASL--------------------------------------

  sendFrame(frame);
  delay(1000);

}
