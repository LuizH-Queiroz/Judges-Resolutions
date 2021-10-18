#include <iostream>
#include <string>

using namespace std;


class IConta
{
    public:
        /******** DESTRUTOR ********/
        virtual ~IConta() { /* VAZIO */ }

        /******** MÉTODOS ********/
        virtual void sacar(float valor) = 0;
        virtual void depositar(float valor) = 0;
        virtual float saldoTotalDisponivel() = 0;
};


class Conta : public IConta
{
    protected:
        string nomeCliente;
        int numeroConta;
        float salarioMensal;
        float saldo;
        float limite;

        /******** MÉTODO PROTECTED ********/
        virtual void definirLimite() { limite = 2 * salarioMensal; }

    public:
        /******** CONSTRUTORES / DESTRUTOR ********/
        Conta();
        Conta(string nome, int numero, float salario);
        virtual ~Conta() { /* VAZIO */ }

        /******** MÉTODOS ********/
        string getNome() const { return nomeCliente; }
        int getNumeroConta() const { return numeroConta; }
        float getSalarioMensal() const { return salarioMensal; }
        float getSaldo() const { return saldo; }
        float getLimite() const { return limite; }

        void setNomeCliente(string nome);
        void setNumeroConta(int numero);
        void setSalarioMensal(float salario);
        void setSaldo(float saldo);
        void setLimite(float limite);

        virtual void sacar(float valor) override;
        virtual void depositar(float valor) override;
        virtual float saldoTotalDisponivel() override;
};


class ContaEspecial : public Conta
{
    protected:
        /******** MÉTODO PROTECTED ********/
        virtual void definirLimite() override { limite = 3 * salarioMensal; }

    public:
        /******** CONSTRUTORES / DESTRUTOR ********/
        ContaEspecial() { /* VAZIO */ }
        ContaEspecial(string nome, int numero, float salario);
        virtual ~ContaEspecial() { /* VAZIO */ }
};



/******************************* Class Conta *******************************/

/******** CONSTRUTORES / DESTRUTOR ********/
Conta::Conta(){
    nomeCliente = "";
    numeroConta = 0;
    salarioMensal = saldo = limite = 0;    
}

Conta::Conta(string nome, int numero, float salario){
    nomeCliente = nome;

    if (numero > 0) numeroConta = numero;
    else numeroConta = 0;

    if (salario >= 0) salarioMensal = salario;
    else salarioMensal = 0;

    definirLimite();
}

/******** MÉTODOS ********/
void Conta::setNomeCliente(string nome){
    nomeCliente = nome;
}

void Conta::setNumeroConta(int numero){
    if (numero > 0) numeroConta = numero;
}

void Conta::setSalarioMensal(float salario){
    if (salario >= 0) salarioMensal = salario;
    definirLimite();
}

void Conta::setSaldo(float saldo){
    if (saldo >= 0) this->saldo = saldo;
}

void Conta::setLimite(float limite){
    if (limite >= 0) this->limite = limite;
}

void Conta::sacar(float valor){
    saldo -= valor;
}

void Conta::depositar(float valor){
    saldo += valor;
}

float Conta::saldoTotalDisponivel(){
    return saldo + limite;
}

/////////////////////////////////////////////////////////////////////////////

/******************************* Class Conta *******************************/

/******** CONSTRUTORES ********/
ContaEspecial::ContaEspecial(string nome, int numero, float salario)
             : Conta(nome, numero, salario)
{
    definirLimite();
}


/***************************************************************************/
/***********************     FUNCAO MAIN     *******************************/
/***************************************************************************/
int main(){
    Conta conta_normal;
    ContaEspecial conta_especial;

    //Variaveis intermediarias:
    string nome;
    int numeroConta;
    float salario;
    float depositar, sacar;
    ///////////////////////////

    getline(cin, nome);
    cin >> numeroConta >> salario >> depositar >> sacar;
    conta_normal = Conta(nome, numeroConta, salario);
    conta_normal.depositar(depositar);
    conta_normal.sacar(sacar);
    cout << conta_normal.getNome() << ", cc: " << conta_normal.getNumeroConta()
         << ", salário " << conta_normal.getSalarioMensal()
         << ", saldo total disponível: R$ " << conta_normal.saldoTotalDisponivel()
         << endl;


    cin.ignore();
    getline(cin, nome);
    cin >> numeroConta >> salario >> depositar >> sacar;
    conta_especial = ContaEspecial(nome, numeroConta, salario);
    conta_especial.depositar(depositar);
    conta_especial.sacar(sacar);
    cout << conta_especial.getNome() << ", cc: " << conta_especial.getNumeroConta()
         << ", salário " << conta_especial.getSalarioMensal()
         << ", saldo total disponível: R$ " << conta_especial.saldoTotalDisponivel()
         << endl;


    return 0;
}