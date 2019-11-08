const int sensorA = A0;
const int sensorB = A1;

const float VCC = 5.02; // Measured voltage of Ardunio 5V line
const float R_DIV = 4660.0; // Measured resistance of 3.3k resistor

float sensorAVoltage;
float sensorBVoltage;

int numOfAntsA, sensorStateA = 0;
int numOfAntsB, sensorStateB = 0;

// Set this to the minimum resistance require to turn an LED on:
const float voltageThresholdA = 4.00;
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
  Serial.println("Starting Program...");
  Serial.print("3,");
  Serial.print("2,");
  Serial.println("1");
  Serial.println("Go!");
}

void loop() 
{
  sensorAVoltage = analogRead(sensorA)* VCC / 1023.0;
  delay(50);
  sensorBVoltage = analogRead(sensorB)* VCC / 1023.0;

  numOfAntsA += checkAnt(sensorAVoltage, sensorStateA, voltageThresholdA);
  numOfAntsB += checkAnt(sensorBVoltage, sensorStateB, voltageThresholdB);

  if(sensorAVoltage < voltageThresholdA || sensorBVoltage < voltageThresholdB){
    Serial.println("Sensor A Voltage: " + String(sensorAVoltage) + ", Sensor B: " + String(sensorBVoltage) + " A Count: " + String(numOfAntsA) +" B Count: " + String(numOfAntsB));
  }

  delay(50);
}
