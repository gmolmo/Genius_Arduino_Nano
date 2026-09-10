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
    noTone(pinoBuzzer);//certeza de buzzer desligado ao iniciar
}

void Genius::avisoInicio()
{
    int tomContagem = 349;
    int tomInicio = 698;//escalas para o buzzer

    for (int i = 0; i < 3; i++)
    {
        digitalWrite(pinoLeds[i], HIGH);
        tone(pinoBuzzer, tomContagem, 150);//faz uma contagem rápida de 3 sinais sonoros
        delay(150);
        digitalWrite(pinoLeds[i], LOW);
        delay(350);
    }

    for (int i = 0; i < 4; i++) 
    {
        digitalWrite(pinoLeds[i], HIGH);//acende todos os leds
    }
    tone(pinoBuzzer, tomInicio, 400);//faz um ultimo aviso sonoro, mais longo
    delay(400);

    for (int i = 0; i < 4; i++)
    {
        digitalWrite(pinoLeds[i], LOW);//desliga todos os leds
    }
    delay(300);

}

void Genius::ledBuzzer(int led,int duracao,int frequencias[])//duracao pra dificuldades maiores
{
    digitalWrite(led,HIGH);
    tone(pinoBuzzer,frequencias[led],duracao);
    delay(duracao);//aciona o determinado led e buzzer no intervalo de tempo recebido, na frequencia de cada "led"
    digitalWrite(pinoLeds[led],LOW);
    noTone(pinoBuzzer);
}

void Genius::tocarSequencia(int sorteados[], int nSorteados,int frequencias[])
{
    for(int i = 0; i < nSorteados; i++)
    {
        ledBuzzer(sorteados[i],400,frequencias);
        delay(200);
    }
}

bool Genius::recebeJogada(int rodada, int sequencia[])
{
    int frequencias[] = {262,294,330,349};//cada led tem seu determinado tom

    for(int jogada = 0; jogada <= rodada; jogada++)
    {
        int pressionado = -1;

        while (pressionado == -1)//aguarda o pressionar de um botao
        {
            pressionado = lerBotao();
        }

        ledBuzzer(pinoLeds[pressionado],200,frequencias);//aciona o led e o buzzer do botao

        if(pressionado != sequencia[jogada])//caso a jogada tenha sido incorreta, retorna falso
        {
            return false;
        }
    }
    return true;//caso contrario, verdadeiro
}

int Genius::loopJogo(int rodadas)
{
       
}

void Genius::gameOver()
{
    for(int i = 0; i < 4; i++)
    {
        digitalWrite(pinoLeds[i],HIGH);
        delay(200);
        digitalWrite(pinoLeds[i],LOW);
    }
}

int Genius::lerBotao()
{
    for(int i = 0; i < 4; i++)
    {
        if(digitalRead(pinoBotoes[i])==LOW)
        {
            delay(50);
            while(digitalRead(pinoBotoes[i]) == LOW)//espera o jogador soltar o botao completamente 
                delay(50);

            return i;//retorna o botao pressionado
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