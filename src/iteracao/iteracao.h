#ifndef ITERACAO_H
#define ITERACAO_H

struct iteracao{
    // informações para ambos os métodos
    double raiz;
    double funcaoNaRaiz;
    double erroEmX;
    double erroEmFX;
    bool parada; //se for true, significa que convergiu
    bool possivelRompimento; //se a corda rompeu

    // informações para o newtom com FL
    double derivadaDeFXw;
    bool modif;
};

#endif
