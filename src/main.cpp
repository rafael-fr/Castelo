#include <Arduino.h>
#include <Servo.h>
#include <WTV020SD16P.h>

// #include <DFRobotDFPlayerMini.h>
// #include <SoftwareSerial.h>

// #include <porteiro/porteiro1.h>
// #include <porteiro/porteiro2.h>
// #include <porteiro/porteiro3.h>
// #include <porteiro/porteiro4.h>
// #include <porteiro/porteiro5.h>
// #include <porteiro/porteiro6.h>
// // // Defina os pinos para os servos
// const int pinOlho = 11;     //porteiro 
// const int pinBoca = 9;    //porteiro 
// const int pinPescoco = 10; //porteiro 

// const int angulos_default[3] = {50,90,90};

#include <porteiro2/porteiro1.h>
#include <porteiro2/porteiro2.h>
#include <porteiro2/porteiro3.h>
#include <porteiro2/porteiro4.h>
#include <porteiro2/porteiro5.h>
#include <porteiro2/porteiro6.h>

// // Defina os pinos para os servos
const int pinOlho = 9;     //porteiro 
const int pinBoca = 10;    //porteiro 
const int pinPescoco = 11; //porteiro 

const int angulos_default[3] = {130,120,115}; // BOCA - OLHO - PESCOCO

// #include <gato/gato1.h>
// #include <gato/gato2.h>
// #include <gato/gato3.h>
// #include <gato/gato4.h>
// // #include <gato/gato5.h>

// // Defina os pinos para os servos
// const int pinOlho = 11;     //gato 
// const int pinBoca = 10;      //gato 
// const int pinPescoco = 9;  //gato 

// const int angulos_default[3] = {60,87,90};


// #include <celeste/celeste1.h>
// #include <celeste/celeste2.h>
// #include <celeste/celeste3.h>
// #include <celeste/celeste4.h>
// #include <celeste/celeste5.h>

// // Defina os pinos para os servos
// const int pinOlho = 10;     //celeste
// const int pinBoca = 9;      //celeste
// const int pinPescoco = 11;  //celeste

// const int angulos_default[3] = {50,80,80};

// #include <celeste2/celeste1.h>
// #include <celeste2/celeste2.h>
// #include <celeste2/celeste3.h>
// #include <celeste2/celeste4.h>
// #include <celeste2/celeste5.h>

// // // Defina os pinos para os servos
// const int pinOlho = 10;     //celeste
// const int pinBoca = 9;      //celeste
// const int pinPescoco = 11;  //celeste

// const int angulos_default[3] = {170,125,85}; // BOCA - OLHO - PESCOCO

const int num_cena = 5;
const int delay_cena = 15000;

Servo olho;
Servo boca;
Servo pescoco;

// ===== WTV020SD16P =====
static const uint8_t resetPin = 4;   // The pin number of the reset pin.
static const uint8_t clockPin = 5;   // The pin number of the clock pin.
static const uint8_t dataPin = 6;    // The pin number of the data pin.
static const uint8_t busyPin = 7;    // The pin number of the busy pin.
WTV020SD16P wtv020sd16p(resetPin, clockPin, dataPin, busyPin);

// ===== DFPlayer Mini (Comentado) =====
// SoftwareSerial mySoftwareSerial(3, 2); // RX, TX
// DFRobotDFPlayerMini myDFPlayer;

int n, t, cena = 0;

int nframes, millis_frames=0;

int anguloBoca = angulos_default[0];
int anguloOlho = angulos_default[1];
int anguloPescoco = angulos_default[2];

void setup() 
{
    // ===== WTV020SD16P Initialization =====
    wtv020sd16p.reset();
  
  Serial.begin(9600);
  Serial.println("Inicializando");
  delay(1000);
  
    // ===== DFPlayer Mini Initialization (Comentado) =====
    // mySoftwareSerial.begin(9600);
    // if (!myDFPlayer.begin(mySoftwareSerial)) {
    //   //Serial.println(F("DFPlayer Mini nao iniciou corretamente!"));
    //   while(1);
    // }
    //Serial.println(F("DFPlayer Mini inicializado com sucesso"));
  
    // Configurações do DFPlayer (comentadas)
    // myDFPlayer.volume(25); // Define volume (0-30)
    //myDFPlayer.EQ(DFPLAYER_EQ_NORMAL);
    //myDFPlayer.outputDevice(DFPLAYER_DEVICE_SD);
  
    // Reproduz arquivo inicial (cena 1) - comentado
    // myDFPlayer.play(1);
    // delay(1000);
  
    // WTV calls removed — using DFPlayer
  
//   Inicialize os servos
  boca.attach(pinBoca);
  olho.attach(pinOlho);
  pescoco.attach(pinPescoco);
  delay(10);
  boca.write(angulos_default[0]);    // celeste 170  fechado 120 aberto              |celeste 35  fechado 75 aberto              |  Gato 60  fechado 100 aberto             |  Porteiro: 50 fechado 80 aberto
  olho.write(angulos_default[1]);     //celeste 150 fechado 125 aberto              |celeste 110 fechado 70 aberto              |  Gato 121 fechado 87 aberto              |  Porteiro:85 aberto 130 fechado
  pescoco.write(angulos_default[2]); // celeste 50  esquerda 130 direita 85 centro |celeste 60  esquerda 110 direita 85 centro | Gato 45  esquerda 125 direita 80 centro  |  Porteiro:50 esquerda 130 direita 90 centro
  delay(5000);

}
void loop() {
    for( cena = 1;cena<=num_cena;cena++)
    {   
        if (cena == 4){cena=5;};
        // cena = 4;
        Serial.println("Cena: " + String(cena));
        switch (cena)
        {
        case 1:
            nframes = nFrames1;
            millis_frames = millis_frames1;
            break;
        case 2:
            nframes = nFrames2;
            millis_frames = millis_frames2;
            break;
        case 3:
            nframes = nFrames3;
            millis_frames = millis_frames3;
            break;
        case 4:
            nframes = nFrames4;
            millis_frames = millis_frames4;
            break;
        case 5:
            nframes = nFrames5;
            millis_frames = millis_frames5;
            break;
        // case 6:
        //     nframes = nFrames6;
        //     millis_frames = millis_frames6;
        //     break;
        
        default:
            break;
        }
        
        // ===== WTV020SD16P play =====
        wtv020sd16p.asyncPlayVoice(cena);
        
        // delay(10);
        t=millis();
        for (n=0; n < nframes; n++)
        {
            // Serial.println(millis()-t);
            // t = millis();
            switch (cena)
            {
            case 1:
                anguloBoca = pgm_read_word(&frames1[n][0]);
                anguloOlho = pgm_read_word(&frames1[n][1]);
                anguloPescoco = pgm_read_word(&frames1[n][2]);
                break;
            case 2:
                anguloBoca = pgm_read_word(&frames2[n][0]);
                anguloOlho = pgm_read_word(&frames2[n][1]);
                anguloPescoco = pgm_read_word(&frames2[n][2]);
                break;
            case 3:
                anguloBoca = pgm_read_word(&frames3[n][0]);
                anguloOlho = pgm_read_word(&frames3[n][1]);
                anguloPescoco = pgm_read_word(&frames3[n][2]);
                break;
            case 4:
                anguloBoca = pgm_read_word(&frames4[n][0]);
                anguloOlho = pgm_read_word(&frames4[n][1]);
                anguloPescoco = pgm_read_word(&frames4[n][2]);
                break;
            case 5:
                anguloBoca = pgm_read_word(&frames5[n][0]);
                anguloOlho = pgm_read_word(&frames5[n][1]);
                anguloPescoco = pgm_read_word(&frames5[n][2]);
                break;
            // case 6:
            //     anguloBoca = pgm_read_word(&frames6[n][0]);
            //     anguloOlho = pgm_read_word(&frames6[n][1]);
            //     anguloPescoco = pgm_read_word(&frames6[n][2]);
            //     break;
            
            default:
                anguloBoca = angulos_default[0];
                anguloOlho = angulos_default[1];
                anguloPescoco = angulos_default[2];
                break;
            }
            // anguloBoca = angulos_default[0];
            // anguloOlho = angulos_default[1];
            // anguloPescoco = angulos_default[2];
            // Mova os servos para as posições corretas
            boca.write(anguloBoca);
            olho.write(anguloOlho);
            pescoco.write(anguloPescoco);
            // Serial.println("Frame: " + String(n) + " - Boca: " + String(anguloBoca) + " - Olho: " + String(anguloOlho) + " - Pescoco: " + String(anguloPescoco));
            // Aguarde um tempo (opcional) para que os servos alcancem as posições
            delay(millis_frames);
        }
        boca.write(angulos_default[0]);    // celeste 170  fechado 120 aberto              |celeste 35  fechado 75 aberto              |  Gato 60  fechado 100 aberto             |  Porteiro: 50 fechado 80 aberto
        olho.write(angulos_default[1]);     //celeste 150 fechado 125 aberto              |celeste 110 fechado 70 aberto              |  Gato 121 fechado 87 aberto              |  Porteiro:85 aberto 130 fechado
        pescoco.write(angulos_default[2]); // celeste 50  esquerda 130 direita 85 centro |celeste 60  esquerda 110 direita 85 centro | Gato 45  esquerda 125 direita 80 centro  |  Porteiro:50 esquerda 130 direita 90 centro
  
        
        // Serial.println(millis()-t);
        // Serial.print("Scene: ");
        // Serial.print(cena);
        // Serial.print(" - frames: ");
        // Serial.print(n);
        // Serial.print(" - Millis: ");
        // Serial.println(millis_frames);
        // delay(5000);
        
        // ===== WTV020SD16P stop (opcional) =====
        // wtv020sd16p.stopVoice();
        wtv020sd16p.asyncPlayVoice(0);
        delay(delay_cena);
    }
    // delay(100);
}

