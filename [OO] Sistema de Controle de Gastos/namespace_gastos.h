#ifndef NAMESPACE_GASTOS
#define NAMESPACE_GASTOS

#include <string>

namespace gastos
{
    class Despesa
    {
        private:
            std::string nome;
            float valor;
            std::string tipoDeGasto;

        
        public:
            /*/////// CONSTRUTORES ///////*/
            Despesa();


            /*/////// MÉTODOS ///////*/
            std::string getNome();
            float getValor();
            std::string getTipoDeGasto();


            void setNome(std::string);
            void setValor(float);
            void setTipoDeGasto(std::string);
    };


    class ControleDeGastos
    {
        private:
            Despesa *despesa;
            int quantElemVetor;


        public:
            /*/////// CONSTRUTORES ///////*/
            ControleDeGastos();
            ControleDeGastos(int); //O numero (parâmetro) é a quantidade de elementos do vetor
                                   // ATENÇÃO: O CONSTRUTOR DEVE SER CHAMADO APENAS NA INSTANCIAÇÃO


            /*/////// MÉTODOS ///////*/
            Despesa getDespesa(int);


            void setDespesa(Despesa, int);


            void novoVetorDespesa(int); //Cria novo vetor dinâmico e apaga o presente (se necessário)
            float calculaTotalDeDespesas();
            float calculaTotalDeDespesas(std::string);
            bool existeDespesaDoTipo(std::string);
            void limparVetor(); //delete [] despesa
    };

} // namespace gastos



#endif