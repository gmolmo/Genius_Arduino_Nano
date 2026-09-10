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
    digitalWrite(pinoLeds[led],HIGH);
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

        ledBuzzer(pressionado,200,frequencias);//aciona o led e o buzzer do botao

        if(pressionado != sequencia[jogada])//caso a jogada tenha sido incorreta, retorna falso
        {
            return false;
        }
    }
    return true;//caso contrario, verdadeiro
}

int Genius::loopJogo(int rodadas)
{
    int frequencias[] = {262,294,330,349};
    int rodadas_jogadas = 0;
    int sequenciaCorreta[rodadas];
    int duracao = 300;
    randomSeed(analogRead(A0));//aleatorizando a sequencia com estrategia do gemini

    for(int i = 0; i < rodadas; i++)
        sequenciaCorreta[i] = random(0,4);//preenche o vetor com numeros entre 0 e 3

    delay(500);
    while (true)//loop principal do jogo;  
    {
        for(int i = 0; i <= rodadas_jogadas; i++)
        {
            ledBuzzer(sequenciaCorreta[i],duracao,frequencias);
            delay(300);
        }
        bool correto = recebeJogada(rodadas_jogadas,sequenciaCorreta);

        if(!correto)
        {
            return 0;
        }

        rodadas_jogadas++;

        if(rodadas_jogadas == rodadas)
            return 1;

        delay(700);
    }
    
}

void Genius::gameOver()
{
    int notasGameOver[] = {220, 196, 175, 146};
    int duracoes[] = {250, 250, 250, 500};

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            digitalWrite(pinoLeds[j], HIGH);
        }

        tone(pinoBuzzer, notasGameOver[i], duracoes[i]);
        delay(duracoes[i]);

        for (int j = 0; j < 4; j++) {
            digitalWrite(pinoLeds[j], LOW);
        }
        delay(80);
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

void Genius::win()
{
int notasVitoria[] = {523, 659, 784, 1046};
    int duracoes[] = {150, 150, 150, 400};

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            digitalWrite(pinoLeds[j], HIGH);
        }

        tone(pinoBuzzer, notasVitoria[i], duracoes[i]);
        delay(duracoes[i]);

        for (int j = 0; j < 4; j++) {
            digitalWrite(pinoLeds[j], LOW);
        }

        delay(60);
    }
}