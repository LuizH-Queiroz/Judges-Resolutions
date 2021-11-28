#ifndef FUNCIONARIOEXCEPTIONS_H
#define FUNCIONARIOEXCEPTIONS_H

#include <exception>


class FuncionarioNaoExisteException : std::exception
{
    public:
        virtual const char * what() {return "FuncionarioNaoExisteException ";}
};


class OrcamentoEstouradoException : std::exception
{
    public:
        virtual const char * what() {return "OrcamentoEstouradoException ";}
};


#endif