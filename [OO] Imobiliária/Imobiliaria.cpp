#include <iostream>
#include <string>
#include "Imoveis.h"

using namespace std;


int main(){
    int nImoveis;
    int opcao;
    Casa casa;
    Apartamento apartamento;
    Terreno terreno;

    cin >> nImoveis;
    for (int i = 0; i < nImoveis; i++)
    {
        cin >> opcao;

        switch (opcao){
            case 0:
                cout << "Indefinido" << endl;
                break;
            case 1:
                casa.lerAtributos();
                casa.exibeAtributos();
                break;
            case 2:
                apartamento.lerAtributos();
                apartamento.exibeAtributos();
                break;
            case 3:
                terreno.lerAtributos();
                terreno.exibeAtributos();
                break;
        }
    }


    return 0;
}