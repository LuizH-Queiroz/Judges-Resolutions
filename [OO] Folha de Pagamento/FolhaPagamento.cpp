#include <iostream>
#include <iomanip>
#include <string>
#include "SistemaGerenciaFolha.h"

using namespace std;


int main(){
    Assalariado *assalariado = new Assalariado();
    Horista *horista = new Horista();
    Comissionado *comissionado = new Comissionado();

    //Variáveis auxiliares
    string nome;
    int matricula;
    double salario;
    double salarioHora, horasTrabalhadas;
    double vendasMensais, percentualComissao;
    //////////////////

    double orcamento_maximo;


    cin >> orcamento_maximo;
    cin.ignore();
    SistemaGerenciaFolha sistema(orcamento_maximo);


    getline(cin, nome);
    cin >> matricula >> salario;
    cin.ignore();
    *assalariado = Assalariado(nome, matricula, salario);
    sistema.setFuncionarios((Funcionario *) assalariado);


    getline(cin, nome);
    cin >> matricula >> salarioHora >> horasTrabalhadas;
    cin.ignore();
    *horista = Horista(nome, matricula, salarioHora, horasTrabalhadas);
    sistema.setFuncionarios((Funcionario *) horista);


    getline(cin, nome);
    cin >> matricula >> vendasMensais >> percentualComissao;
    cin.ignore();
    *comissionado = Comissionado(nome, matricula, vendasMensais, percentualComissao);
    sistema.setFuncionarios((Funcionario *) comissionado);


    getline(cin, nome);
    try
    {
        cout << sistema.consultaSalarioFuncionario(nome) << endl;
    }
    catch(FuncionarioNaoExisteException * e)
    {
        cout << e->what() << nome << '\n';
        delete e;
    }
    
    getline(cin, nome);
    try
    {
        cout << sistema.consultaSalarioFuncionario(nome) << endl;
    }
    catch(FuncionarioNaoExisteException * e)
    {
        cout << e->what() << nome << '\n';
        delete e;
    }

    getline(cin, nome);
    try
    {
        cout << sistema.consultaSalarioFuncionario(nome) << endl;
    }
    catch(FuncionarioNaoExisteException * e)
    {
        cout << e->what() << nome << '\n';
        delete e;
    }


    try
    {
        cout << sistema.calculaValorTotalFolha() << endl;
    }
    catch(string e)
    {
        cout << e << '\n';
    }
    


    return 0;
}