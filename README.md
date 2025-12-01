# MetodosNumericosI

Nosso trabalho de Métodos Numéricos

## Compilando e Usando o programa

Para compilar o programa você precisa ter um compilador de c++ e o programa make instalados, basta entrar na pasta do código fonte e rodar o comando:
``````bash
make
``````

para rodar:
``````bash
cd build
./MetodosNum
``````

O programa vai perguntar o seguinte: 
- Número de polinômios(n) que você vai querer inserir;
- Formato do polinômio que você vai querer inserir.

Então para cada polinômio o programa vai pedir:
- Coeficientes;
- Lambda.

## Código fonte

O código fonte está divido em pastas, com as implementações dos métodos em src/metodos/Newton, a interface está em src/interface.

A interface utiliza a biblioteca raylib, para criar a janela, receber inputs, e desenhar texto e formas. A raylib está inclusa no repositório como biblioteca estática.
