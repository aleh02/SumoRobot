#include "attesa.h"
#include "define_global.h"
#include "motore.h"
#include "vista.h"

void setup(void)
{
  for (byte i = 2; i < 12; i++)
  {
    pinMode(i, OUTPUT);
  }
  pinMode(BOT, INPUT_PULLUP);
  pinMode(CNYSX, INPUT_PULLUP);
  pinMode(CNYDX, INPUT_PULLUP);
  pinMode(SHSX, INPUT);
  pinMode(SHDX, INPUT);
  //Serial.begin(9600);
}

byte flag_avvio = 0;

void loop()
{
  byte bottone = digitalRead(BOT);
  if (!bottone && !flag_avvio)
  {
    attesa(&flag_avvio);
  }
  else if (flag_avvio)
  {
    byte cny_sx;
    if (analogRead(CNYSX) < 50)
    {
      cny_sx = 0;
    }
    else
    {
      cny_sx = 1;
    }
    byte cny_dx;
    if (analogRead(CNYDX) < 50)
    {
      cny_dx = 0;
    }
    else
    {
      cny_dx = 1;
    }
    
    if (!cny_sx && !cny_dx)
    {
      indietro();
      delay(TEMPO_INDIETRO);
      rot_sinistra();
      delay(TEMPO_ROTAZIONE);
    }
    else if (!cny_sx)
    {
      rot_destra();
      delay(TEMPO_GIRO);
    }
    else if (!cny_dx)
    {
      rot_sinistra();
      delay(TEMPO_GIRO);
    }
    else
    {
      //usare gli sharp e ceracre l'avversario
      //avanti();
      vista();
    }
  }
}
