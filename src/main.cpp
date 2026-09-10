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

  int jogoComeca = jogo.standby();

  jogo.avisoInicio();

  if(jogoComeca == 1)
    jogo.gameOver();
}