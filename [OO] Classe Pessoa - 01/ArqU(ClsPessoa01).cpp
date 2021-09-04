#include <iostream>
#include <string>

#define QUANT_PESSOAS 2

using namespace std;


class Pessoa {
    public:
        std::string nome;
        int idade;
        std::string telefone;
};


int main(){
    Pessoa *pessoa;

    pessoa = new Pessoa[QUANT_PESSOAS];


    for (int i = 0; i < QUANT_PESSOAS; i++)
    {
        getline(cin, pessoa[i].nome);
        cin >> pessoa[i].idade;
        getchar(); //Limpar o '\n' do buffer
        getline(cin, pessoa[i].telefone);


        cout << pessoa[i].nome << ", "
             << pessoa[i].idade << ", "
             << pessoa[i].telefone << endl;
    }


    delete [] pessoa;


    return 0;
}