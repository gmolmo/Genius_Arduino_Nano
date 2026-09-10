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
    noTone(pinoBuzzer);
}

void Genius::avisoInicio()
{
    int tomContagem = 349;
    int tomInicio = 698;

    for (int i = 0; i < 3; i++)
    {
        digitalWrite(pinoLeds[i], HIGH);
        tone(pinoBuzzer, tomContagem, 150);
        delay(150);
        digitalWrite(pinoLeds[i], LOW);
        delay(350);
    }

    for (int i = 0; i < 4; i++) 
    {
        digitalWrite(pinoLeds[i], HIGH);
    }
    tone(pinoBuzzer, tomInicio, 400);
    delay(400);

    for (int i = 0; i < 4; i++)
    {
        digitalWrite(pinoLeds[i], LOW);
    }
    delay(300);

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

int Genius::standby()
{
    for(int i = 0; i < 4; i++)//inicializa leds apagados
        digitalWrite(pinoLeds[i], LOW);

    while (true)//inicia o loop que faz:
    {
        for(int i = 0; i < 4; i++)
            digitalWrite(pinoLeds[i], HIGH);//acende os leds

        for(int m = 0; m < 5000; m++)//verifica se tem botao clicado
        {
            int botao = lerBotao();
            if(botao != -1)
            {
                for(int i = 0; i < 4; i++)
                digitalWrite(pinoLeds[i], LOW);//se tiver, desliga tudo e retorna

                return 1;
            }
        }
        delay(10);
        for(int i = 0; i < 4; i++)
            digitalWrite(pinoLeds[i], LOW);// se nao apaga e verifica de novo
        delay(10);

        for(int m = 0; m < 5000; m++)
        {
            int botao = lerBotao();
            if(botao != -1)
            {
                for(int i = 0; i < 4; i++)
                digitalWrite(pinoLeds[i], LOW);

                return 1;
            }
        }
    }
}