#include <iostream>
#include "figuras_2.h"

using namespace std;


int main(){
    FiguraGeometrica *figura;
    int tipo;


    while (true)
    {
        cin >> tipo;
        if (tipo == Figura::INDEFINIDO){
            break;
        }

        switch (tipo){
            case Figura::TRIANGULO:
                figura = new Triangulo();
                figura->lerAtributosArea();
                break;
            case Figura::QUADRADO:
                figura = new Quadrado();
                figura->lerAtributosArea();
                break;
            case Figura::RETANGULO:
                figura = new Retangulo();
                figura->lerAtributosArea();
                break;
            case Figura::CIRCULO:
                figura = new Circulo();
                figura->lerAtributosArea();
                break;
        }

        cout << figura->getNome() << " polimórfico de área " << figura->calcularArea() << endl;

        delete figura;
        figura = NULL;
    }


    return 0;
}