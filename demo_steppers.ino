#include <GyverStepper.h>

#define ENA_PIN 9

GStepper<STEPPER2WIRE> m1(800, 1, 0);
GStepper<STEPPER2WIRE> m2(800, 2, 3);
GStepper<STEPPER2WIRE> m3(800, 6, 5);

void setup() {
  pinMode(ENA_PIN, OUTPUT);
  digitalWrite(ENA_PIN, LOW);

  for (auto* s : { &m1, &m2, &m3 }) {
    s->setRunMode(FOLLOW_POS);
    s->setAcceleration(3000);
    s->setMaxSpeed(3000);
  }

  m1.setTarget(10000);
  m2.setTarget(10000);
  m3.setTarget(10000);
}

void loop() {
  // Тикаем ОДИН раз и сохраняем результаты
  bool t1 = m1.tick();
  bool t2 = m2.tick();
  bool t3 = m3.tick();

  // Проверяем по сохранённым значениям
  if (!t1 && !t2 && !t3) {
    static bool dir = true;
    dir = !dir;
    long pos = dir ? 10000 : -10000;
    m1.setTarget(pos);
    m2.setTarget(pos);
    m3.setTarget(pos);
  }
}
