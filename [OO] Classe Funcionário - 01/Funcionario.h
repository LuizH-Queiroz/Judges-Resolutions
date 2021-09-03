#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <string>

using namespace std;

class Funcionario {

    public:
        string nome;
        string sobrenome;
        int salarioMensal;


        int getSalarioAnual();
};

#endif