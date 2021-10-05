#ifndef GER_EMP
#define GER_EMP

#include <string>

class Funcionario
{
    protected:
        int matricula;
        std::string nome;
        float salario;

    public:
        /******** MÉTODOS ********/
        int getMatricula() const { return matricula; }
        std::string getNome() const { return nome; }
        float getSalario() const { return salario; }

        void setMatricula(int);
        void setNome(std::string);
        void setSalario(float);
};

class Consultor : public Funcionario
{
    public:
        /******** MÉTODOS ********/
        float getSalario() const { return salario * 1.1; }
        float getSalario(float) const;
};

#endif