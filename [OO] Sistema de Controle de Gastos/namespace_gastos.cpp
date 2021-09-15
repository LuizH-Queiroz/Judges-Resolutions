#include "namespace_gastos.h"


/*/////////////// CLASSE Despesa ///////////////*/

/*/////// CONSTRUTORES ///////*/
gastos::Despesa::Despesa(){
    nome = "";
    valor = 0;
    tipoDeGasto = "";
}


/*/////// MÉTODOS ///////*/
std::string gastos::Despesa::getNome(){
    return nome;
}

float gastos::Despesa::getValor(){
    return valor;
}

std::string gastos::Despesa::getTipoDeGasto(){
    return tipoDeGasto;
}



void gastos::Despesa::setNome(std::string str){
    nome = str;
}

void gastos::Despesa::setValor(float val){

    if (val < 0){
        return;
    }

    valor = val;
}

void gastos::Despesa::setTipoDeGasto(std::string str){
    tipoDeGasto = str;
}




/*/////////////// CLASSE ControleDeGastos ///////////////*/

/*/////// CONSTRUTORES ///////*/
gastos::ControleDeGastos::ControleDeGastos(){
    despesa = NULL;
    quantElemVetor = 0;
}

gastos::ControleDeGastos::ControleDeGastos(int quant){

    despesa = new Despesa[quant];
    quantElemVetor = quant;
}


/*/////// MÉTODOS ///////*/
gastos::Despesa gastos::ControleDeGastos::getDespesa(int n){
    return despesa[n];
}



void gastos::ControleDeGastos::setDespesa(Despesa desp, int pos){

    if (pos < 0 || pos >= quantElemVetor){
        return;
    }

    despesa[pos] = desp;
}



void gastos::ControleDeGastos::novoVetorDespesa(int n){

    if (despesa != NULL){
        delete [] despesa;
    }

    despesa = new Despesa[n];
    quantElemVetor = n;
}

float gastos::ControleDeGastos::calculaTotalDeDespesas(){
    float soma = 0;

    for (int i = 0; i < quantElemVetor; i++)
    {
        soma += despesa[i].getValor();
    }

    return soma;
}

float gastos::ControleDeGastos::calculaTotalDeDespesas(std::string tipo){
    float soma = 0;

    for (int i = 0; i < quantElemVetor; i++)
    {
        if (despesa[i].getTipoDeGasto() == tipo){
            soma += despesa[i].getValor();
        }
    }

    return soma;
}

bool gastos::ControleDeGastos::existeDespesaDoTipo(std::string tipo){

    for (int i = 0; i < quantElemVetor; i++)
    {
        if (despesa[i].getTipoDeGasto() == tipo){
            return true;
        }
    }

    return false;
}

void gastos::ControleDeGastos::limparVetor(){

    if (despesa != NULL){
        delete [] despesa;
        despesa = NULL;
    }
}