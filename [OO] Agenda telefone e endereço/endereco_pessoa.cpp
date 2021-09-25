#include "endereco_pessoa.h"
#include <iostream>


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

Endereco::Endereco(std::string rua, int numero, std::string bairro, std::string cidade,
                   std::string estado, std::string CEP)
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
std::string Endereco::getRua(){
    return rua;
}

int Endereco::getNumero(){
    return numero;
}

std::string Endereco::getBairro(){
    return bairro;
}

std::string Endereco::getCidade(){
    return cidade;
}

std::string Endereco::getEstado(){
    return estado;
}

std::string Endereco::getCEP(){
    return CEP;
}


void Endereco::setRua(std::string rua){
    this->rua = rua;
}

void Endereco::setNumero(int numero){

    if (numero > 0){
        this->numero = numero;
    }
}

void Endereco::setBairro(std::string bairro){
    this->bairro = bairro;
}

void Endereco::setCidade(std::string cidade){
    this->cidade = cidade;
}

void Endereco::setEstado(std::string estado){
    this->estado = estado;
}

void Endereco::setCEP(std::string cep){
    this->CEP = cep;
}


std::string Endereco::toString(){
    return rua + ", " + std::to_string(numero) + ", " + bairro + ". "
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

Pessoa::Pessoa(std::string nome){
    this->nome = nome;
    endereco = Endereco();
    telefone = "";
}

Pessoa::Pessoa(std::string nome, Endereco endereco, std::string telefone){
    this->nome = nome;
    this->endereco = endereco;
    this->telefone = telefone;
}


/******** MÉTODOS ********/
std::string Pessoa::getNome(){
    return nome;
}

Endereco Pessoa::getEndereco(){
    return endereco;
}

std::string Pessoa::getTelefone(){
    return telefone;
}


void Pessoa::setNome(std::string nome){
    this->nome = nome;
}

void Pessoa::setEndereco(Endereco endereco){
    this->endereco = endereco;
}

void Pessoa::setTelefone(std::string telefone){
    this->telefone = telefone;
}


std::string Pessoa::toString(){
    return nome + ", " + telefone + '\n'
           + endereco.toString();
}