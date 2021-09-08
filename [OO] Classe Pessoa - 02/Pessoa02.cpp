#include <string>
#include "Pessoa02.h"

/*/////// CONSTRUTORES ///////*/
Pessoa::Pessoa(){

    idade = 0;

    /* Variáveis do tipo string já começam vazias e, portanto,
    não precisam receber nenhum valor inicial no construtor */
}

Pessoa::Pessoa(std::string nome){
    this->nome = nome;
}

Pessoa::Pessoa(std::string nome, int idade, std::string telefone){
    this->nome = nome;
    this->idade = idade;
    this->telefone = telefone;
}


/*/////// MÉTODOS ///////*/
std::string Pessoa::getNome(){
    return nome;
}

int Pessoa::getIdade(){
    return idade;
}

std::string Pessoa::getTelefone(){
    return telefone;
}


void Pessoa::setNome(std::string nome){
    this->nome = nome;
}

void Pessoa::setIdade(int idade){
    this->idade = idade;
}

void Pessoa::setTelefone(std::string telefone){
    this->telefone = telefone;
}