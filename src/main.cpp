#include <Arduino.h>
#include <Servo.h>
#include <WTV020SD16P.h>
// #include <celeste.h>
// #include <porteiro.h>
#include <porteiro/porteiro1.h>
#include <porteiro/porteiro2.h>
#include <porteiro/porteiro3.h>
#include <porteiro/porteiro4.h>
#include <porteiro/porteiro5.h>
#include <porteiro/porteiro6.h>

// Defina os pinos para os servos
const int pinOlho = 9;
const int pinBoca = 11;
const int pinPescoco = 10;

Servo olho;
Servo boca;
Servo pescoco;


static const uint8_t resetPin = 4; // The pin number of the reset pin.
static const uint8_t clockPin = 5; // The pin number of the clock pin.
static const uint8_t dataPin = 6; // The pin number of the data pin.
static const uint8_t busyPin = 7; // The pin number of the busy pin.

WTV020SD16P wtv020sd16p(resetPin, clockPin,dataPin,busyPin);

int n, t = 0;

void setup() 
{
  wtv020sd16p.reset();
  // Serial.begin(9600);
  delay(2000);
  wtv020sd16p.asyncPlayVoice(0);
  // Inicialize os servos
  olho.attach(pinOlho);
  boca.attach(pinBoca);
  pescoco.attach(pinPescoco);
  delay(10);
  boca.write(50); //50 fechado 80 aberto
  olho.write(90);  //85 aberto 130 fechado
  pescoco.write(90); //50 esquerda 130 direita 90 centro
  // delay(5000);
  
}

void loop() {
  wtv020sd16p.asyncPlayVoice(1);
  // delay(10);
  for (n=0; n < nFrames1; n++)
  {
      t = millis();
      int anguloBoca = pgm_read_word(&frames1[n][0]);
      int anguloOlho = pgm_read_word(&frames1[n][1]);
      int anguloPescoco = pgm_read_word(&frames1[n][2]);

      // Mova os servos para as posições corretas
      boca.write(anguloBoca);
      olho.write(anguloOlho);
      pescoco.write(anguloPescoco);
      // Aguarde um tempo (opcional) para que os servos alcancem as posições
      delay(millis_frames1);
      n++;
  }
  // wtv020sd16p.asyncPlayVoice(0);
  delay(10000);
  
  wtv020sd16p.asyncPlayVoice(2);
  for (n=0; n < nFrames2; n++)
  {
      t = millis();
      int anguloBoca = pgm_read_word(&frames2[n][0]);
      int anguloOlho = pgm_read_word(&frames2[n][1]);
      int anguloPescoco = pgm_read_word(&frames2[n][2]);

      // Mova os servos para as posições corretas
      boca.write(anguloBoca);
      olho.write(anguloOlho);
      pescoco.write(anguloPescoco);
      // Aguarde um tempo (opcional) para que os servos alcancem as posições
      delay(millis_frames2+1.2);
      n++;
  }
  // wtv020sd16p.asyncPlayVoice(0);
  delay(10000);
  
  wtv020sd16p.asyncPlayVoice(3);
  for (n=0; n < nFrames3; n++)
  {
      t = millis();
      int anguloBoca = pgm_read_word(&frames3[n][0]);
      int anguloOlho = pgm_read_word(&frames3[n][1]);
      int anguloPescoco = pgm_read_word(&frames3[n][2]);

      // Mova os servos para as posições corretas
      boca.write(anguloBoca);
      olho.write(anguloOlho);
      pescoco.write(anguloPescoco);
      // Aguarde um tempo (opcional) para que os servos alcancem as posições
      delay(millis_frames3+1.2);
      n++;
  }
  // wtv020sd16p.asyncPlayVoice(0);
  delay(10000);
  
  wtv020sd16p.asyncPlayVoice(4);
  for (n=0; n < nFrames4; n++)
  {
      t = millis();
      int anguloBoca = pgm_read_word(&frames4[n][0]);
      int anguloOlho = pgm_read_word(&frames4[n][1]);
      int anguloPescoco = pgm_read_word(&frames4[n][2]);

      // Mova os servos para as posições corretas
      boca.write(anguloBoca);
      olho.write(anguloOlho);
      pescoco.write(anguloPescoco);
      // Aguarde um tempo (opcional) para que os servos alcancem as posições
      delay(millis_frames4+1.2);
      n++;
  }
  // wtv020sd16p.asyncPlayVoice(0);
  delay(10000);
  
  wtv020sd16p.asyncPlayVoice(5);
  for (n=0; n < nFrames5; n++)
  {
      t = millis();
      int anguloBoca = pgm_read_word(&frames5[n][0]);
      int anguloOlho = pgm_read_word(&frames5[n][1]);
      int anguloPescoco = pgm_read_word(&frames5[n][2]);

      // Mova os servos para as posições corretas
      boca.write(anguloBoca);
      olho.write(anguloOlho);
      pescoco.write(anguloPescoco);
      // Aguarde um tempo (opcional) para que os servos alcancem as posições
      delay(millis_frames5+1.2);
      n++;
  }
  // wtv020sd16p.asyncPlayVoice(0);
  delay(10000);
  
  wtv020sd16p.asyncPlayVoice(6);
  for (n=0; n < nFrames6; n++)
  {
      t = millis();
      int anguloBoca = pgm_read_word(&frames6[n][0]);
      int anguloOlho = pgm_read_word(&frames6[n][1]);
      int anguloPescoco = pgm_read_word(&frames6[n][2]);

      // Mova os servos para as posições corretas
      boca.write(anguloBoca);
      olho.write(anguloOlho);
      pescoco.write(anguloPescoco);
      // Aguarde um tempo (opcional) para que os servos alcancem as posições
      delay(millis_frames6+1.2);
      n++;
  }
  delay(10000);
}
