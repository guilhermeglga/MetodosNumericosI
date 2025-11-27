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
#include "./métodos/Newton/NewtonPadrao/NewtonPadraoHorner.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    double lambda, a3, a2, epsilon;
    cin >> n >> lambda >> a3 >> a2 >> epsilon;
    vector<double> vec_pol = {3, a2 * -9, 0, a3};
    Polinomio pol(vec_pol);
    double x0 = pol.isolamento();
    NewtonPadraoHorner newt(pol, x0, epsilon);
    for (int i = 0; i < 5; i++) {
        cout << "O xk atual eh " << newt.get_xk_atual() << endl;
        newt.iterar();
    }
    return 0;
}
