#include <Arduino.h>
#include "attesa.h"
#include "define_global.h"
#include "motore.h"
#include "vista.h"

byte flag_avvio = 0;

void setup()
{
  // LED
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
  pinMode(LED_4, OUTPUT);

  // Motore 1
  pinMode(MOT1A, OUTPUT);
  pinMode(MOT1B, OUTPUT);
  pinMode(MOT1EN, OUTPUT);

  // Motore 2
  pinMode(MOT2A, OUTPUT);
  pinMode(MOT2B, OUTPUT);
  pinMode(MOT2EN, OUTPUT);

  // Pulsante di start
  pinMode(BOT, INPUT_PULLUP);

  // Sensori linea (li leggi in analogico, pinMode non serve ma non fa danni)
  pinMode(CNYSX, INPUT);
  pinMode(CNYDX, INPUT);

  // Sharp (analog input)
  pinMode(SHSX, INPUT);
  pinMode(SHDX, INPUT);

  // Serial.begin(9600); // utile per debug
}

void loop()
{
  // Lettura pulsante di avvio (attivo LOW)
  byte bottone = digitalRead(BOT);

  // Se premi il pulsante e non stai già correndo → attesa & countdown
  if (!bottone && !flag_avvio)
  {
    attesa(&flag_avvio);
  }
  else if (flag_avvio)
  {
    // Lettura sensori CNY con soglia (nero=0, bianco=1)
    const int SOGLIA_CNY = 50;

    byte cny_sx = (analogRead(CNYSX) < SOGLIA_CNY) ? 0 : 1;
    byte cny_dx = (analogRead(CNYDX) < SOGLIA_CNY) ? 0 : 1;

    // LOGICA DI GARA SUMO
    if (!cny_sx && !cny_dx)
    {
      // Entrambi vedono il bordo → indietro + rotazione per rientrare
      indietro();
      delay(TEMPO_INDIETRO);

      rot_sinistra();
      delay(TEMPO_ROTAZIONE);
    }
    else if (!cny_sx)
    {
      // Bordo a sinistra → correggi verso destra
      rot_destra();
      delay(TEMPO_GIRO);
    }
    else if (!cny_dx)
    {
      // Bordo a destra → correggi verso sinistra
      rot_sinistra();
      delay(TEMPO_GIRO);
    }
    else
    {
      // Nessun bordo → usa gli Sharp per cercare l’avversario
      vista();
    }
  }
}
