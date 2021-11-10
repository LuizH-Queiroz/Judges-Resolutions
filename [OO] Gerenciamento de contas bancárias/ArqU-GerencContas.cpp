#include <iostream>
#include <string>

using namespace std;


class Conta
{
    protected:
        string nomeCliente;
        int numero;
        double saldo;

    public:
        /******** CONSTRUTORES / DESTRUTOR ********/
        Conta();
        Conta(string nome, int num, double saldo);
        virtual ~Conta();

        /******** MÉTODOS ********/
        string getNomeCliente();
        int getNumero();
        double getSaldo();

        void setNomeCliente(string nome);
        void setNumero(int numero);
        void setSaldo(double saldo);

        virtual void sacar(double valor);
        void depositar(double valor);
        virtual double saldoTotalDisponivel();
};


class ContaCorrente : public Conta
{
    protected:
        double salario;
        int limite;

    public:
        /******** CONSTRUTORES / DESTRUTOR ********/
        ContaCorrente();
        ContaCorrente(string nome, int num, double saldo, double salario);
        virtual ~ContaCorrente();

        /******** MÉTODOS ********/
        double getSalario();
        int getLimite();

        void setSalario(double salario);

        virtual double definirLimite();
        virtual void sacar(double valor) override;
        virtual double saldoTotalDisponivel() override;
};


class ContaEspecial : public ContaCorrente
{
    public:
        /******** CONSTRUTORES / DESTRUTOR ********/
        ContaEspecial();
        ContaEspecial(string nome, int num, double saldo, double salario);
        virtual ~ContaEspecial();

        /******** MÉTODOS ********/
        virtual double definirLimite() override;
};


class Poupanca : public Conta
{
    private:
        int variacao;
        double taxaRendimento;

    public:
        /******** CONSTRUTORES / DESTRUTOR ********/
        Poupanca();
        Poupanca(string nome, int num, double saldo, int variacao, double rendimento);
        virtual ~Poupanca();

        /******** MÉTODOS ********/
        int getVariacao();
        double getTaxaRendimento();

        void setVariacao(int variacao);
        void setTaxaRendimento(double rendimento);

        double render();
        virtual double saldoTotalDisponivel() override;
};



/****************************** Class Conta ******************************/
/******** CONSTRUTORES / DESTRUTOR ********/
Conta::Conta(){
    nomeCliente = "";
    numero = 0;
    saldo = 0;
}

Conta::Conta(string nome, int num, double saldo){
    this->nomeCliente = nome;
    this->numero = num;
    this->saldo = saldo;
}

Conta::~Conta(){

}

/******** MÉTODOS ********/
string Conta::getNomeCliente() { return nomeCliente; }

int Conta::getNumero() { return numero; }

double Conta::getSaldo() { return saldo; }

inline void Conta::setNomeCliente(string nome) { this->nomeCliente = nome; }

inline void Conta::setNumero(int numero) { this->numero = numero; }

inline void Conta::setSaldo(double saldo) { this->saldo = saldo; }

void Conta::sacar(double valor){

    if (valor <= saldo) saldo -= valor;
    else cout << "saldo insuficiente" << endl;
}

void Conta::depositar(double valor){
    saldo += valor;
}

double Conta::saldoTotalDisponivel(){
    return saldo;
}


//////////////////////////////////////////////////////////////////////////////////////////////////

/****************************** Class ContaCorrente : public Conta ******************************/
/******** CONSTRUTORES / DESTRUTOR ********/
ContaCorrente::ContaCorrente()
             : Conta()
{
    salario = 0;
    limite = 0;
}

ContaCorrente::ContaCorrente(string nome, int num, double saldo, double salario)
             : Conta(nome, num, saldo)
{
    this->salario = salario;
    definirLimite();
}

ContaCorrente::~ContaCorrente(){

}
/********* MÉTODOS *********/
double ContaCorrente::getSalario() { return salario; }

int ContaCorrente::getLimite() { return limite; }

inline void ContaCorrente::setSalario(double salario) { this->salario = salario; }

void ContaCorrente::sacar(double valor){

    if (valor <= (saldo + limite)){
        if (valor <= saldo){
            saldo -= valor;
        }
        else {
            saldo = 0;
            limite = limite - (valor - saldo);
        }
    }
    else cout << "\nsaldo insuficiente" << endl;
}

double ContaCorrente::definirLimite(){
    limite = 2*salario;
    return limite;
}

double ContaCorrente::saldoTotalDisponivel(){
    return saldo + limite;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////

/****************************** Class ContaEspecial : public ContaCorrente ******************************/
/******** CONSTRUTORES / DESTRUTOR ********/
ContaEspecial::ContaEspecial()
             : ContaCorrente()
{
}

ContaEspecial::ContaEspecial(string nome, int num, double saldo, double salario)
             : ContaCorrente(nome, num, saldo, salario)
{
    definirLimite();
}

ContaEspecial::~ContaEspecial(){

}

/******** MÉTODOS ********/
double ContaEspecial::definirLimite(){
    limite = 4*salario;
    return limite;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////

/****************************** Class Poupanca : public Conta ******************************/
/******** CONSTRUTORES / DESTRUTOR ********/
Poupanca::Poupanca()
        : Conta()
{
    variacao = 0;
    taxaRendimento = 0.006;
}

Poupanca::Poupanca(string nome, int num, double saldo, int variacao, double rendimento)
        : Conta(nome, num, saldo)
{
    this->variacao = variacao;
    this->taxaRendimento = rendimento;
}

Poupanca::~Poupanca(){

}

/******** MÉTODOS ********/
inline int Poupanca::getVariacao() { return variacao; }

inline double Poupanca::getTaxaRendimento() { return taxaRendimento; }

inline void Poupanca::setVariacao(int variacao) { this->variacao = variacao; }

inline void Poupanca::setTaxaRendimento(double rendimento) { this->taxaRendimento = rendimento; }

double Poupanca::render(){
    return saldo * taxaRendimento;
}

double Poupanca::saldoTotalDisponivel(){
    return saldo + render();
}


/*************************************************/
/****************** FUNÇÃO MAIN ******************/
/*************************************************/
int main(){
    ContaCorrente corrente;
    ContaEspecial especial;
    Poupanca poupanca;

    //Variáveis auxiliares:
    string nome;
    int numero;
    float salario;
    float deposito, saque;
    ///////////////////////


    getline(cin, nome);
    cin >> numero >> salario >> deposito >> saque;
    cin.ignore();
    corrente = ContaCorrente(nome, numero, 0, salario);
    cout << corrente.getNomeCliente() << ", cc: " << corrente.getNumero()
         << ", salário " << corrente.getSalario();
    corrente.depositar(deposito);
    corrente.sacar(saque);
    cout << ", saldo total disponível: R$ " << corrente.saldoTotalDisponivel() << endl;
    

    getline(cin, nome);
    cin >> numero >> salario >> deposito >> saque;
    cin.ignore();
    especial = ContaEspecial(nome, numero, 0, salario);
    cout << especial.getNomeCliente() << ", cc: " << especial.getNumero()
         << ", salário " << especial.getSalario()
         << ", ";
    especial.depositar(deposito);
    especial.sacar(saque);
    cout << "saldo total disponível: R$ " << especial.saldoTotalDisponivel() << endl;


    getline(cin, nome);
    cin >> numero >> deposito >> saque;
    poupanca = Poupanca(nome, numero, 0, 0, 0.006);
    poupanca.depositar(deposito);
    poupanca.sacar(saque);
    cout << poupanca.getNomeCliente() << ", cc: " << poupanca.getNumero()
         << ", saldo total disponível: R$ " << poupanca.saldoTotalDisponivel() << endl;




    return 0;
}