#include "parser.h"

void update(Time dt);
void process_input(uint8_t input);

typedef struct {
  bool task_enabled;
  Time remain_length;
} Task;

const int FINGER_NUM = 10;
Task tasks[FINGER_NUM] = {{false, Time{0}}, {false, Time{0}}, {false, Time{0}},
                          {false, Time{0}}, {false, Time{0}}, {false, Time{0}},
                          {false, Time{0}}, {false, Time{0}}, {false, Time{0}},
                          {false, Time{0}}};


void setup() {
  Serial.begin(9600);
  Serial.println("Hello Arduino!");

  for (int i = 0; i < FINGER_NUM; i++) {
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW); // 初期状態をLOWに設定
  }
}

// 0.1秒に一回updateが呼ばれる
const unsigned int UPDATE_DELTA_TIME = 100;

void loop() {
  static Time prev_update_time = Time{0};
  auto time = millis2time(millis());
  auto dt = time - prev_update_time;
  prev_update_time = time;

  if (dt.time < UPDATE_DELTA_TIME) {
    delay(UPDATE_DELTA_TIME - dt.time);
  } else {
    Serial.println("update use over UPDATE_DELTA_TIME");
  }

  if (Serial.available()) {
    uint8_t input;
    input = Serial.read();
    process_input(input);
  }
  update(dt);
}

void update(Time dt) {
  for (int i = 0; i < FINGER_NUM; i++) {
    Task &task = tasks[i];
    if (task.task_enabled) {
      auto rem = task.remain_length - dt;
      if (rem.time == 0) {
        task.task_enabled = false;
        digitalWrite(i, LOW);
      }
    }
  }
}

void process_input(uint8_t input) {
  Packet packet = parse(input);
  FingerIndex idx = finger2idx(packet.finger);
  auto length = Time{packet.time};
  tasks[(int)idx] = Task{true, length};
  digitalWrite((int)idx, HIGH);
}
