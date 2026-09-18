<h1 align="center"> 🎮🔵🟢 Genius / Simon - Arduino 🟡🔴🎮 </h1>

<div align="center">

<img loading="lazy" src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/cplusplus/cplusplus-original.svg" width="40" height="40"/> <img loading="lazy" src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/arduino/arduino-original.svg" width="40" height="40"/> <img loading="lazy" src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/vscode/vscode-original.svg" width="40" height="40"/> <img loading="lazy" src="https://cdn.simpleicons.org/platformio/F58220" width="40" height="40"/>

</div>

## Descrição do Projeto
O projeto consiste no desenvolvimento do clássico jogo de memória **Genius (ou Simon)** utilizando um **Arduino Nano**. O objetivo do jogo é memorizar e repetir a sequência aleatória de luzes e sons apresentada pelos LEDs e buzzer. É possível selecionar a quantidade de rodadas desejadas e, com o avançar do jogo, o tempo de exibição é diminuído para aumentar a dificuldade.

O desenvolvimento passou pelas etapas de prototipagem em protoboard, soldagem final dos componentes em uma placa perfurada e montagem em um case feito em impressão 3D (feito por membros antigos da **ERUS UFES**).
<div align="center">
<img width="150" src="https://github.com/gmolmo/Genius_Arduino_Nano/blob/main/midia/Fotos/prototipo1.jpeg"> <img width="200" src="https://github.com/gmolmo/Genius_Arduino_Nano/blob/main/midia/Fotos/soldando_placa.jpg"> <img width="200" src="https://github.com/gmolmo/Genius_Arduino_Nano/blob/main/midia/Fotos/montagem_final.jpg">
</div>

## ⚙️ Funcionamento

### Software
O código foi inteiramente programado em **C++** modularizado sob o conceito de **TAD (Tipo Abstrato de Dados)**. A estrutura foi dividida em três arquivos principais:
- `Genius.h`: Contém a definição da classe `Genius`, protótipos de métodos e atributos.
- `Genius.cpp`: Implementação da lógica do jogo, controle de som via buzzer, animações de LEDs (Início, Vitória e Game Over), gerenciamento de estados e leitura dos botões.
- `main.cpp`: Executa o setup e o loop principal com a máquina de estados do jogo.

O programa conta com **3 níveis de dificuldade** selecionáveis pelo botão de controle antes do início da partida, indicados por LEDs dedicados.

### Hardware
- **Arduino Nano**: Microcontrolador responsável pelo processamento da lógica.
- **LEDs Coloridos**: 4 LEDs para a sequência do jogo e 3 LEDs para indicação do nível de dificuldade.
- **Push Buttons**: 4 botões para entrada do jogador e 1 botão para seleção de dificuldade.
- **Buzzer Passivo**: Emite tons em frequências específicas para cada LED e reproduz os efeitos sonoros do jogo.
- **Placa Perfurada**: Circuito soldado para garantir durabilidade e conexões firmes.
- **Case 3D**: Case plástico impresso em 3D para abrigar a eletrônica.

## 🏗️ Ferramentas

### C++ / Arduino Framework <img loading="lazy" src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/cplusplus/cplusplus-original.svg" width="25" height="25"/>
Linguagem utilizada no desenvolvimento de toda a lógica do projeto, aplicando orientação a objetos básica e boa organização estrutural.

### PlatformIO (VS Code) <img loading="lazy" src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/vscode/vscode-original.svg" width="25" height="25"/> <img loading="lazy" src="https://cdn.simpleicons.org/platformio/F58220" width="25" height="25"/>
Ecossistema utilizado para compilação, gerenciamento de dependências e upload do código diretamente para o Arduino Nano através do Visual Studio Code.

## Instruções

Para compilar e enviar o projeto para o Arduino:

1. Certifique-se de ter o **VS Code** instalado com a extensão do **PlatformIO**.
2. Clone o repositório ou baixe o pacote completo de código.
3. Abra a pasta do projeto no VS Code.
4. Conecte o **Arduino Nano** à porta USB do seu computador.
5. Acesse a aba do **PlatformIO** na barra lateral e clique em **Upload** (ou utilize o atalho do VS Code).
