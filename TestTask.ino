#include "Config.hpp"
  /*! @author Sam4uk
   *  @date 2022
   *  @version 0.1.demo
   */

void set_leds(uint8_t ledsmode) {
  digitalWrite(LED_RED, ledsmode & LED_RED_MASK);
  digitalWrite(LED_GREEN, ledsmode & LED_GREEN_MASK);
  digitalWrite(LED_BLUE, ledsmode & LED_BLUE_MASK);
}

// int silent{};

void setup() {
  /*
   * конфігуруємо плату для виведення
   */
  pinMode(LED_RED, OUTPUT);   // готуємо червону ножку
  pinMode(LED_GREEN, OUTPUT); // готуємо зелену ножку
  set_leds(LEDS_OFF); // провсяк випадок тушимо всі кольори (ножок піля
                      // завнтаження не визначено)

  /*
   * використаємо піни для живлення мікрофону
   */
  pinMode(MIC_VCC, OUTPUT);
  digitalWrite(MIC_VCC, HIGH);
  pinMode(MIC_GND, OUTPUT);
  digitalWrite(MIC_GND, LOW);
  pinMode(SOUND_PIN, INPUT);
}
uint8_t color{};

void loop() {
  /* читаємо дані з ножок */
  bool CLAP = digitalRead(SOUND_PIN);

  if (CLAP)
    color++;

#ifdef SEVEN_COLORS
  /*
   * Послідовно кольри
   */
  if (color >= MAX_COLOR)
    color = 0; // < типу переповнення
  set_leds(color);
#else
  /*
   * Довільно кольори
   */
  switch (color) {
  case 0:
    set_leds(LEDS_OFF);
    break;
  case 1:
    set_leds(LEDS_WHITE);
    break;
  case 2:
    set_leds(LEDS_GREEN);
    break;
  /* case NEXT:
    set_leds(LEDS_MODE);
    break;
  */
  default:
    set_leds(LEDS_OFF);
    color = 0; // < типу переповнення
    break;
  }
#endif
  delay(WAIT0_25);
}
