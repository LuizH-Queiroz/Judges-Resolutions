#include <iostream>
#include <string>
#include "namespace_gastos.h"

using namespace std;


int main(){

    gastos::ControleDeGastos gasto;
    int quantDespesas;

    string nome, tipoDeGasto;
    float valor;   
    gastos::Despesa despesa;

////////////////////////////////////////////////////
////////////////////////////////////////////////////

    cin >> quantDespesas;
    cin.ignore();
    gasto.novoVetorDespesa(quantDespesas);
    for (int i = 0; i < quantDespesas; i++)
    {
        getline(cin, nome);
        cin >> valor;
        cin.ignore();
        getline(cin, tipoDeGasto);


        despesa.setNome(nome);
        despesa.setValor(valor);
        despesa.setTipoDeGasto(tipoDeGasto);


        gasto.setDespesa(despesa, i);
    }


    string procurado;
    getline(cin, procurado);
    if (gasto.existeDespesaDoTipo(procurado) == false){
        cout << "Nenhuma despesa do tipo especificado" << endl;
    }
    else {
        for (int i = 0; i < quantDespesas; i++)
        {
            if (gasto.getDespesa(i).getTipoDeGasto() == procurado)
            {
                cout << gasto.getDespesa(i).getNome() << ", "
                     << "R$ " << gasto.getDespesa(i).getValor() << endl;
            }
        }
    }
    
    cout << "Total: "
         << gasto.calculaTotalDeDespesas(procurado) << "/"
         << gasto.calculaTotalDeDespesas() << endl;


    gasto.limparVetor();


    return 0;
}