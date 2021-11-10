#include <iostream>
#include <string>
#include "conta.h"

using namespace std;


int main(){
    ContaCorrente corrente;
    ContaEspecial especial;
    Poupanca poupanca;

    //Variáveis auxiliares:
    string nome;
    int numero;
    float salario;
    float deposito, saque;
    ///////////////////////


    getline(cin, nome);
    cin >> numero >> salario >> deposito >> saque;
    cin.ignore();
    corrente = ContaCorrente(nome, numero, 0, salario);
    cout << corrente.getNomeCliente() << ", cc: " << corrente.getNumero()
         << ", salário " << corrente.getSalario();
    corrente.depositar(deposito);
    corrente.sacar(saque);
    cout << ", saldo total disponível: R$ " << corrente.saldoTotalDisponivel() << endl;
    

    getline(cin, nome);
    cin >> numero >> salario >> deposito >> saque;
    cin.ignore();
    especial = ContaEspecial(nome, numero, 0, salario);
    cout << especial.getNomeCliente() << ", cc: " << especial.getNumero()
         << ", salário " << especial.getSalario()
         << ", ";
    especial.depositar(deposito);
    especial.sacar(saque);
    cout << "saldo total disponível: R$ " << especial.saldoTotalDisponivel() << endl;


    getline(cin, nome);
    cin >> numero >> deposito >> saque;
    poupanca = Poupanca(nome, numero, 0, 0, 0.006);
    poupanca.depositar(deposito);
    poupanca.sacar(saque);
    cout << poupanca.getNomeCliente() << ", cc: " << poupanca.getNumero()
         << ", saldo total disponível: R$ " << poupanca.saldoTotalDisponivel() << endl;




    return 0;
}