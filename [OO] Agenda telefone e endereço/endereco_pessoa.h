#ifndef ENDERECO_PESSOA
#define ENDERECO_PESSOA

#include <string>

class Endereco
{
    private:
        std::string rua;
        int numero;
        std::string bairro;
        std::string cidade;
        std::string estado;
        std::string CEP;

    
    public:
        /******** CONSTRUTORES ********/
        Endereco();
        Endereco(std::string rua, int numero, std::string bairro, std::string cidade,
                 std::string estado, std::string CEP);
        

        /******** MÉTODOS ********/
        std::string getRua();
        int getNumero();
        std::string getBairro();
        std::string getCidade();
        std::string getEstado();
        std::string getCEP();


        void setRua(std::string);
        void setNumero(int);
        void setBairro(std::string);
        void setCidade(std::string);
        void setEstado(std::string);
        void setCEP(std::string);


        std::string toString();
};


class Pessoa
{
    private:
        std::string nome;
        Endereco endereco;
        std::string telefone;


    public:
        /******** CONSTRUTORES ********/
        Pessoa();
        Pessoa(std::string);
        Pessoa(std::string, Endereco, std::string);


        /******** MÉTODOS ********/
        std::string getNome();
        Endereco getEndereco();
        std::string getTelefone();


        void setNome(std::string);
        void setEndereco(Endereco);
        void setTelefone(std::string);


        std::string toString();
};



#endif