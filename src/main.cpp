#include <Arduino.h>
#include <Servo.h>
#include <WTV020SD16P.h>

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

int nFrames = 500;
int frames[500][3] = {0,0,0};

void setup() 
{
  // Inicialize os servos
  olho.attach(pinOlho);
  boca.attach(pinBoca);
  pescoco.attach(pinPescoco);
  
  wtv020sd16p.asyncPlayVoice(0);

  for (int n = 0; n < nFrames; n++) 
  {
    int anguloBoca = frames[n][0];
    int anguloOlho = frames[n][1];
    int anguloPescoco = frames[n][2];

    // Mova os servos para as posições corretas
    boca.write(anguloBoca);
    olho.write(anguloOlho);
    pescoco.write(anguloPescoco);

    // Aguarde um tempo (opcional) para que os servos alcancem as posições
    delay(30);
  }
}

void loop() {
  // Seu código principal aqui (se necessário)
}
