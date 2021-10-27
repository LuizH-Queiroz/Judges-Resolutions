#include <iostream>
#include "Insumo.h"


/******************************* Class Insumo *******************************/

/******** CONSTRUTORES / DESTRUTOR ********/
Insumo::Insumo(){
    nome = dtVencimento = nomeFabricante = "";
    quantidade = valorUnitario = tipoInsumo = 0;
}

Insumo::Insumo(std::string insumo_nome, int quant, int valor, std::string vencimento,
               std::string fabricante, int tipo)
{
    nome = insumo_nome;
    quantidade = quant;
    valorUnitario = valor;
    dtVencimento = vencimento;
    nomeFabricante = fabricante;
    tipoInsumo = tipo;
}

Insumo::~Insumo(){
    std::cout << "Deletando Insumos" << std::endl;
}


//////////////////////////////////////////////////////////////////////////////////////////////

/******************************* Class Vacina : public Insumo *******************************/

/******** CONSTRUTORES / DESTRUTOR ********/
Vacina::Vacina()
      : Insumo()
{
    tipo = quantDoses = intervalo = 0;
}

Vacina::Vacina(std::string insumo_nome, int quant, int valor, std::string vencimento,
               std::string fabricante, int tipo, int tipo_vac, int n_doses, int interval)
       : Insumo(insumo_nome, quant, valor, vencimento, fabricante, tipo)
{
    this->tipo = tipo_vac;
    this->quantDoses = n_doses;
    this->intervalo = interval;
}

Vacina::~Vacina(){
    std::cout << "Deletando Vacina" << std::endl;
}


///////////////////////////////////////////////////////////////////////////////////////////////////

/******************************* Class Medicamento : public Insumo *******************************/

/******** CONSTRUTORES / DESTRUTOR ********/
Medicamento::Medicamento()
           : Insumo()
{
    dosagem = administracao = disponibilizacao = "";
}

Medicamento::Medicamento(std::string insumo_nome, int quant, int valor, std::string vencimento,
                         std::string fabricante, int tipo, std::string dosagem, std::string administracao,
                         std::string disponibilizacao)
           : Insumo(insumo_nome, quant, valor, vencimento, fabricante, tipo)
{
    this->dosagem = dosagem;
    this->administracao = administracao;
    this->disponibilizacao = disponibilizacao;
}

Medicamento::~Medicamento(){
    std::cout << "Deletando Medicamento" << std::endl;
}


///////////////////////////////////////////////////////////////////////////////////////////

/******************************* Class EPI : public Insumo *******************************/

/******** CONSTRUTORES / DESTRUTOR ********/
EPI::EPI()
   : Insumo()
{
    tipo = 0;
    descricao = "";
}

EPI::EPI(std::string insumo_nome, int quant, int valor, std::string vencimento,
         std::string fabricante, int tipo, int tipo_EPI, std::string descricao)
   : Insumo(insumo_nome, quant, valor, vencimento, fabricante, tipo)
{
    this->tipo = tipo_EPI;
    this->descricao = descricao;
}

EPI::~EPI(){
    std::cout << "Deletando EPI" << std::endl;
}


/////////////////////////////////////////////////////////////////////////////

/******************************* Class Local *******************************/

/******** CONSTRUTORES / DESTRUTOR ********/
Local::Local(){
    nome = "";
    tipo = 0;

    for (int i = 0; i < 3; i++)
    {
        insumosArr[i] = nullptr;
    }
}

Local::Local(std::string nome, int tipo){
    this->nome = nome;
    this->tipo = tipo;
}

Local::~Local(){
    std::cout << "Deletando Local" << std::endl;

    for (int i = 0; i < 3; i++)
    {
        delete insumosArr[i];
    }

    for (auto&& it : insumosVec)
    {
        delete it;
    }
}

/******** MÉTODOS ********/
void Local::addInsumoArr(Insumo *in, int index){
    insumosArr[index] = in;
}

void Local::addInsumoVec(Insumo *in){
    insumosVec.push_back(in);
}