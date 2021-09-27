#include <iostream>
#include "restlib.h"


/********************* Class Pedido *********************/

/******** CONSTRUTORES ********/
Pedido::Pedido(){
    numero = 0;
    descricao = "";
    preco = 0;
    quantComprada = 0;
}

Pedido::Pedido(int num, std::string desc, float custo, int quant){
    
    if (num > 0){
        numero = num;
    }
    else {
        numero = 0;
    }

    descricao = desc;

    if (custo >= 0){
        preco = custo;
    }
    else {
        preco = 0;
    }

    if (quant >= 0){
        quantComprada = quant;
    }
    else {
        quantComprada = 0;
    }
}


/******** MÉTODOS ********/
int Pedido::getNumero(){
    return numero;
}

std::string Pedido::getDescricao(){
    return descricao;
}

float Pedido::getPreco(){
    return preco;
}

int Pedido::getQuantComprada(){
    return quantComprada;
}


void Pedido::setNumero(int num){

    if (num > 0){
        numero = num;
    }
}

void Pedido::setDescricao(std::string desc){
    descricao = desc;
}

void Pedido::setPreco(float custo){

    if (custo >= 0){
        preco = custo;
    }
}

void Pedido::setQuantComprada(int quant){

    if (quant >= 0){
        quantComprada = quant;
    }
}


void Pedido::aumentaQuantComprada(int quant){
    quantComprada += quant;
}

float Pedido::getTotal(){
    return preco * quantComprada;
}



/********************* Class MesaDeRestaurante *********************/

/******** MÉTODOS ********/
void MesaDeRestaurante::adicionarPedido(Pedido p){
    
    for(int i = 0; i < pedido.size(); i++)
    {
        if (pedido[i].getDescricao().find(p.getDescricao()) != std::string::npos){
            pedido[i].aumentaQuantComprada(p.getQuantComprada());
            return;
        }
    }

    pedido.push_back(p);
}

void MesaDeRestaurante::zeraPedidos(){

    for (int i = 0; i < pedido.size(); i++)
    {
        pedido[i].setQuantComprada(0);
    }
}

float MesaDeRestaurante::calculaTotal(){
    float total = 0;

    for (int i = 0; i < pedido.size(); i++)
    {
        total += pedido[i].getPreco() * pedido[i].getQuantComprada();
    }

    return total;
}

void MesaDeRestaurante::exibeConta(){

    for(int i = 0; i < pedido.size(); i++)
    {
        std::cout << pedido[i].getNumero() << " - " << pedido[i].getDescricao() << " - "
                  << pedido[i].getQuantComprada() << " - " << pedido[i].getPreco() << " - "
                  << "R$ " << pedido[i].getTotal() << std::endl;
    }

    std::cout << "Total: R$ " << calculaTotal() << std::endl;
}



/********************* Class Restaurante *********************/

/******** CONSTRUTORES ********/
Restaurante::Restaurante(){
    mesa = NULL;
    quantMesas = 0;
}

Restaurante::Restaurante(int quant){

    if (quant > 0){
        mesa = new MesaDeRestaurante[quant];
        quantMesas = quant;
    }
}


/******** MÉTODOS ********/
void Restaurante::adicionarPedido(Pedido p, int mesa){

    if (mesa < quantMesas){
        this->mesa[mesa-1].adicionarPedido(p);
    }
}

float Restaurante::calculaTotalRestaurante(){
    float total = 0;

    for (int i = 0; i < quantMesas; i++)
    {
        total += mesa[i].calculaTotal();
    }

    return total;
}

MesaDeRestaurante Restaurante::getMesa(int i){
    
    if (i <= quantMesas){
        return mesa[i];
    }
}

void Restaurante::NovoArray(int quant){

    if (quant > 0){

        if (mesa != NULL){
            delete [] mesa;
        }

        mesa = new MesaDeRestaurante[quant];
        quantMesas = quant;
    }
}


void Restaurante::limparArray(){

    if (mesa != NULL){
        delete [] mesa;
        quantMesas = 0;
    }
}