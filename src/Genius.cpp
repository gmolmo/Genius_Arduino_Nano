#include "Genius.h"

Genius::Genius(const int leds[],const int botoes[],int buzzer)
{
    this->pinoLeds = leds;
    this->pinoBotoes = botoes;
    this->pinoBuzzer = buzzer;
}

void Genius::iniciar()
{
    for(int i = 0; i < 4; i++)
    {
        pinMode(pinoLeds[i],OUTPUT);
        pinMode(pinoBotoes[i],INPUT_PULLUP);
    }
    pinMode(pinoBuzzer,OUTPUT);
}

void Genius::testar()
{
    for(int i = 0; i < 4; i++)
    {
        digitalWrite(pinoLeds[i],HIGH);
        delay(200);
        digitalWrite(pinoLeds[i],LOW);
    }
    delay(200);
}

int Genius::lerBotao()
{
    for(int i = 0; i < 4; i++)
    {
        if(digitalRead(pinoBotoes[i])==LOW)
        {
            delay(50);
            while(digitalRead(pinoBotoes[i]) == LOW)
                delay(50);

            return i;
        }
    }
    return -1;
}