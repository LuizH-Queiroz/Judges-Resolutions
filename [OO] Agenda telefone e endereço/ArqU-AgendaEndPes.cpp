#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Endereco
{
    private:
        string rua;
        int numero;
        string bairro;
        string cidade;
        string estado;
        string CEP;

    
    public:
        /******** CONSTRUTORES ********/
        Endereco();
        Endereco(string rua, int numero, string bairro, string cidade,
                 string estado, string CEP);
        

        /******** MÉTODOS ********/
        string getRua();
        int getNumero();
        string getBairro();
        string getCidade();
        string getEstado();
        string getCEP();


        void setRua(string);
        void setNumero(int);
        void setBairro(string);
        void setCidade(string);
        void setEstado(string);
        void setCEP(string);


        string toString();
};


class Pessoa
{
    private:
        string nome;
        Endereco endereco;
        string telefone;


    public:
        /******** CONSTRUTORES ********/
        Pessoa();
        Pessoa(string);
        Pessoa(string, Endereco, string);


        /******** MÉTODOS ********/
        string getNome();
        Endereco getEndereco();
        string getTelefone();


        void setNome(string);
        void setEndereco(Endereco);
        void setTelefone(string);


        string toString();
};



/********************* Class Endereco *********************/

/******** CONSTRUTORES ********/
Endereco::Endereco(){
    rua = "";
    numero = 0;
    bairro = "";
    cidade = "";
    estado = "";
    CEP = "";
}

Endereco::Endereco(string rua, int numero, string bairro, string cidade,
                   string estado, string CEP)
{
    this->rua = rua;

    if (numero > 0){
        this->numero = numero;
    }
    else {
        this->numero = 0;
    }
    
    this->bairro = bairro;
    this->cidade = cidade;
    this->estado = estado;
    this->CEP = CEP;
}


/******** MÉTODOS ********/
string Endereco::getRua(){
    return rua;
}

int Endereco::getNumero(){
    return numero;
}

string Endereco::getBairro(){
    return bairro;
}

string Endereco::getCidade(){
    return cidade;
}

string Endereco::getEstado(){
    return estado;
}

string Endereco::getCEP(){
    return CEP;
}


void Endereco::setRua(string rua){
    this->rua = rua;
}

void Endereco::setNumero(int numero){

    if (numero > 0){
        this->numero = numero;
    }
}

void Endereco::setBairro(string bairro){
    this->bairro = bairro;
}

void Endereco::setCidade(string cidade){
    this->cidade = cidade;
}

void Endereco::setEstado(string estado){
    this->estado = estado;
}

void Endereco::setCEP(string cep){
    this->CEP = cep;
}


string Endereco::toString(){
    return rua + ", " + to_string(numero) + ", " + bairro + ". "
           + cidade + " - " + estado + ". "
           + "CEP: " + CEP + '\n';
}



/********************* Class Endereco *********************/

/******** CONSTRUTORES ********/
Pessoa::Pessoa(){
    nome = "";
    endereco = Endereco();
    telefone = "";
}

Pessoa::Pessoa(string nome){
    this->nome = nome;
    endereco = Endereco();
    telefone = "";
}

Pessoa::Pessoa(string nome, Endereco endereco, string telefone){
    this->nome = nome;
    this->endereco = endereco;
    this->telefone = telefone;
}


/******** MÉTODOS ********/
string Pessoa::getNome(){
    return nome;
}

Endereco Pessoa::getEndereco(){
    return endereco;
}

string Pessoa::getTelefone(){
    return telefone;
}


void Pessoa::setNome(string nome){
    this->nome = nome;
}

void Pessoa::setEndereco(Endereco endereco){
    this->endereco = endereco;
}

void Pessoa::setTelefone(string telefone){
    this->telefone = telefone;
}


string Pessoa::toString(){
    return nome + ", " + telefone + '\n'
           + endereco.toString();
}



/******************************************/
/************* FUNÇÃO MAIN ****************/
/******************************************/
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
    ////////////////////////////////////////

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