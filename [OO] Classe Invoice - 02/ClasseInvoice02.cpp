#include <iostream>
#include <string>
#include "Invoice02.h"

#define QUANT_INVOICE 2

using namespace std;


int main(){
    Invoice *invoice = new Invoice[QUANT_INVOICE];
    int numero, quantComprada;
    string descricao;
    float preco;


    for (int i = 0; i < QUANT_INVOICE; i++)
    {
        cin >> numero;
        getchar();
        getline(cin, descricao);
        cin >> quantComprada >> preco;


        invoice[i] = Invoice(numero, descricao, quantComprada, preco);


        invoice[i].print();
    }


    delete [] invoice;


    return 0;
}