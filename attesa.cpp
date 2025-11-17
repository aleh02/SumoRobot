#include <Arduino.h>
#include "define_global.h"

// Effetto countdown sui LED prima dell'avvio
void attesa(byte *flag_attesa)
{
  *flag_attesa = 1;

  const byte leds[] = {LED_1, LED_2, LED_3, LED_4};

  // Accendi a "corsa" i LED uno alla volta
  for (byte i = 0; i < 4; i++)
  {
    // Spegni tutti
    for (byte j = 0; j < 4; j++)
    {
      digitalWrite(leds[j], LOW);
    }

    // Accendi quello giusto
    digitalWrite(leds[i], HIGH);
    delay(1000);
  }

  // Tutti ON per 1 secondo
  for (byte i = 0; i < 4; i++)
  {
    digitalWrite(leds[i], HIGH);
  }
  delay(1000);

  // Tutti OFF
  for (byte i = 0; i < 4; i++)
  {
    digitalWrite(leds[i], LOW);
  }
}
