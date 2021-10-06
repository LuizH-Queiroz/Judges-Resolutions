#ifndef TRABALHADOR
#define TRABALHADOR

#include <string>

class Trabalhador
{
    protected:
        std::string nome;
        float salario;

    public:
        /******** CONSTRUTORES ********/
        Trabalhador();

        /******** MÉTODOS ********/
        std::string getNome() const { return nome; }
        float getSalario() const { return salario; }

        void setNome(std::string);
        void setSalario(float);
};


class TrabalhadorAssalariado : public Trabalhador
{
    public:
        /******** CONSTRUTORES ********/
        TrabalhadorAssalariado();
        TrabalhadorAssalariado(float);

        /******** MÉTODOS ********/
        float calcularPagamentoSemanal() const;
};


class TrabalhadorPorHora : public Trabalhador
{
    private:
        float valorDaHora;

    public:
        static const int maxHorasSemanais; // Maximo de horas em que o pagamento eh nomal.
                                           // Apos isso o trabalhador recebe 150% do valorDaHora

        /******** CONSTRUTORES ********/
        TrabalhadorPorHora();
        TrabalhadorPorHora(float);

        /******** MÉTODOS ********/
        float getValorDaHora() const { return valorDaHora; }
        float getPagamentoSemanal() const { return salario / 4; }

        void setValorDaHora(float);

        float calcularPagamentoSemanal(int);
};

#endif