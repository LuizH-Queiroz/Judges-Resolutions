#include "pagamento_funcionarios.h"


/*//////////////////// Class Pagamento ////////////////////*/

/*////////// CONSTRUTORES //////////*/
Pagamento::Pagamento(){
    nomeDoFuncionario = "";
    valorPagamento = 0;
}

Pagamento::Pagamento(std::string nome, float valor){
    nomeDoFuncionario = nome;
    valorPagamento = valor;
}


/*////////// MÉTODOS //////////*/
std::string Pagamento::getNomeDoFuncionario(){
    return nomeDoFuncionario;
}

float Pagamento::getValorPagamento(){
    return valorPagamento;
}


void Pagamento::setNomeDoFuncionario(std::string nome){
    nomeDoFuncionario = nome;
}

void Pagamento::setValorPagamento(float valor){

    if (valor >= 0){
        valorPagamento = valor;
    }
}



/*//////////////////// Class ControleDePagamentos ////////////////////*/

/*////////// CONSTRUTORES //////////*/
ControleDePagamentos::ControleDePagamentos(){
    pagamento = NULL;
    quantElemVetor = 0;
}

ControleDePagamentos::ControleDePagamentos(int quantElemVetor){

    pagamento = new Pagamento[quantElemVetor];
    this->quantElemVetor = quantElemVetor;
}


/*////////// MÉTODOS //////////*/
Pagamento ControleDePagamentos::getPagamento(int indice){
    
    if (indice >= 0 && indice < quantElemVetor){
        return pagamento[indice];
    }
}

int ControleDePagamentos::getIndexFuncionario(std::string nome){

    for (int i = 0; i < quantElemVetor; i++)
    {
        if (pagamento[i].getNomeDoFuncionario().find(nome) != std::string::npos){
            return i;
        }
    }

    return -1;
}


void ControleDePagamentos::setPagamento(Pagamento pag, int indice){

    if (indice >= 0 && indice < quantElemVetor){
        pagamento[indice] = pag;
    }
}


float ControleDePagamentos::calculaTotalDePagamentos(){
    float total = 0;

    for (int i = 0; i < quantElemVetor; i++)
    {
        total += pagamento[i].getValorPagamento();
    }

    return total;
}

void ControleDePagamentos::novoArray(int quant){

    if (pagamento != NULL){
        delete [] pagamento;
    }

    pagamento = new Pagamento[quant];
    quantElemVetor = quant;
}

void ControleDePagamentos::limparArray(){

    if (pagamento != NULL){
        delete [] pagamento;
        pagamento = NULL;
    }
}