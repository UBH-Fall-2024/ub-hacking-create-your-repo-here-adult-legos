#include "roboLib.h"


void readAndParseSerial() {
  static boolean reading = false;
  static String dataBuffer = "";
  
  while (Serial.available() > 0) {
    char received = Serial.read();

    if (received == '<') {
      reading = true;
      dataBuffer = "";  // Clear the buffer for new data
    } else if (received == '>') {
      reading = false;
      parseData(dataBuffer);  // Parse the data once we reach the end marker
      dataBuffer = "";  // Clear the buffer after parsing
    } else if (reading) {
      dataBuffer += received;  // Add characters to buffer if within markers
    }
  }
}

void parseData(String data) {
  int index = 0;
  int startPos = 0;
  
  while (startPos >= 0 && index < maxNumbers) {
    int commaPos = data.indexOf(',', startPos);
    String numberString;

    if (commaPos == -1) {  // Last number in the line
      numberString = data.substring(startPos);
      startPos = -1;  // End the loop
    } else {
      numberString = data.substring(startPos, commaPos);
      startPos = commaPos + 1;
    }

    numbers[index] = numberString.toFloat();  // Convert to float and store
    index++;
  }

  // Print parsed numbers (for testing purposes)
  Serial.println("Parsed numbers:");
  for (int i = 0; i < index; i++) {
    Serial.println(numbers[i]);
  }
}