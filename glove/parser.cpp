#include "parser.h"

Packet parse(uint8_t packet) {
  Finger finger = (Finger)(packet >> 4);
  unsigned int time = packet & 0x0F;

  return Packet{finger, time};
}

FingerIndex finger2idx(Finger finger) {
  FingerIndex value;

  switch (finger) {
  case Finger::LThumb:
    value = FingerIndex::LThumb;
    break;
  case Finger::LIndex:
    value = FingerIndex::LIndex;
    break;
  case Finger::LMiddle:
    value = FingerIndex::LMiddle;
    break;
  case Finger::LRing:
    value = FingerIndex::LRing;
    break;
  case Finger::LLittle:
    value = FingerIndex::LLittle;
    break;
  case Finger::RThumb:
    value = FingerIndex::RThumb;
    break;
  case Finger::RIndex:
    value = FingerIndex::RIndex;
    break;
  case Finger::RMiddle:
    value = FingerIndex::RMiddle;
    break;
  case Finger::RRing:
    value = FingerIndex::RRing;
    break;
  case Finger::RLittle:
    value = FingerIndex::RLittle;
    break;
  default:
    break;
  }
  return value;
}

Time millis2time(unsigned long time) {
  auto value = (unsigned int) time/100;
  return Time {value};
}
