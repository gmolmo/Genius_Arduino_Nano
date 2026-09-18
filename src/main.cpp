#include <Arduino.h>
#include "Genius.h"

const int pinoLeds[] = {3,4,5,6};
const int pinobotoes[] = {A4,A3,A2,A1,A0};
const int ledsdificuldade[] = {10,11,12};
int buzzer = 13;

int dificuldade;

Genius jogo(pinoLeds,pinobotoes,buzzer,ledsdificuldade);

void setup() {
    jogo.iniciar();
}

void loop() {

  int nRodadas = 5;

  int dificuldade = 0;

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