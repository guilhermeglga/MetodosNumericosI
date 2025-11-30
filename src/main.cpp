#define RAYGUI_IMPLEMENTATION
#include <iostream> 

#include "./interface/App.h"
#include "./quadros/QuadroComparativo.h"


int main(){
   int n; 
   cout << "Bem vindo! Digite o número de funções a serem inseridas: ";
   cin >> n;
   bool modo;
   cout << "\nDigite agora o modo da função (0: função generica, 1: a3x^3 - 9a2x + 3)";
   cin >> modo;
   vector <QuadroComparativo*> quadros;
   
   cout << "\n";
   for(int i = 1; i <= n; ++i){
      cout << "Função " << i << ":\n";
      double a3, a2, a1, a0;
      if (modo){
         cout << "Digite os dois coeficientes (a3 a2): ";
         cin >> a3 >> a1;
         a2 = 0, a0 = 0, a1 *= -9;
      }
      else {
         cout << "Digite os quatro coeficientes (a3 a2 a1 a0): ";
         cin >> a3 >> a2 >> a1 >> a0;
      }

      cout << "\nDigite epsilon, o lambda e o número de interações maxima (eps lamb lim): ";
      double epsilon, lambda; int limite;
      cin >> epsilon >> lambda >> limite;

      quadros.push_back(&QuadroComparativo({a3, a2, a1, a0}, epsilon, lambda, limite));
      cout << "\n";
   }

   App app(1080, 720);

   app.start();

   return 0;
}