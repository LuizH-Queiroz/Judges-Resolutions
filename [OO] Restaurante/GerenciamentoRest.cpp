#include <iostream>
#include <string>
#include "restlib.h"

#define MESAS_REST 5

using namespace std;


int main(){
    Restaurante mesas(MESAS_REST);

    //Para passar os dados:
    int numero, quantComprada, numMesa;
    float preco;
    string descricao;
    ///////////////////////////////////

    while(true)
    {
        cin >> numero;
        if (numero < 0){
            break;
        }

        cin.ignore();
        getline(cin, descricao);
        cin >> quantComprada >> preco >> numMesa;


        mesas.adicionarPedido(Pedido(numero, descricao, preco, quantComprada), numMesa);
    }

    for (int i = 0; i < MESAS_REST; i++)
    {
        if(mesas.getMesa(i).calculaTotal() > 0){
            cout << "Mesa " << i + 1 << endl;
            mesas.getMesa(i).exibeConta();
            cout << endl;
        }
    }
    cout << "Total Restaurante: R$ " << mesas.calculaTotalRestaurante() << endl;


    mesas.limparArray();


    return 0;
}