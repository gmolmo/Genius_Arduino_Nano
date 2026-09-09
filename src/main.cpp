#include <Arduino.h>
#include "Genius.h"

const int pinoLeds[] = {5,6,10,11};
const int pinobotoes[] = {2,3,8,12};
int buzzer = 4;

Genius jogo(pinoLeds,pinobotoes,buzzer);

void setup() {
    jogo.iniciar();

}

void loop() {
  int pressionado = -1;

  while (pressionado == -1)
  {
    pressionado = jogo.lerBotao();
  }
  
  jogo.testar();
}