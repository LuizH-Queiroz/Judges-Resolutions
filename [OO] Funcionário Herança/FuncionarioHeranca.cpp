#include <iostream>
#include <string>
#include "GerenciarEmpresa.h"

#define N_FUNC 1 //Quantidade de funcionarios
#define N_CONSULT 1 //Quantidade de consultores

using namespace std;


int main(){
    Funcionario funcionario;
    Consultor consultor;

    //Variaveis auxiliares:
    int matricula;
    string nome;
    float salario;
    ////////////////////////////////////////////


    for (int i = 0; i < N_FUNC; i++)
    {
        cin >> matricula;
        cin.ignore();
        getline(cin, nome);
        cin >> salario;

        funcionario.setMatricula(matricula);
        funcionario.setNome(nome);
        funcionario.setSalario(salario);

        cout << funcionario.getMatricula() << " - " << funcionario.getNome()
             << " - R$ " << funcionario.getSalario() << endl;
    }

    for (int i = 0; i < N_CONSULT; i++)
    {
        cin >> matricula;
        cin.ignore();
        getline(cin, nome);
        cin >> salario;

        consultor.setMatricula(matricula);
        consultor.setNome(nome);
        consultor.setSalario(salario);

        cout << consultor.getMatricula() << " - " << consultor.getNome()
             << " - R$ " << consultor.getSalario() << endl;
    }


    return 0;
}