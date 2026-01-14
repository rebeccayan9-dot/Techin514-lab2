#include <Arduino.h>

const int PIN_VOUT1 = 2; 
const int PIN_VOUT2 = 3; 
const int PIN_VOUT3 = 4; 

void setup() {
    
    Serial.begin(115200);
    while (!Serial); 

    
    analogReadResolution(12);
    
    Serial.println("ESP32-C3 电压读取测试开始...");
}

float getVoltage(int pin, int &raw_value) {

    raw_value = analogRead(pin);

    float voltage = (raw_value / 4095.0) * 3.3;
    return voltage;
}

void loop() {
    int raw1, raw2, raw3;
    float v1 = getVoltage(PIN_VOUT1, raw1);
    float v2 = getVoltage(PIN_VOUT2, raw2);
    float v3 = getVoltage(PIN_VOUT3, raw3);


    Serial.print("VOUT1 (G2) - ADC: "); Serial.print(raw1); Serial.print(" | "); Serial.print(v1); Serial.print("V | ");
    Serial.print("VOUT2 (G3) - ADC: "); Serial.print(raw2); Serial.print(" | "); Serial.print(v2); Serial.print("V | ");
    Serial.print("VOUT3 (G4) - ADC: "); Serial.print(raw3); Serial.print(" | "); Serial.print(v3); Serial.println("V");

    delay(1000);
}