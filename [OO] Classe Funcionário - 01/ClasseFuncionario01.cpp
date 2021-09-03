#include <iostream>
#include "Funcionario.h"

using namespace std;

int main(){
    int quantFuncionarios;
    Funcionario *funcionario;

    cin >> quantFuncionarios;
    getchar(); //Limpar buffer
    funcionario = new Funcionario[quantFuncionarios];

    for (int i = 0; i < quantFuncionarios; i++)
    {
        getline(cin, funcionario[i].nome);
        getline(cin, funcionario[i].sobrenome);
        cin >> funcionario[i].salarioMensal;
        getchar(); //Limpar buffer

        
        cout << funcionario[i].nome << " " << funcionario[i].sobrenome 
        << " - " << funcionario[i].salarioMensal << " - " << funcionario[i].getSalarioAnual() 
        << endl;
    }


    delete [] funcionario;


    return 0;
}