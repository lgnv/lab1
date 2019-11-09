#include <Arduino.h>
const int countLed = 8;
const int startPin = 2;
const int endPin = startPin + countLed;

void setup(){
    Serial.begin(115200);
    Serial.println("Started!");
    for(int i = startPin; i < endPin; i++){
        pinMode(i, OUTPUT);
        digitalWrite(i, HIGH);
    }
}

void loop() {
    if(Serial.available()){
        int number = Serial.parseInt();
        bool *desiredLEDs = get_array_whether_use_LED(number, countLed);
        Serial.println(number);
        light_off(startPin, endPin);
        light_on(a, startPin, endPin);
    }
}

void light_on(bool* desiredLEDs, int startPin, int endPin)
{
    for (int i = startPin; i < endPin; i++){
        if (desiredLEDs[i - startPin]){
            digitalWrite(i, LOW);
        }
    }
}

void light_off(int startPin, int endPin)
{
    for (int i = startPin; i < endPin; i++){
        digitalWrite(i, HIGH);
    }
}

bool * get_array_whether_use_LED(int number, int numberBinaryDigits)
{
    bool* result = new bool[numberBinaryDigits];
    for(int i = 0; i < numberBinaryDigits; i++)
    {
        result[i] = number % 2 == 1;
        number /= 2;
    }
    return result;
}