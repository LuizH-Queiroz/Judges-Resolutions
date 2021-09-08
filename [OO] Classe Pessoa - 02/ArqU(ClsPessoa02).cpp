#include <iostream>
#include <string>

using namespace std;

/*//////////////// DEFINIÇÃO DA CLASSE ////////////////////*/
class Pessoa {
    private:
        string nome;
        int idade;
        string telefone;

    public:
        /*/////// CONSTRUTORES ///////*/
        Pessoa();
        Pessoa(string); //O nome é o único parâmetro
        Pessoa(string, int, string);

        /*/////// MÉTODOS ///////*/
        string getNome();
        int getIdade();
        string getTelefone();

        void setNome(string);
        void setIdade(int);
        void setTelefone(string);
};

/*//////////////// CONSTRUTORES ////////////////////*/
Pessoa::Pessoa(){

    idade = 0;

    /* Variáveis do tipo string já começam vazias e, portanto,
    não precisam receber nenhum valor inicial no construtor */
}

Pessoa::Pessoa(string nome){
    this->nome = nome;
}

Pessoa::Pessoa(string nome, int idade, string telefone){
    this->nome = nome;
    this->idade = idade;
    this->telefone = telefone;
}


/*/////////////////// MÉTODOS /////////////////////*/
string Pessoa::getNome(){
    return nome;
}

int Pessoa::getIdade(){
    return idade;
}

string Pessoa::getTelefone(){
    return telefone;
}


void Pessoa::setNome(string nome){
    this->nome = nome;
}

void Pessoa::setIdade(int idade){
    this->idade = idade;
}

void Pessoa::setTelefone(string telefone){
    this->telefone = telefone;
}


/*/////////////////////////////////////////////////*/
/*//////////////// FUNÇÃO MAIN ////////////////////*/
/*/////////////////////////////////////////////////*/
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