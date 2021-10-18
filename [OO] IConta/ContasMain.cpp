#include <iostream>
#include <string>
#include "conta.h"

using namespace std;


int main(){
    Conta conta_normal;
    ContaEspecial conta_especial;

    //Variaveis intermediarias:
    string nome;
    int numeroConta;
    float salario;
    float depositar, sacar;
    ///////////////////////////

    getline(cin, nome);
    cin >> numeroConta >> salario >> depositar >> sacar;
    conta_normal = Conta(nome, numeroConta, salario);
    conta_normal.depositar(depositar);
    conta_normal.sacar(sacar);
    cout << conta_normal.getNome() << ", cc: " << conta_normal.getNumeroConta()
         << ", salário " << conta_normal.getSalarioMensal()
         << ", saldo total disponível: R$ " << conta_normal.saldoTotalDisponivel()
         << endl;


    cin.ignore();
    getline(cin, nome);
    cin >> numeroConta >> salario >> depositar >> sacar;
    conta_especial = ContaEspecial(nome, numeroConta, salario);
    conta_especial.depositar(depositar);
    conta_especial.sacar(sacar);
    cout << conta_especial.getNome() << ", cc: " << conta_especial.getNumeroConta()
         << ", salário " << conta_especial.getSalarioMensal()
         << ", saldo total disponível: R$ " << conta_especial.saldoTotalDisponivel()
         << endl;


    return 0;
}