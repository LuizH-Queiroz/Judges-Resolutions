#ifndef FUNCIONARIO02_H
#define FUNCIONARIO02_H

#include <string>

class Funcionario{
    private:
        /* Atributos */
        std::string nome;
        std::string sobrenome;
        int salarioMensal;


    public:
        /* Construtor */
        Funcionario();


        /* Métodos (Protótipos) */
        std::string getNome();
        std::string getSobrenome();
        int getSalarioMensal();

        void setNome(std::string);
        void setSobrenome(std::string);
        void setSalarioMensal(int);

        int getSalarioAnual();
        void aumentaSalario(float percent);
};

#endif