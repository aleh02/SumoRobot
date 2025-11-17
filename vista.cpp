#include <Arduino.h>
#include "define_global.h"
#include "motore.h"

#define SOGLIA_SHARP 400

// Usa gli Sharp per "vedere" l'avversario e decidere come muoversi
void vista(void)
{
  int sh_sx = analogRead(SHSX);
  int sh_dx = analogRead(SHDX);

  // LED di stato: ad esempio LED_3 acceso quando stiamo "cercando"
  digitalWrite(LED_4, LOW);
  digitalWrite(LED_3, HIGH);

  if (sh_sx > SOGLIA_SHARP && sh_dx > SOGLIA_SHARP)
  {
    // avversario davanti → vai dritto
    avanti();
  }
  else if (sh_dx > SOGLIA_SHARP)
  {    
    // avversario verso destra
    destra();
  }
  else if (sh_sx > SOGLIA_SHARP)
  {
    // avversario verso sinistra
    sinistra();
  }
  else
  {
    // nessun avversario rilevato: gira finché non trova l'avversario
    //avanti();
    rot_destra(); // o rot_sinistra();
  }
}
