#include <arduino.h>
#include "define_global.h"
#include "motore.h"

void vista(void)
{
  int sh_sx = analogRead(A2);
  int sh_dx = analogRead(A3);
  if (sh_sx > 400 && sh_dx > 400)
  {
    digitalWrite(LED_4, 0);
    digitalWrite(LED_3, 0);
    digitalWrite(LED_3, 1);
    avanti();
  }
  else if (sh_dx > 400)
  {    
    digitalWrite(LED_4, 0);
    digitalWrite(LED_3, 0);
    digitalWrite(LED_3, 1);
    destra();
  }
  else if (sh_sx > 400)
  {
    digitalWrite(LED_4, 0);
    digitalWrite(LED_3, 0);
    digitalWrite(LED_3, 1);
    sinistra();
  }
  else
  {
    digitalWrite(LED_4, 0);
    digitalWrite(LED_3, 0);
    digitalWrite(LED_3, 1);
    avanti();
  }

}

