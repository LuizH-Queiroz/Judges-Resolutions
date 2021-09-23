#ifndef PAG_FUNC
#define PAG_FUNC

#include <string>

    
class Pagamento
{
    private:
        std::string nomeDoFuncionario;
        float valorPagamento;

    
    public:
        /*/////// CONSTRUTORES ///////*/
        Pagamento();
        Pagamento(std::string, float);


        /*/////// MÉTODOS ///////*/
        std::string getNomeDoFuncionario();
        float getValorPagamento();


        void setNomeDoFuncionario(std::string);
        void setValorPagamento(float);
};


class ControleDePagamentos
{
    private:
        Pagamento *pagamento;
        int quantElemVetor;


    public:
        /*/////// CONSTRUTORES ///////*/
        ControleDePagamentos();
        ControleDePagamentos(int);


        /*/////// MÉTODOS ///////*/
        Pagamento getPagamento(int);
        int getIndexFuncionario(std::string);


        void setPagamento(Pagamento, int);


        float calculaTotalDePagamentos();
        void novoArray(int);
        void limparArray();
};


#endif