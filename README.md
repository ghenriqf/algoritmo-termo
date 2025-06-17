# Algoritmo do Jogo Termo – Trabalho de Algoritmos e Programação

Este projeto é um algoritmo básico desenvolvido em grupo como parte da disciplina de **Algoritmos e Programação**. O programa simula uma versão simplificada do popular jogo **Termo**, onde o jogador tenta adivinhar uma palavra com base em dicas de letras.

## Objetivo

O projeto tem como foco aplicar conceitos fundamentais da programação em C++, como:

- Leitura de arquivos (`ifstream`)
- Controle de fluxo (`if`, `while`, `for`)
- Funções e modularização
- Manipulação de strings e datas
- Interação com o terminal (uso de cores e efeitos)

## Requisitos

Para compilar e executar corretamente este projeto, é **necessário utilizar uma versão moderna do compilador G++**, recomendada **versão 11 ou superior**, pois o código faz uso de recursos das bibliotecas `<chrono>` e `<thread>`.

### Verificando a versão do G++ instalada:

```bash
g++ --version
```

Caso esteja usando uma versão antiga, atualize seu compilador para evitar erros de compilação.

## Estrutura do Projeto

- `main.cpp` – Arquivo principal com o código-fonte
- `palavras.csv` – Lista de palavras utilizadas no jogo

## Como Compilar e Executar no Windows

### 1. Compile o código com G++:

```bash
g++ -std=c++17 -o programa.exe main.cpp
```

> O uso da flag `-std=c++17` (ou superior) é **obrigatório** para garantir compatibilidade com os recursos modernos da linguagem.

### 2. Execute o programa:

```bash
programa.exe
```

> Você pode rodar o arquivo diretamente no terminal (cmd ou PowerShell), ou dando duplo clique no `programa.exe`.

## Participantes

Projeto desenvolvido por [**Gabriel Henrique, João Matheus, Murilo Pavanello**]  
