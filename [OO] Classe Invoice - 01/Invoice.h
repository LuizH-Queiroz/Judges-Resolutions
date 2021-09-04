#ifndef INVOICE01_H
#define INVOICE01_H

#include <string>

class Invoice {
    public:
        int numero;
        std::string descricao;
        int quantComprada;
        float preco;


        float getInvoiceAmount();
};

#endif