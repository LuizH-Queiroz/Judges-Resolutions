#include <iostream>
#include <string>
#include "Pessoa02.h"

using namespace std;

int main(){
    Pessoa *pessoa;
    int numPessoas; //Quantidade de pessoas
    string nome, telefone;
    int idade;
    string procurado;


    cin >> numPessoas;
    cin.ignore();
    pessoa = new Pessoa[numPessoas];

    for (int i = 0; i < numPessoas; i++)
    {
        getline(cin, nome);
        cin >> idade;
        cin.ignore();
        getline(cin, telefone);

        pessoa[i] = Pessoa(nome, idade, telefone);
    }
    
    getline(cin, procurado);
    for (int i = 0; i < numPessoas; i++)
    {
        if (pessoa[i].getNome().find(procurado) < pessoa[i].getNome().size())
        {
            cout << pessoa[i].getNome() + ", " << pessoa[i].getIdade() << ", "
                 << pessoa[i].getTelefone() << endl;
        }
    }

    delete [] pessoa;


    return 0;
}