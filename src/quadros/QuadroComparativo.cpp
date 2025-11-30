#include "QuadroComparativo.h"

QuadroComparativo::QuadroComparativo(std::vector<double> coeficientes, double epsilon, double lambda, int interacao_max): 
    QPadrao_M(NEWTON_PADRAO_DER_CALC, coeficientes, epsilon, lambda),
    QPadrao_H(NEWTON_PADRAO_DER_NCALC, coeficientes, epsilon, lambda),
    QFL_M(NEWTON_COM_FL_DER_CALC, coeficientes, epsilon, lambda),
    QFL_H(NEWTON_COM_FL_DER_NCALC, coeficientes, epsilon, lambda)
    {
        QPadrao_M.iterar_total(interacao_max);
        QPadrao_H.iterar_total(interacao_max);
        QFL_M.iterar_total(interacao_max);
        QFL_H.iterar_total(interacao_max);
    }
