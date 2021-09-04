#include <iostream>
#include "Invoice.h"

#define QUANT_INVOICES 2

using namespace std;

int main(){
    Invoice invoice[QUANT_INVOICES];


    for (int i = 0; i < QUANT_INVOICES; i++)
    {
        cin >> invoice[i].numero;
        getchar(); //Limpar '\n' do buffer

        getline(cin, invoice[i].descricao);
        cin >> invoice[i].quantComprada >> invoice[i].preco;


        if (invoice[i].preco < 0){
            invoice[i].preco = 0;
        }
        if (invoice[i].quantComprada < 0){
            invoice[i].quantComprada = 0;
        }


        cout << invoice[i].numero << " - "
             << invoice[i].descricao << " - "
             << invoice[i].quantComprada << " - "
             << invoice[i].preco << " - "
             << invoice[i].getInvoiceAmount() << endl;
    }



    return 0;
}