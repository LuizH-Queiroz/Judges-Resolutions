#ifndef PESSOA02_H
#define PESSOA02_H

#include <string>

class Pessoa {
    private:
        std::string nome;
        int idade;
        std::string telefone;

    public:
        /*/////// CONSTRUTORES ///////*/
        Pessoa();
        Pessoa(std::string); //O nome é o único parâmetro
        Pessoa(std::string, int, std::string);

        /*/////// MÉTODOS ///////*/
        std::string getNome();
        int getIdade();
        std::string getTelefone();

        void setNome(std::string);
        void setIdade(int);
        void setTelefone(std::string);
};

#endif