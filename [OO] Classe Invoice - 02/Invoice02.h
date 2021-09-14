#ifndef INVOICE02_H
#define INVOICE02_H

#include <string>

class Invoice {
    private:
        int numero;
        std::string descricao;
        int quantComprada;
        float preco;


    public:
        /*/////// CONSTRUTOR ///////*/
        Invoice();
        Invoice(int, std::string, int, float);


        /*/////// MÉTODOS ///////*/
        int getNumero();
        std::string getDescricao();
        int getQuantComprada();
        float getPreco();


        void setNumero(int);
        void setDescricao(std::string);
        void setQuantComprada(int);
        void setPreco(float);


        float getInvoiceAmount();
        void print();
};

#endif