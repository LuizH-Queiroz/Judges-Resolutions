#include <iostream>
#include "figuras.h"

using namespace std;


int main(){
    Triangulo triangulo;
    Quadrado quadrado;
    Retangulo retangulo;
    Circulo circulo;
    int figura;


    while(true)
    {
        cin >> figura;
        if (figura == 0){
            break;
        }

        switch (figura){
            case 1:
                quadrado.lerAtributosArea();
                cout << "Quadrado de área " << quadrado.calcularArea() << endl;
                break;
            case 2:
                retangulo.lerAtributosArea();
                cout << "Retângulo de área " << retangulo.calcularArea() << endl;
                break;
            case 3:
                triangulo.lerAtributosArea();
                cout << "Triângulo de área " << triangulo.calcularArea() << endl;
                break;
            case 4:
                circulo.lerAtributosArea();
                cout << "Círculo de área " << circulo.calcularArea() << endl;
                break;
        }
    }


    return 0;
}