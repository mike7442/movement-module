#include <FastLED.h>

#define LED_PIN      10
#define MOTOR_EN_PIN 9
#define NUM_LEDS     6

CRGB leds[NUM_LEDS];

void setup() {
  Serial.begin(115200);
  delay(1000);
  
  // Блокируем моторы
  pinMode(MOTOR_EN_PIN, OUTPUT);
  digitalWrite(MOTOR_EN_PIN, HIGH);
  
  // Инициализируем ленту
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(100);
  
  FastLED.clear();
  FastLED.show();
}

void loop() {
  // Эффект 1: Бегающий огонек
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Red;
    FastLED.show();
    delay(200);
    leds[i] = CRGB::Black;
  }

  // Эффект 2: Все мигают одним цветом
  for (int c = 0; c < 4; c++) {
    CRGB color;
    switch(c) {
      case 0: color = CRGB::Green; break;
      case 1: color = CRGB::Blue; break;
      case 2: color = CRGB::Purple; break;
      case 3: color = CRGB::Yellow; break;
    }
    
    for (int i = 0; i < NUM_LEDS; i++) leds[i] = color;
    FastLED.show();
    delay(300);
    
    for (int i = 0; i < NUM_LEDS; i++) leds[i] = CRGB::Black;
    FastLED.show();
    delay(300);
  }

  // Эффект 3: Шахматка
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = (i % 2 == 0) ? CRGB::White : CRGB::Black;
  }
  FastLED.show();
  delay(500);
  
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = (i % 2 != 0) ? CRGB::White : CRGB::Black;
  }
  FastLED.show();
  delay(500);
  
  // Гасим всё
  for (int i = 0; i < NUM_LEDS; i++) leds[i] = CRGB::Black;
  FastLED.show();
  delay(500);
}
