#ifndef _CONFIG_H_PP_
#define _CONFIG_H_PP_ (22.12.22)

#define WAIT0_25 (10)

// Живлення мікрофону
//< Пін плюса мікрофону
#define MIC_VCC (10)
//< пін мінуса мікрофону
#define MIC_GND (9)
// Пін звуку
#define SOUND_PIN (8)

// Пін червоного
#define LED_RED (12)
//Пін зеленого
#define LED_GREEN (11)
//Пін синього
#define LED_BLUE (13)

// Налаштування бітової маски
#define LED_RED_MASK (1)
#define LED_GREEN_MASK (2)
#define LED_BLUE_MASK (4)

//Деякі коьори
#define LEDS_OFF (0)
#define LEDS_RED (LED_RED_MASK)
#define LEDS_GREEN (LED_GREEN_MASK)
#define LEDS_BLUE (LED_BLUE_MASK)
#define LEDS_COLOR1 ((1 << LED_GREEN_MASK) || (1 << LED_BLUE_MASK))
#define LEDS_COLOR2 ((1 << LED_RED_MASK) || (1 << LED_BLUE_MASK))
#define LEDS_COLOR3 ((1 << LED_RED_MASK) || (1 << LED_GREEN_MASK))
#define LEDS_WHITE                                                             \
  ((1 << LED_BLUE_MASK) | (1 << LED_GREEN_MASK) | (1 << LED_RED_MASK))

//Максимальна кіькість кольорів
#define MAX_COLOR (LEDS_WHITE + 1)

#define SEVEN_COLORS

#endif
