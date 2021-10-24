#include <iostream>
#include "Imoveis.h"


/******************************** Class Imovel ********************************/

/******** CONSTRUTORES / DESTRUTOR ********/
Imovel::Imovel(){
    nome = "";
    valor = 0;
    tipo = TipoImovel::INDEFINIDO;
    forma_negocio = "";
}

Imovel::Imovel(float valor, TipoImovel tipo, std::string forma){
    this->valor = valor;
    setTipoImovel(tipo);
    forma_negocio = forma;
}

Imovel::~Imovel(){
    std::cout << "Deletando Imovel" << std::endl;
}


/******** MÉTODOS ********/
std::string Imovel::getNome() const { return nome; }
float Imovel::getValor() const { return valor; }
TipoImovel Imovel::getTipoImovel() const { return tipo; }
std::string Imovel::getFormaNegocio() const { return forma_negocio; }

void Imovel::setNome(std::string nome){
    this->nome = nome;
}

void Imovel::setValor(float valor){
    this->valor = valor;
}

void Imovel::setTipoImovel(TipoImovel tipo){
    this->tipo = tipo;

    switch (tipo){
        case TipoImovel::CASA:
            nome = "Casa";
            break;
        case TipoImovel::APARTAMENTO:
            nome = "Apartamento";
            break;
        case TipoImovel::TERRENO:
            nome = "Terreno";
            break;
        default:
            nome = "INDEFINIDO";
            break;
    }
}

void Imovel::setFormaNegocio(std::string forma) {
    forma_negocio = forma;
}

void Imovel::lerAtributos(){
    std::cin >> valor;
    std::cin.ignore();
    std::getline(std::cin, forma_negocio);
}

void Imovel::exibeAtributos() const{
    std::cout << nome << " para " + forma_negocio + ".";
}

//////////////////////////////////////////////////////////////////////////////////////////////


/******************************** Class Casa : public Imovel ********************************/

/******** CONSTRUTORES / DESTRUTOR ********/
Casa::Casa()
    : Imovel()
{
    setTipoImovel(TipoImovel::CASA);

    num_pavimentos = num_quartos = 0;
    area_construida = area_terreno = 0;
}

Casa::Casa(float valor, std::string forma_negocio,
        int num_pavimentos, int num_quartos, float area_terreno, float area_construida)
    : Imovel(valor, TipoImovel::CASA, forma_negocio)
{
    this->num_pavimentos = num_pavimentos;
    this->num_quartos = num_quartos;
    this->area_terreno = area_terreno;
    this->area_construida = area_construida;
}

Casa::~Casa(){
    std::cout << "Deletando Casa" << std::endl;
}


/******** MÉTODOS ********/
int Casa::getNumPavimentos() const { return num_pavimentos; }
int Casa::getNumQuartos() const { return num_quartos; }
float Casa::getAreaTerreno() const { return area_terreno; }
float Casa::getAreaConstruida() const { return area_construida; }


void Casa::setNumPavimentos(int num){
    num_pavimentos = num;
}

void Casa::setNumQuartos(int num){
    num_quartos = num;
}

void Casa::setAreaTerreno(float area){
    area_terreno = area;
}

void Casa::setAreaConstruida(float area){
    area_construida = area;
}

void Casa::lerAtributos(){
    Imovel::lerAtributos();

    std::cin >> num_pavimentos >> num_quartos >> area_terreno >> area_construida;
}

void Casa::exibeAtributos() const {
    Imovel::exibeAtributos();

    std::cout << " " << num_pavimentos << " pavimentos, "
              << num_quartos << " quartos, "
              << area_terreno << "m2 de área de terreno e "
              << area_construida << "m2 de área construída."
              << " R$ " << valor << "." << std::endl;
}

////////////////////////////////////////////////////////////////////////////////////////////////////


/******************************** Class Apartamento : public Imovel ********************************/

/******** CONSTRUTORES / DESTRUTOR ********/
Apartamento::Apartamento()
           : Imovel()
{
    setTipoImovel(TipoImovel::APARTAMENTO);

    area = 0;
    num_quartos = 0;
    andar = 0;
    valor_condominio = 0;
    vagas_garagem = 0;
}

Apartamento::Apartamento(float valor, std::string forma_negocio,
            float area, int num_quartos, int andar, float valor_condominio, int vagas_garagem)
           : Imovel(valor, TipoImovel::APARTAMENTO, forma_negocio)
{
    this->area = area;
    this->num_quartos = num_quartos;
    this->andar = andar;
    this->valor_condominio = valor_condominio;
    this->vagas_garagem = vagas_garagem;
}

Apartamento::~Apartamento(){
    std::cout << "Deletando Apartamento" << std::endl;
}


/******** MÉTODOS ********/
float Apartamento::getArea() const { return area; }
int Apartamento::getNumQuartos() const { return num_quartos; }
int Apartamento::getAndar() const { return andar; }
float Apartamento::getValorCondominio() const { return valor_condominio; }
int Apartamento::getVagasGaragem() const { return vagas_garagem; }

void Apartamento::setArea(float area){
    this->area = area;
}

void Apartamento::setNumQuartos(int num){
    num_quartos = num;
}

void Apartamento::setAndar(int andar){
    this->andar = andar;
}

void Apartamento::setValorCondominio(float valor){
    valor_condominio = valor;
}

void Apartamento::setVagasGaragem(int quant){
    vagas_garagem = quant;
}

void Apartamento::lerAtributos(){
    Imovel::lerAtributos();

    std::cin >> area >> num_quartos >> andar >> valor_condominio >> vagas_garagem;
}

void Apartamento::exibeAtributos() const {
    Imovel::exibeAtributos();

    std::cout << " " << area << "m2 de área, "
              << num_quartos << " quartos, "
              << andar << " andar(es), "
              << valor_condominio << " de condomínio, "
              << vagas_garagem << " vaga(s) de garagem."
              << " R$ " << valor << "." << std::endl;
}

/////////////////////////////////////////////////////////////////////////////////////////////////


/******************************** Class Terreno : public Imovel ********************************/

/******** CONSTRUTORES / DESTRUTOR ********/
Terreno::Terreno()
       : Imovel()
{
    setTipoImovel(TipoImovel::TERRENO);

    area = 0;
}

Terreno::Terreno(float valor, std::string forma_negocio, float area)
       : Imovel(valor, TipoImovel::TERRENO, forma_negocio)
{
    this->area = area;
}

Terreno::~Terreno(){
    std::cout << "Deletando Terreno" << std::endl;
}


/******** MÉTODOS ********/
float Terreno::getArea() const { return area; }

void Terreno::setArea(float area){
    this->area = area;
}

void Terreno::lerAtributos(){
    Imovel::lerAtributos();
    
    std::cin >> area;
}

void Terreno::exibeAtributos() const {
    Imovel::exibeAtributos();

    std::cout << " " << area << "m2 de área de terreno."
              << " R$ " << valor << "." << std::endl;
}

/////////////////////////////////////////////////////////////////////////////////////


/******************************** Class Imobiliaria ********************************/

/******** CONSTRUTORES / DESTRUTOR ********/
Imobiliaria::Imobiliaria(){
    imoveis.clear();
}

Imobiliaria::~Imobiliaria(){
    std::cout << "Deletando Imobiliária" << std::endl;

    for (auto&& it : imoveis)
    {
        delete it;
    }
}


/******** OPERADORES ********/
Imovel* &Imobiliaria::operator[] (int indice){

    return imoveis[indice];
}


/******** MÉTODOS ********/
size_t Imobiliaria::size() const {
    return imoveis.size();
}

void Imobiliaria::addImovel(Imovel *imovel){
    imoveis.push_back(imovel);
}

void Imobiliaria::buscaImovel(std::string busca){

    for (auto&& it : imoveis)
    {
        if ((it->getNome() == busca) || (it->getFormaNegocio() == busca)){
            it->exibeAtributos();
        }
    }
}