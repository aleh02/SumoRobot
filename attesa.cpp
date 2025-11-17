#include <arduino.h>
#include "define_global.h"

void attesa(byte *flag_attesa)
{
  *flag_attesa = 1;
  digitalWrite(LED_1, 1);
  delay(1000);
  digitalWrite(LED_2, 1);
  digitalWrite(LED_1, 0);
  delay(1000);
  digitalWrite(LED_3, 1);
  digitalWrite(LED_2, 0);
  delay(1000);
  digitalWrite(LED_4, 1);
  digitalWrite(LED_3, 0);
  delay(1000);
  digitalWrite(LED_1, 1);
  digitalWrite(LED_2, 1);
  digitalWrite(LED_3, 1);
  digitalWrite(LED_4, 1);
  delay(1000);
  digitalWrite(LED_1, 0);
  digitalWrite(LED_2, 0);
  digitalWrite(LED_3, 0);
  digitalWrite(LED_4, 0);
}
