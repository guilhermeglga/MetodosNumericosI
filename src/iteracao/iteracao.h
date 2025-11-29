#ifndef iteracao_h
#define iteracao_h

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