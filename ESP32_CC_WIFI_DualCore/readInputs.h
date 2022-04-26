#include "variables.h"

float read_Avg(const byte pin, uint16_t valBuffer[], const int buf_len, byte *buffer_i, const float cal, const float shunt) {
  valBuffer[(*buffer_i)++] = analogRead(pin);
  if(*buffer_i >= buf_len){
    *buffer_i = 0;
  }
  
  uint32_t currentSum = 0;
  for (int i = 0; i <= buf_len; ++i) {
    currentSum += valBuffer[i];
  }
  return (float)(currentSum / (buf_len * cal * shunt));
}

float read_Avg(const byte pin, uint16_t valBuffer[], const int buf_len, byte *buffer_i, const float cal) {
  valBuffer[(*buffer_i)++] = analogRead(pin);
  if(*buffer_i >= buf_len){
    *buffer_i = 0;
  }
  
  uint32_t voltageSum = 0;
  for (int i = 0; i <= buf_len; ++i) {
    voltageSum += valBuffer[i];
  }
  return (float)(voltageSum / (buf_len * cal));
}

float read_Avg(const byte pin, uint16_t valBuffer[], const int buf_len, byte *buffer_i) {
  valBuffer[(*buffer_i)++] = analogRead(pin);
  if(*buffer_i >= buf_len){
    *buffer_i = 0;
  }
  
  uint32_t voltageSum = 0;
  for (int i = 0; i <= buf_len; ++i) {
    voltageSum += valBuffer[i];
  }
  return (float)(voltageSum / buf_len);
}

//readPulse digital
bool readPulse(const byte pin){
  return digitalRead(pin);
}
