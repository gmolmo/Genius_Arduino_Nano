#ifndef GENIUS_H
#define GENIUS_H

#include<Arduino.h>

class Genius
{
    private:
        const int* pinoLeds;//vetor de leds
        const int* pinoBotoes;//vetor de botoes
        int pinoBuzzer;

    public:
        //construtor que recebe um vetor de leds, um vetor de botoes e o pino do buzzer    
        Genius(const int pinoLeds[], const int pinoBotoes[], int pinoBuzzer);

        //funcao que aguarda o pressionamento de um botao
        //retorna -1 caso nao seja apertado nenhum botao
        //ou retorna o botao lido
        int lerBotao();

        //funcao que inicializa todos os pinos e configs necessárias para o Arduino
        void iniciar();

        //funcao que aciona uma contagem para o inicio do jogo, com aviso luminoso e sonoro
        void avisoInicio();

        //funcao que pisca o led selecionado e aciona o buzzer em sincronia
        void ledBuzzer(int led,int duracao,int frequencias[]);//duracao pra dificuldades maiores
        
        //funcao que recebe a sequencia ja sorteada e exibe 
        void tocarSequencia(int sorteados[], int nSorteados, int frequencias[]);

        //funcao que espera uma jogada e retorna se ela foi correta ou nao
        bool recebeJogada(int rodada, int sequencia[]);

        //loop principal do jogo
        int loopJogo(int rodadas);

        //aviso sonoro e luminoso de fim de jogo, em caso de perder
        void gameOver();

        //funcao que aguarda o inicio do jogo, encerrando com o pressionar de qualquer botao
        int standby();


};

#endif