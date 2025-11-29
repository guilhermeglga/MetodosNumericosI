//#define RAYGUI_IMPLEMENTATION
//
//#include "./interface/App.h"
//
//int main(){
//    App app(1080, 720);
//
//    app.start();
//
//    return 0;
//}

//#include "./metodos/Newton/NewtonPadrao/NewtonPadraoHorner.h"
#include "./metodos/Newton/NewtonFL/NewtonFLHorner.h"
#include <iostream>
#include <vector>

int main() {
    int n;
    double a3, a2, epsilon;
    std::cin >> n;
    std::vector<double> lambda(n);
    for (int i = 0; i < n; i++) std::cin >> lambda[i];
    std::cin >> a3 >> a2 >> epsilon;
    std::vector<double> vec_pol = {3, a2 * -9, 0, a3};
    Polinomio pol(vec_pol);
    double x0 = pol.isolamento();
    NewtonFLHorner newt(pol, x0, epsilon, n, lambda);
    for (int i = 0; i < 5; i++) {
        std::cout << "O xk atual eh " << newt.get_xk_atual() << std::endl;
        newt.iterar();
    }
    return 0;
}
