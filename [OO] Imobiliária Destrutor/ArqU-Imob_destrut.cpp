#include <iostream>
#include <string>
#include <vector>

using namespace std;


enum TipoImovel
{
    INDEFINIDO = 0,
    CASA = 1,
    APARTAMENTO = 2,
    TERRENO = 3
};


class Imovel
{
    protected:
        string nome;
        float valor;
        TipoImovel tipo;
        string forma_negocio;

    public:
        /******** CONSTRUTORES / DESTRUTOR ********/
        Imovel();
        Imovel(float valor, TipoImovel tipo, string forma_negocio);
        virtual ~Imovel();


        /******** MÉTODOS ********/
        string getNome() const;
        float getValor() const;
        TipoImovel getTipoImovel() const;
        string getFormaNegocio() const;

        void setNome(string nome);
        void setValor(float valor);
        void setTipoImovel(TipoImovel tipo);
        void setFormaNegocio(string forma);

        virtual void lerAtributos();
        virtual void exibeAtributos() const;
};


class Casa : public Imovel
{
    private:
        int num_pavimentos;
        int num_quartos;
        float area_terreno;
        float area_construida;

    public:
        /******** CONSTRUTORES / DESTRUTOR ********/
        Casa();
        Casa(float valor, string forma_negocio,
             int num_pavimentos, int num_quartos, float area_terreno, float area_construida);
        virtual ~Casa();


        /******** MÉTODOS ********/
        int getNumPavimentos() const;
        int getNumQuartos() const;
        float getAreaTerreno() const;
        float getAreaConstruida() const;

        void setNumPavimentos(int num);
        void setNumQuartos(int num);
        void setAreaTerreno(float area);
        void setAreaConstruida(float area);

        virtual void lerAtributos() override;
        virtual void exibeAtributos() const override;
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
        /******** CONSTRUTORES / DESTRUTOR ********/
        Apartamento();
        Apartamento(float valor, string forma_negocio,
                    float area, int num_quartos, int andar, float valor_condominio, int vagas_garagem);
        virtual ~Apartamento();


        /******** MÉTODOS ********/
        float getArea() const;
        int getNumQuartos() const;
        int getAndar() const;
        float getValorCondominio() const;
        int getVagasGaragem() const;

        void setArea(float area);
        void setNumQuartos(int num);
        void setAndar(int andar);
        void setValorCondominio(float valor);
        void setVagasGaragem(int quant);

        virtual void lerAtributos() override;
        virtual void exibeAtributos() const override;
};


class Terreno : public Imovel
{
    private:
        float area;

    public:
        /******** CONSTRUTORES / DESTRUTOR ********/
        Terreno();
        Terreno(float valor, string forma_negocio, float area);
        virtual ~Terreno();


        /******** MÉTODOS ********/
        float getArea() const;

        void setArea(float area);

        virtual void lerAtributos() override;
        virtual void exibeAtributos() const override;
};

///////////////////////////////////////////////////////////////////////////////////////

/******************************** Class Imobiliaria ********************************/
class Imobiliaria
{
    private:
        vector<Imovel*> imoveis;

    public:
        /******** CONSTRUTORES / DESTRUTOR ********/
        Imobiliaria();
        virtual ~Imobiliaria();


        /******** OPERADORES ********/
        Imovel* &operator[] (int indice);


        /******** MÉTODOS ********/
        size_t size() const;

        void addImovel(Imovel *imovel);
        void buscaImovel(string busca);
};



/******************************** Class Imovel ********************************/

/******** CONSTRUTORES / DESTRUTOR ********/
Imovel::Imovel(){
    nome = "";
    valor = 0;
    tipo = TipoImovel::INDEFINIDO;
    forma_negocio = "";
}

Imovel::Imovel(float valor, TipoImovel tipo, string forma){
    this->valor = valor;
    setTipoImovel(tipo);
    forma_negocio = forma;
}

Imovel::~Imovel(){
    cout << "Deletando Imovel" << endl;
}


/******** MÉTODOS ********/
string Imovel::getNome() const { return nome; }
float Imovel::getValor() const { return valor; }
TipoImovel Imovel::getTipoImovel() const { return tipo; }
string Imovel::getFormaNegocio() const { return forma_negocio; }

void Imovel::setNome(string nome){
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

void Imovel::setFormaNegocio(string forma) {
    forma_negocio = forma;
}

void Imovel::lerAtributos(){
    cin >> valor;
    cin.ignore();
    getline(cin, forma_negocio);
}

void Imovel::exibeAtributos() const{
    cout << nome << " para " + forma_negocio + ".";
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

Casa::Casa(float valor, string forma_negocio,
        int num_pavimentos, int num_quartos, float area_terreno, float area_construida)
    : Imovel(valor, TipoImovel::CASA, forma_negocio)
{
    this->num_pavimentos = num_pavimentos;
    this->num_quartos = num_quartos;
    this->area_terreno = area_terreno;
    this->area_construida = area_construida;
}

Casa::~Casa(){
    cout << "Deletando Casa" << endl;
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

    cin >> num_pavimentos >> num_quartos >> area_terreno >> area_construida;
}

void Casa::exibeAtributos() const {
    Imovel::exibeAtributos();

    cout << " " << num_pavimentos << " pavimentos, "
              << num_quartos << " quartos, "
              << area_terreno << "m2 de área de terreno e "
              << area_construida << "m2 de área construída."
              << " R$ " << valor << "." << endl;
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

Apartamento::Apartamento(float valor, string forma_negocio,
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
    cout << "Deletando Apartamento" << endl;
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

    cin >> area >> num_quartos >> andar >> valor_condominio >> vagas_garagem;
}

void Apartamento::exibeAtributos() const {
    Imovel::exibeAtributos();

    cout << " " << area << "m2 de área, "
              << num_quartos << " quartos, "
              << andar << " andar(es), "
              << valor_condominio << " de condomínio, "
              << vagas_garagem << " vaga(s) de garagem."
              << " R$ " << valor << "." << endl;
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

Terreno::Terreno(float valor, string forma_negocio, float area)
       : Imovel(valor, TipoImovel::TERRENO, forma_negocio)
{
    this->area = area;
}

Terreno::~Terreno(){
    cout << "Deletando Terreno" << endl;
}


/******** MÉTODOS ********/
float Terreno::getArea() const { return area; }

void Terreno::setArea(float area){
    this->area = area;
}

void Terreno::lerAtributos(){
    Imovel::lerAtributos();
    
    cin >> area;
}

void Terreno::exibeAtributos() const {
    Imovel::exibeAtributos();

    cout << " " << area << "m2 de área de terreno."
              << " R$ " << valor << "." << endl;
}

/////////////////////////////////////////////////////////////////////////////////////


/******************************** Class Imobiliaria ********************************/

/******** CONSTRUTORES / DESTRUTOR ********/
Imobiliaria::Imobiliaria(){
    imoveis.clear();
}

Imobiliaria::~Imobiliaria(){
    cout << "Deletando Imobiliária" << endl;

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

void Imobiliaria::buscaImovel(string busca){

    for (auto&& it : imoveis)
    {
        if ((it->getNome() == busca) || (it->getFormaNegocio() == busca)){
            it->exibeAtributos();
        }
    }
}


/****************************************************************/
/************************ FUNÇÃO MAIN ***************************/
/****************************************************************/
int main(){
    Imobiliaria imob;
    int n_imoveis;
    int tipoImovel;


    cin >> n_imoveis;
    for (int i = 0; i < n_imoveis; i++)
    {
        cin >> tipoImovel;

        switch (tipoImovel){
            case TipoImovel::CASA:
                imob.addImovel(new Casa());
                break;
            case TipoImovel::APARTAMENTO:
                imob.addImovel(new Apartamento());
                break;
            case TipoImovel::TERRENO:
                imob.addImovel(new Terreno());
                break;
        }

        imob[imob.size()-1]->lerAtributos();
    }


    string buscar;
    cin.ignore();
    getline(cin, buscar);
    imob.buscaImovel(buscar);


    return 0;
}