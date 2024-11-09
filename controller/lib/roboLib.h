#ifndef SERIALPARSER_H
#define SERIALPARSER_H

#include <Arduino.h>

const int maxNumbers = 10;   // Adjust based on the maximum expected numbers
extern float numbers[maxNumbers];  // Declare the array as external to be defined in the .cpp file

void readAndParseSerial();
void parseData(String data);

#endif