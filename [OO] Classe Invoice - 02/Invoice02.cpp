#include <iostream>
#include "Invoice02.h"


/*/////// CONSTRUTORES ///////*/
Invoice::Invoice(){
    numero = 0;
    descricao = "";
    quantComprada = 0;
    preco = 0;
}

Invoice::Invoice(int num, std::string desc, int comprado, float custo){
    numero = num;
    descricao = desc;
    
    if (comprado < 0){
        quantComprada = 0;
    }
    else {
        quantComprada = comprado;
    }

    if (custo < 0){
        preco = 0;
    }
    else {
        preco = custo;
    }
}


/*/////// MÉTODOS ///////*/
int Invoice::getNumero(){
    return numero;
}

std::string Invoice::getDescricao(){
    return descricao;
}

int Invoice::getQuantComprada(){
    return quantComprada;
}

float Invoice::getPreco(){
    return preco;
}



void Invoice::setNumero(int n){
    numero = n;
}

void Invoice::setDescricao(std::string desc){
    descricao = desc;
}

void Invoice::setQuantComprada(int quant){

    if (quant < 0){
        quantComprada = 0;
    }
    else {
        quantComprada = quant;
    }
}

void Invoice::setPreco(float custo){

    if (custo < 0){
        preco = 0;
    }
    else {
        preco = custo;
    }
}



float Invoice::getInvoiceAmount(){
    return quantComprada * preco;
}

void Invoice::print(){

    std::cout << numero << " - "
              << descricao << " - "
              << quantComprada << " - "
              << preco << " - "
              << getInvoiceAmount() << std::endl;
}