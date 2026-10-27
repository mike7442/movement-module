#include <FastLED.h>

#define LED_PIN 10
#define MOTOR_EN_PIN 9
#define NUM_LEDS 6

CRGB leds[NUM_LEDS];

// Массив цветов, из которых будем выбирать
CRGB colors[] = {
  CRGB::Red, CRGB::Green, CRGB::Blue,
  CRGB::Purple, CRGB::Yellow, CRGB::Cyan,
  CRGB::Magenta, CRGB::Orange, CRGB::White
};
const int numColors = sizeof(colors) / sizeof(colors[0]);

void setup() {
  Serial.begin(115200);
  randomSeed(analogRead(0));  // для случайных цветов

  pinMode(MOTOR_EN_PIN, OUTPUT);
  digitalWrite(MOTOR_EN_PIN, HIGH);

  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(100);

  FastLED.clear();
  FastLED.show();
}

void loop() {
  static int i = 0;
  static int c = 0;

  FastLED.clear();
  leds[i] = colors[c];
  FastLED.show();

  i++;
  if (i >= NUM_LEDS) {
    i = 0;
    c = (c + 1) % numColors;  // меняем цвет после полного прохода
  }
  delay(200);
}
