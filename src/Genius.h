#ifndef GENIUS_H
#define GENIUS_H

#include<Arduino.h>

class Genius
{
    private:
        const int* pinoLeds;
        const int* pinoBotoes;
        int pinoBuzzer;

    public:
        Genius(const int pinoLeds[], const int pinoBotoes[], int pinoBuzzer);

        void iniciar();

        void testar();

        int lerBotao();

        int standby();
};

#endif