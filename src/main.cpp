#include <Arduino.h>
#include "Genius.h"

const int pinoLeds[] = {5,6,10,11};
const int pinobotoes[] = {2,3,8,12};
int buzzer = 7;

Genius jogo(pinoLeds,pinobotoes,buzzer);

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