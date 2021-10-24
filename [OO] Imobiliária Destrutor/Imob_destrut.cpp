#include <iostream>
#include <string>
#include "Imoveis.h"

using namespace std;


int main(){
    Imobiliaria imob;
    int n_imoveis;
    int tipoImovel;


    cin >> n_imoveis;
    for (int i = 0; i < n_imoveis; i++)
    {
        cin >> tipoImovel;

        switch (tipoImovel){
            case TipoImovel::CASA:
                imob.addImovel(new Casa());
                break;
            case TipoImovel::APARTAMENTO:
                imob.addImovel(new Apartamento());
                break;
            case TipoImovel::TERRENO:
                imob.addImovel(new Terreno());
                break;
        }

        imob[imob.size()-1]->lerAtributos();
    }


    string buscar;
    cin.ignore();
    getline(cin, buscar);
    imob.buscaImovel(buscar);


    return 0;
}