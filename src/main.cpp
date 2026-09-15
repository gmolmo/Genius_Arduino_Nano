#include <Arduino.h>
#include "Genius.h"

const int pinoLeds[] = {6,5,4,3};
const int pinobotoes[] = {A5,A4,A3,A2,A1};
const int ledsdificuldade[] = {11,10,9};
int buzzer = 12;

int dificuldade;

Genius jogo(pinoLeds,pinobotoes,buzzer,ledsdificuldade);

void setup() {
    jogo.iniciar();
    int dificuldade = 0;
}

void loop() {

  int nRodadas = 5;

  dificuldade = jogo.standby();

  switch (dificuldade)
  {
  case 0:
    nRodadas = 5;
    break;
  case 1:
    nRodadas = 10;
    break;
  case 2:
    nRodadas = 15;
    break;
  default:
    nRodadas = 5;
    break;
  }

  jogo.avisoInicio();
  int resultado = jogo.loopJogo(nRodadas);

  if(resultado == 1)
    jogo.win();
  else
    jogo.gameOver();

  delay(1000);

}