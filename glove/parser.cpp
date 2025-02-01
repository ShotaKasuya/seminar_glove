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
// Finger を文字列に変換する関数
String finger_to_string(Finger finger) {
    switch (finger) {
        case Finger::LThumb:  return "LThumb";
        case Finger::LIndex:  return "LIndex";
        case Finger::LMiddle: return "LMiddle";
        case Finger::LRing:   return "LRing";
        case Finger::LLittle: return "LLittle";
        case Finger::RThumb:  return "RThumb";
        case Finger::RIndex:  return "RIndex";
        case Finger::RMiddle: return "RMiddle";
        case Finger::RRing:   return "RRing";
        case Finger::RLittle: return "RLittle";
        default:              return "Unknown";
    }
}
Time millis2time(unsigned long time) {
  auto value = (unsigned int) time/100;
  return Time {value};
}
