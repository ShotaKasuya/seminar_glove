#ifndef PARSER_H
#define PARSER_H

#include <Arduino.h>

enum class Finger {
  LThumb = 0b0001,
  LIndex = 0b0010,
  LMiddle = 0b0011,
  LRing = 0b0100,
  LLittle = 0b0101,

  RThumb = 0b1001,
  RIndex = 0b1010,
  RMiddle = 0b1011,
  RRing = 0b1100,
  RLittle = 0b1101,
};
String finger_to_string(Finger finger);

enum class FingerIndex {
  LThumb,
  LIndex,
  LMiddle,
  LRing,
  LLittle,

  RThumb,
  RIndex,
  RMiddle,
  RRing,
  RLittle,
};

typedef struct {
  Finger finger;
  unsigned int time;
  String to_string() const {
        return "Packet{finger: " + finger_to_string(finger) + ", time: " + String(time) + "}";
    }
} Packet;

typedef struct Time {
  unsigned int time;

  Time operator-(const Time &other) const {
    Time result;
    if (time >= other.time) {
      result.time = time - other.time;
    } else {
      result.time = 0;
    }
    return result;
  }
} Time;

Packet parse(uint8_t packet);
FingerIndex finger2idx(Finger finger);
Time millis2time(unsigned long time);

#endif
