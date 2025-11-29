#ifndef ITERACAO_H
#define ITERACAO_H

struct iteracao{
    // informações para ambos os métodos
    double raiz;
    double funcaoNaRaiz;
    double erroEmX;
    double erroEmFX;
    bool parada;

    // informações para o newtom com FL
    double derivadaDeFXw;
    bool possivelRompimento;
};

#endif
