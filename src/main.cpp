#include <Arduino.h>
#include <Servo.h>
#include <WTV020SD16P.h>
// #include <celeste.h>
// #include <porteiro.h>
#include <gato.h>

// Defina os pinos para os servos
const int pinOlho = 9;
const int pinBoca = 10;
const int pinPescoco = 11;

Servo olho;
Servo boca;
Servo pescoco;


static const uint8_t resetPin = 2; // The pin number of the reset pin.
static const uint8_t clockPin = 6; // The pin number of the clock pin.
static const uint8_t dataPin = 7; // The pin number of the data pin.
static const uint8_t busyPin = 5; // The pin number of the busy pin.

WTV020SD16P wtv020sd16p(resetPin, clockPin,dataPin,busyPin);



void setup() 
{
  // Inicialize os servos
  olho.attach(pinOlho);
  boca.attach(pinBoca);
  pescoco.attach(pinPescoco);
  
  wtv020sd16p.asyncPlayVoice(0);

  
}

void loop() {
  wtv020sd16p.asyncPlayVoice(0);
  delay(10);
  for (int n = 0; n < nFrames; n++) 
  {
    int anguloBoca = pgm_read_word(&frames[n][0]);
    int anguloOlho = pgm_read_word(&frames[n][1]);
    int anguloPescoco = pgm_read_word(&frames[n][2]);

    // Mova os servos para as posições corretas
    boca.write(anguloBoca);
    olho.write(anguloOlho);
    pescoco.write(anguloPescoco);

    // Aguarde um tempo (opcional) para que os servos alcancem as posições
    delay(30);
  }
  delay(10);
}
