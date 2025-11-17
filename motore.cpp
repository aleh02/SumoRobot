#include <arduino.h>
#include "motore.h"
#include "define_global.h"

void avanti(void)
{
  motore(MOT1A, MOT1B, MOT1EN, 1, 255);
  motore(MOT2A, MOT2B, MOT2EN, 1, 255);
}
void indietro(void)
{
  motore(MOT1A, MOT1B, MOT1EN, -1, 255);
  motore(MOT2A, MOT2B, MOT2EN, -1, 255);
}
void destra(void)
{
  motore(MOT1A, MOT1B, MOT1EN, 0, 0);
  motore(MOT2A, MOT2B, MOT2EN, 1, 255);//destra
}
void sinistra(void)
{
  motore(MOT1A, MOT1B, MOT1EN, 1, 255);//sinistra
  motore(MOT2A, MOT2B, MOT2EN, 0, 0);
}
void rot_destra(void)
{
  motore(MOT1A, MOT1B, MOT1EN, -1, 255);
  motore(MOT2A, MOT2B, MOT2EN, 1, 255);//destra
}
void rot_sinistra(void)
{
  motore(MOT1A, MOT1B, MOT1EN, 1, 255);//sinistra
  motore(MOT2A, MOT2B, MOT2EN, -1, 255);
}
void motore(byte pin_a, byte pin_b, byte pin_en, char dir, byte vel)
{
  digitalWrite(pin_en, 1);
  switch (dir)
  {
    case 0:
      {
        digitalWrite(pin_a, 0);
        digitalWrite(pin_b, 0);

      }
      break;
    case 1:
      {
        digitalWrite(pin_a, 1);
        digitalWrite(pin_b, 0);
      }
      break;
    case -1:
      {
        digitalWrite(pin_a, 0);
        digitalWrite(pin_b, 1);
      }
      break;
  }
}

