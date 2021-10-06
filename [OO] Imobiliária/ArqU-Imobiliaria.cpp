#include <iostream>
#include <string>

using namespace std;


class Imovel
{
    protected:
        string tipo; //Terreno, Casa ou Apartamento
        float valor;
        bool vender;
        bool alugar;

    public:
        /******** CONSTRUTORES ********/
        Imovel();
        Imovel(int, float, string); //int para tipo, string para venda ou aluguel

        /******** MÉTODOS ********/
        string getTipo() const { return tipo; }
        float getValor() const { return valor; }


        bool paraVender() const { return vender; }
        bool paraAlugar() const { return alugar; }


        void lerAtributos();
        void exibeAtributos() const;
};

class Casa : public Imovel
{
    private:
        int num_pavimentos;
        int num_quartos;
        float areaTerreno;
        float areaConstruida;

    public:
        /******** CONSTRUTORES ********/
        Casa();
        Casa(float, string, int, int, float, float);

        /******** MÉTODOS ********/
        void lerAtributos();
        void exibeAtributos() const;
};

class Apartamento : public Imovel
{
    private:
        float area;
        int num_quartos;
        int andar;
        float valor_condominio;
        int vagas_garagem;

    public:
        /******** CONSTRUTORES ********/
        Apartamento();
        Apartamento(float, string, float, int, int, float, int);

        /******** MÉTODOS ********/
        void lerAtributos();
        void exibeAtributos() const;
};

class Terreno : public Imovel
{
    private:
        float area;

    public:
        /******** CONSTRUTORES ********/
        Terreno();
        Terreno(float, string, float);

        /******** MÉTODOS ********/
        void lerAtributos();
        void exibeAtributos() const;
};


/********************* Class Imovel *********************/

/******** CONSTRUTORES ********/
Imovel::Imovel(){
    tipo = "";
    valor = 0;
    vender = false;
    alugar = false;
}

Imovel::Imovel(int tipo, float valor, string venda_aluguel){

    switch (tipo){
        case 1:
            this->tipo = "Casa";
            break;
        case 2:
            this->tipo = "Apartamento";
            break;
        case 3:
            this->tipo = "Terreno";
            break;
    }

    if (valor >= 0) this->valor = valor;
    else this->valor = 0;

    if (venda_aluguel == "venda"){
        vender = true;
        alugar = false;
    }
    else if (venda_aluguel == "aluguel") {
        alugar = true;
        vender = false;
    }
    else {
        vender = alugar = false;
    }
}

/******** MÉTODOS ********/
void Imovel::lerAtributos(){
    float valor;
    string tipo;

    cin >> valor;
    cin.ignore();
    if (valor >= 0){
        this->valor = valor;
    }

    getline(cin, tipo);
    if (tipo == "venda"){
        vender = true;
        alugar = false;
    }
    else if (tipo == "aluguel"){
        alugar = true;
        vender = false;
    }
}

void Imovel::exibeAtributos() const{
    
    cout << tipo << " para ";
    if (vender){
        cout << "venda.";
    }
    else if (alugar){
        cout << "aluguel.";
    }
}



/********************* Class Casa *********************/

/******** CONSTRUTORES ********/
Casa::Casa()
    : Imovel()
{
    tipo = "Casa";
    num_pavimentos = num_quartos = 0;
    areaTerreno = areaConstruida = 0;
}

Casa::Casa(float valor, string venda_aluguel, int n_pav, int n_quart, float areaTer, float areaConst)
    : Imovel(1, valor, venda_aluguel)
{
    if (n_pav >= 0) num_pavimentos = n_pav;
    else num_pavimentos = 0;

    if (n_quart >= 0) num_quartos = n_quart;
    else num_quartos = 0;

    if (areaTer >= 0) areaTerreno = areaTer;
    else areaTerreno = 0;

    if (areaConst >= 0) areaConstruida = areaConst;
    else areaConstruida = 0;
}

/******** MÉTODOS ********/
void Casa::lerAtributos(){

    Imovel::lerAtributos();

    int pavimentos, quartos;
    float terreno, construido;

    cin >> pavimentos >> quartos
             >> terreno >> construido;

    if (pavimentos >= 0) num_pavimentos = pavimentos;

    if (quartos >= 0) num_quartos = quartos;

    if (terreno >= 0) areaTerreno = terreno;

    if (construido >= 0) areaConstruida = construido;
}

void Casa::exibeAtributos() const{

    Imovel::exibeAtributos();

    cout << " " << num_pavimentos << " pavimentos, "
              << num_quartos << " quartos, "
              << areaTerreno << "m2 de área de terreno e "
              << areaConstruida << "m2 de área construída. R$ "
              << valor << ".\n";
}



/********************* Class Apartamento *********************/

/******** CONSTRUTORES ********/
Apartamento::Apartamento()
           : Imovel()
{
    tipo = "Apartamento";
    area = 0;
    num_quartos = vagas_garagem = andar = 0;
    valor_condominio = 0;
}

Apartamento::Apartamento(float valor, string venda_aluguel, float area, int quartos,
                         int andar, float condominio, int garagem)
           : Imovel(2, valor, venda_aluguel)
{
    if (area >= 0) this->area = area;
    else this->area = 0;

    if (quartos >= 0) num_quartos = quartos;
    else num_quartos = 0;

    if (andar >= 0) this->andar = andar;
    else this->andar = 0;

    if (condominio >= 0) valor_condominio = condominio;
    else valor_condominio = 0;

    if (garagem >= 0) vagas_garagem = garagem;
    else vagas_garagem = 0;
}

/******** MÉTODOS ********/
void Apartamento::lerAtributos(){

    Imovel::lerAtributos();

    float area, condominio;
    int quartos, andar, garagem;

    cin >> area >> quartos >> andar >> condominio >> garagem;

    if (area >= 0) this->area = area;

    if (quartos >= 0) num_quartos = quartos;

    if (andar >= 0) this->andar = andar;

    if (condominio >= 0) valor_condominio = condominio;

    if (garagem >= 0) vagas_garagem = garagem;
}

void Apartamento::exibeAtributos() const{

    Imovel::exibeAtributos();

    cout << " " << area << "m2 de área, "
              << num_quartos << " quartos, "
              << andar << " andar(es), "
              << valor_condominio << " de condomínio, "
              << vagas_garagem << " vaga(s) de garagem. R$ "
              << valor << ".\n";
}



/********************* Class Terreno *********************/

/******** CONSTRUTORES ********/
Terreno::Terreno()
       : Imovel()
{
    tipo = "Terreno";
    area = 0;
}

Terreno::Terreno(float valor, string venda_aluguel, float area)
       : Imovel(3, valor, venda_aluguel)
{
    if (area >= 0) this->area = area;
    else this->area = 0;
}

/******** MÉTODOS ********/
void Terreno::lerAtributos(){

    Imovel::lerAtributos();

    float area;
    cin >> area;
    if (area >= 0) this->area = area;
}

void Terreno::exibeAtributos() const {

    Imovel::exibeAtributos();

    cout << " " << area << "m2 de área de terreno. R$ " << valor << ".\n";
}



/*********************************************/
/**********     FUNÇÃO MAIN         **********/
/*********************************************/
int main(){
    int nImoveis;
    int opcao;
    Casa casa;
    Apartamento apartamento;
    Terreno terreno;

    cin >> nImoveis;
    for (int i = 0; i < nImoveis; i++)
    {
        cin >> opcao;

        switch (opcao){
            case 0:
                cout << "Indefinido" << endl;
                break;
            case 1:
                casa.lerAtributos();
                casa.exibeAtributos();
                break;
            case 2:
                apartamento.lerAtributos();
                apartamento.exibeAtributos();
                break;
            case 3:
                terreno.lerAtributos();
                terreno.exibeAtributos();
                break;
        }
    }


    return 0;
}