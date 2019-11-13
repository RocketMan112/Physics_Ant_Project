const int sensorA = A0;
const int sensorB = A1;

const float VCC = 5.02; // Measured voltage of Ardunio 5V line
const float R_DIV = 4660.0; // Measured resistance of 3.3k resistor

float sensorAVoltage;
float sensorBVoltage;

int numOfAntsA, sensorStateA = 0;
int numOfAntsB = 0, sensorStateB = 0;

// Set this to the minimum resistance require to turn an LED on:
const float voltageThresholdA = 4.10;
const float voltageThresholdB = 4.10;

int checkAnt(float voltage, int& sensorState, int voltageThreshold){
  if(voltageThreshold > voltage && sensorState == 0){
    sensorState = 1;
    return 1;
  }
  else{
    if(voltageThreshold < voltage){
      sensorState = 0;
      return 0;
    }
    return 0;
  }
  
}

void setup() 
{
  Serial.begin(9600);
  Serial.println("Starting Program:");
  Serial.println("3");
  delay(1000);
  Serial.println("2");
  delay(1000);
  Serial.println("1");
  delay(1000);
  Serial.println("Go!");
}

void loop() 
{
  delay(50);
  sensorAVoltage = analogRead(sensorA)* VCC / 1023.0;
  sensorAVoltage = analogRead(sensorA)* VCC / 1023.0;
  delay(50);
  sensorBVoltage = analogRead(sensorB)* VCC / 1023.0;
  sensorBVoltage = analogRead(sensorB)* VCC / 1023.0;


  if(voltageThresholdA > sensorAVoltage && sensorStateA == 0){
    sensorStateA = 1;
    numOfAntsA += 1;
  }
  else{
    if(voltageThresholdA < sensorAVoltage){
      sensorStateA = 0;
    }
  }

  if(voltageThresholdB > sensorBVoltage && sensorStateB == 0){
    sensorStateB = 1;
    numOfAntsB += 1;
  }
  else{
    if(voltageThresholdB < sensorBVoltage){
      sensorStateB = 0;
    }
  }

  
  Serial.println("Sensor A Voltage: " + String(sensorAVoltage) + ", Sensor B: " + String(sensorBVoltage) + " A Count: " + String(numOfAntsA) +" B Count: " + String(numOfAntsB));
//  if(sensorAVoltage < voltageThresholdA || sensorBVoltage < voltageThresholdB){
//    Serial.println("A Count: " + String(numOfAntsA) +" B Count: " + String(numOfAntsB));
//  }
}
