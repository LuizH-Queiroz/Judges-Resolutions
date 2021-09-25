#include <iostream>
#include <vector>
#include "endereco_pessoa.h"

using namespace std;


int main(){
    int quantPessoas;
    vector<Pessoa> pessoa;

    //Para receber valores e passar para o vector:
    int numero;
    string nome,
           telefone,
           rua,
           bairro,
           cidade,
           estado,
           cep;
///////////////////////////////////////////////

    cin >> quantPessoas;
    cin.ignore();
    for (int i = 0; i < quantPessoas; i++)
    {
        getline(cin, nome);
        getline(cin, telefone);
        getline(cin, rua);
        cin >> numero;
        cin.ignore();
        getline(cin, bairro);
        getline(cin, cidade);
        getline(cin, estado);
        getline(cin, cep);


        pessoa.push_back(Pessoa(nome,
                                Endereco(rua, numero, bairro, cidade, estado, cep),
                                telefone));
    }

    for (int i = 0; i < pessoa.size(); i++)
    {
        cout << pessoa[i].toString() << endl;
    }



    return 0;
}