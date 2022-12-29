
#include "Config.hpp"

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

  Serial.begin(SERIAL_SPEED);
}
uint8_t color{};
uint16_t VAL;

void loop() {
  int CLAP = analogRead(SOUND_PIN);

  /* читаємо дані з ножок */
  if (CLAP > CLAP_LEVEL) // фото затемнено
    color++;

    //   }
#ifdef SEVEN_COLORS
  if (color >= MAX_COLOR)
    color = 0; // < типу переповнення
  set_leds(color);
#else
  switch (color) {
  case 1:
    set_leds(LEDS_WHITE);
    break; // < типу переповнення
  default:
    set_leds(LEDS_OFF);
    color = 0; // < типу переповнення
    break;
  }
#endif
  delay(WAIT0_25);
}
