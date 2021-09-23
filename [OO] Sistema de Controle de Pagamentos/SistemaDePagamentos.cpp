#include <iostream>
#include "pagamento_funcionarios.h"

using namespace std;


int main(){
    ControleDePagamentos pagamento;
    int quantPag;

    cin >> quantPag;
    pagamento.novoArray(quantPag);

    float valor;
    string nome;
    for (int i = 0; i < quantPag; i++)
    {
        cin >> valor;
        cin.ignore();
        getline(cin, nome);

        pagamento.setPagamento(Pagamento(nome, valor), i);
    }

    int indice;
    getline(cin, nome);
    indice = pagamento.getIndexFuncionario(nome);
    if (indice != -1){
        cout << pagamento.getPagamento(indice).getNomeDoFuncionario()
             << ": R$ " << pagamento.getPagamento(indice).getValorPagamento() << endl;
    }
    else {
        cout << nome << " não encontrado(a)." << endl;
    }
    cout << "Total: R$ " << pagamento.calculaTotalDePagamentos() << endl;


    pagamento.limparArray();


    return 0;
}