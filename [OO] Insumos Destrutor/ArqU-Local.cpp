#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Insumo
{
    protected:
        std::string nome;
        int quantidade;
        int valorUnitario;
        std::string dtVencimento;
        std::string nomeFabricante;
        int tipoInsumo;

    public:
        /******** CONSTRUTORES / DESTRUTOR ********/
        Insumo();
        Insumo(std::string insumo_nome, int quant, int valor, std::string vencimento,
               std::string fabricante, int tipo);
        virtual ~Insumo();
};


class Vacina : public Insumo
{
    private:
        int tipo;
        int quantDoses;
        int intervalo;

    public:
        /******** CONSTRUTORES / DESTRUTOR ********/
        Vacina();
        Vacina(std::string insumo_nome, int quant, int valor, std::string vencimento,
               std::string fabricante, int tipo, int tipo_vac, int n_doses, int interval);
        virtual ~Vacina();
};


class Medicamento : public Insumo
{
    private:
        std::string dosagem;
        std::string administracao;
        std::string disponibilizacao;

    public:
        /******** CONSTRUTORES / DESTRUTOR ********/
        Medicamento();
        Medicamento(std::string insumo_nome, int quant, int valor, std::string vencimento,
                    std::string fabricante, int tipo, std::string dosagem, std::string administracao,
                    std::string disponibilizacao);
        virtual ~Medicamento();
};


class EPI : public Insumo
{
    private:
        int tipo;
        std::string descricao;

    public:
        /******** CONSTRUTORES / DESTRUTOR ********/
        EPI();
        EPI(std::string insumo_nome, int quant, int valor, std::string vencimento,
            std::string fabricante, int tipo, int tipo_EPI, std::string descricao);
        virtual ~EPI();
};



class Local
{
    private:
        std::string nome;
        int tipo;
        Insumo* insumosArr[3];
        std::vector<Insumo*> insumosVec;

    public:
        /******** CONSTRUTORES / DESTRUTOR ********/
        Local();
        Local(std::string nome, int tipo);
        virtual ~Local();

        /******** MÉTODOS ********/
        void addInsumoArr(Insumo *in, int index);
        void addInsumoVec(Insumo *in);
};


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


/*************************************************************/
/********************** FUNÇÃO MAIN **************************/
/*************************************************************/
int main(){
    Local local;

    //Variáveis gerais (para todos os tipos de Insumo):
    string nome;
    int quantidade;
    int valorUnitario;
    string dtVencimento;
    string nomeFabricante;
    int tipoInsumo;
    ///////////////////////////
    

    /* Leitura dos dados da Vacina */
    {
        int tipo, quantDoses, intervalo;

        getline(cin, nome);
        cin >> quantidade >> valorUnitario;
        cin.ignore();
        getline(cin, dtVencimento);
        getline(cin, dtVencimento);
        getline(cin, nomeFabricante);
        getline(cin, nome);
        cin >> quantDoses >> intervalo;
        cin.ignore();

        local.addInsumoArr(new Vacina(nome, quantidade, valorUnitario, dtVencimento,
                           nomeFabricante, tipoInsumo, tipo, quantDoses, intervalo), 0);
        local.addInsumoVec(new Vacina(nome, quantidade, valorUnitario, dtVencimento,
                           nomeFabricante, tipo, tipo, quantDoses, intervalo));
    }


    /* Leitura de dados do Medicamento */
    {
        string dosagem, administ, disp;

        getline(cin, nome);
        cin >> quantidade >> valorUnitario;
        cin.ignore();
        getline(cin, dtVencimento);
        getline(cin, dtVencimento);
        getline(cin, nomeFabricante);
        getline(cin, dosagem);
        getline(cin, administ);
        getline(cin, disp);

        local.addInsumoArr(new Medicamento(nome, quantidade, valorUnitario, dtVencimento,
                           nomeFabricante, tipoInsumo, dosagem, administ, disp), 1);
        local.addInsumoVec(new Medicamento(nome, quantidade, valorUnitario, dtVencimento,
                           nomeFabricante, tipoInsumo, dosagem, administ, disp));
    }


    /* Leitura de dados do EPI */
    {
        int tipo;
        string descricao;

        getline(cin, nome);
        cin >> quantidade >> valorUnitario;
        cin.ignore();
        getline(cin, dtVencimento);
        getline(cin, dtVencimento);
        getline(cin, nomeFabricante);
        getline(cin, descricao);
        getline(cin, descricao);

        local.addInsumoArr(new EPI(nome, quantidade, valorUnitario, dtVencimento,
                           nomeFabricante, tipoInsumo, tipo, descricao), 2);
        local.addInsumoVec(new EPI(nome, quantidade, valorUnitario, dtVencimento,
                           nomeFabricante, tipoInsumo, tipo, descricao));
    }



    return 0;
}