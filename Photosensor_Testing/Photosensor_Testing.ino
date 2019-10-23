const int sensorA = A0;
const int sensorB = A1;

const float VCC = 5.02; // Measured voltage of Ardunio 5V line
const float R_DIV = 4660.0; // Measured resistance of 3.3k resistor

float sensorAVoltage;
float sensorBVoltage;

int numOfAntsA, sensorStateA = 0;
int numOfAntsB, sensorStateB = 0;

// Set this to the minimum resistance require to turn an LED on:
const float voltageThreshold = 10000.0;

int checkAnt(float voltage, int& sensorState){
  if(voltageThreshold > voltage && sensorStateA == 0){
    sensorStateA = 1;
    return 1;
  }
  else{
    if(voltageThreshold < voltage){
      sensorState = 0;
    }
  }
  
}

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  sensorAVoltage = analogRead(sensorA)* VCC / 1023.0;
  delay(50);
  sensorBVoltage = analogRead(sensorB)* VCC / 1023.0;
  
  Serial.println("Sensor A Voltage: " + String(sensorAVoltage) + ", Sensor B: " + String(sensorBVoltage));

  numOfAntsA += checkAnt(sensorAVoltage, sensorStateA);
  numOfAntsB += checkAnt(sensorBVoltage, sensorStateB);

  delay(100);
}
