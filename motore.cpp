#include <Arduino.h>
#include "motore.h"
#include "define_global.h"

// Muove entrambi i motori in avanti alla massima velocità
void avanti(void)
{
  motore(MOT1A, MOT1B, MOT1EN,  1, 255);
  motore(MOT2A, MOT2B, MOT2EN,  1, 255);
}

// Muove entrambi i motori indietro
void indietro(void)
{
  motore(MOT1A, MOT1B, MOT1EN, -1, 255);
  motore(MOT2A, MOT2B, MOT2EN, -1, 255);
}

// Curva verso destra: fermo motore sinistro, avanti motore destro
void destra(void)
{
  motore(MOT1A, MOT1B, MOT1EN, 0,   0);
  motore(MOT2A, MOT2B, MOT2EN, 1, 255); // destra
}

// Curva verso sinistra: avanti motore sinistro, fermo motore destro
void sinistra(void)
{
  motore(MOT1A, MOT1B, MOT1EN, 1, 255); // sinistra
  motore(MOT2A, MOT2B, MOT2EN, 0,   0);
}

// Rotazione sul posto verso destra
void rot_destra(void)
{
  motore(MOT1A, MOT1B, MOT1EN, -1, 255);
  motore(MOT2A, MOT2B, MOT2EN,  1, 255); // destra
}

// Rotazione sul posto verso sinistra
void rot_sinistra(void)
{
  motore(MOT1A, MOT1B, MOT1EN,  1, 255); // sinistra
  motore(MOT2A, MOT2B, MOT2EN, -1, 255);
}

// Funzione generica per controllare un motore
// dir: -1 = indietro, 0 = fermo, 1 = avanti
// vel: 0-255 (PWM su EN)
void motore(byte pin_a, byte pin_b, byte pin_en, int8_t dir, byte vel)
{
  switch (dir)
  {
    case 0: // stop
      digitalWrite(pin_a, LOW);
      digitalWrite(pin_b, LOW);
      analogWrite(pin_en, 0);
      break;

    case 1: // avanti
      digitalWrite(pin_a, HIGH);
      digitalWrite(pin_b, LOW);
      analogWrite(pin_en, vel);
      break;

    case -1: // indietro
      digitalWrite(pin_a, LOW);
      digitalWrite(pin_b, HIGH);
      analogWrite(pin_en, vel);
      break;
  }
}
