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

        nomes_prop = {"x", "f(x)", "Err x", "Convergiu", "Rompimento"};
    }

int QuadroComparativo::tam_max()
{
    int maior = QPadrao_M.getTamanho();

    if(QPadrao_H.getTamanho() > maior) maior = QPadrao_H.getTamanho();
    if(QFL_H.getTamanho() > maior) maior = QFL_H.getTamanho();
    if(QFL_M.getTamanho() > maior) maior = QFL_M.getTamanho();

    return maior;
}

std::string QuadroComparativo::get_nome_prop(int i)
{
    return nomes_prop.at(i%nomes_prop.size());
}
