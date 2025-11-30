#define RAYGUI_IMPLEMENTATION
#include <iostream> 

#include "./interface/App.h"
#include "./quadros/QuadroComparativo.h"


int main(){
   int n; 
   cout << "Bem vindo! Digite o número de funções a serem inseridas: ";
   cin >> n;
   vector <QuadroComparativo> quadros;
   
   for(int i = 1; i <= n; ++i){
      cout << "\nFunção " << i << ":";
      cout << "\nDigite os quatro coeficientes (a3 a2 a1 a0)";
      double a3, a2, a1, a0;
      cin >> a3 >> a2 >> a1 >> a0;
      cout << "\nDigite epsilon, o lambda e o número de interações maxima (eps lamb lim): ";
      double epsilon, lambda; int limite;
      cin >> epsilon >> lambda >> limite;

      quadros.push_back(QuadroComparativo({a3, a2, a1, a0}, epsilon, lambda, limite));
   }
   
   App app(1080, 720);

   app.start();

   return 0;
}