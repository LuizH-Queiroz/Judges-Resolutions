#include <iostream>
#include <iomanip>
#include <exception>
#include <string>
#include <vector>


using namespace std;


class FuncionarioNaoExisteException : exception
{
    public:
        virtual const char * what() {return "FuncionarioNaoExisteException ";}
};


class OrcamentoEstouradoException : exception
{
    public:
        virtual const char * what() {return "OrcamentoEstouradoException ";}
};


class Funcionario
{
    private:
        string nome;
        int matricula;

    public:
        /******** CONSTRUTORES E DESTRUTOR ********/
        Funcionario();
        Funcionario(string nome, int matricula);
        virtual ~Funcionario();

        /******** MÉTODOS ********/
        string getNome();
        int getMatricula();

        void setNome(string nome);
        void setMatricula(int matricula);

        virtual double calcularSalario() = 0;
};


class Assalariado : Funcionario
{
    private:
        double salario;

    public:
        /******** CONSTRUTORES E DESTRUTOR ********/
        Assalariado();
        Assalariado(string nome, int matricula, double salario);
        virtual ~Assalariado();

        /******** MÉTODOS ********/
        //double getSalario(); //Usar calcularSalario() no lugar

        void setSalario(double sal);

        virtual double calcularSalario() override;
};


class Horista : Funcionario
{
    private:
        double salarioPorHora;
        double horasTrabalhadas; //Horas semanais trabalhadas

    public:
        /******** CONSTRUTORES E DESTRUTOR ********/
        Horista();
        Horista(string nome, int matricula, double salarioHora, double horasTrabalhadas);
        virtual ~Horista();

        /******** MÉTODOS ********/
        double getSalarioPorHora();
        double getHorasTrabalhadas();

        void setSalarioPorHora(double sal);
        void setHorasTrabalhadas(double horas);

        virtual double calcularSalario() override;
};


class Comissionado : Funcionario
{
    private:
        double vendasMensais;
        double percentualComissao;

    public:
        /******** CONSTRUTORES E DESTRUTOR ********/
        Comissionado();
        Comissionado(string nome, int matricula, double vendas, double percentual);
        virtual ~Comissionado();

        /******** MÉTODOS ********/
        double getVendasMensais();
        double getPercentualComissao();

        void setVendasMensais(double vendas);
        void setPercentualComissao(double percentual);

        virtual double calcularSalario() override;
};


class SistemaGerenciaFolha
{
    private:
        vector<Funcionario*> funcionarios;
        double orcamento_maximo;

    public:
        /******** CONSTRUTORES E DESTRUTOR ********/
        SistemaGerenciaFolha(double maximo);
        virtual ~SistemaGerenciaFolha();

        /******** MÉTODOS ********/
        void setFuncionarios(Funcionario * func);

        double calculaValorTotalFolha();
        double consultaSalarioFuncionario(string nome);
};


/************************** Class Funcionario **************************/

/******** CONSTRUTORES E DESTRUTOR ********/
Funcionario::Funcionario(){
    nome = "";
    matricula = 0;
}

Funcionario::Funcionario(string nome, int matricula){
    this->nome = nome;
    this->matricula = matricula;
}

Funcionario::~Funcionario(){ }

/******** MÉTODOS ********/
string Funcionario::getNome() { return nome; }
int Funcionario::getMatricula() { return matricula; }

void Funcionario::setNome(string nome){
    this->nome = nome;
}

void Funcionario::setMatricula(int matricula){
    this->matricula = matricula;
}

///////////////////////////////////////////////////////////////////////////////////////


/************************** Class Assalariado : Funcionario **************************/

/******** CONSTRUTORES E DESTRUTOR ********/
Assalariado::Assalariado()
           : Funcionario()
{
    salario = 0;
}

Assalariado::Assalariado(string nome, int matricula, double salario)
           : Funcionario(nome, matricula)
{
    this->salario = salario;
}

Assalariado::~Assalariado(){ }

/******** MÉTODOS ********/
void Assalariado::setSalario(double sal){
    salario = sal;
}

double Assalariado::calcularSalario() { return salario; }

///////////////////////////////////////////////////////////////////////////////////


/************************** Class Horista : Funcionario **************************/

/******** CONSTRUTORES E DESTRUTOR ********/
Horista::Horista()
       : Funcionario()
{
    salarioPorHora = 0;
    horasTrabalhadas = 0;
}

Horista::Horista(string nome, int matricula, double salarioHora, double horasTrabalhadas)
       : Funcionario(nome, matricula)
{
    this->salarioPorHora = salarioHora;
    this->horasTrabalhadas = horasTrabalhadas;
}

Horista::~Horista(){ }

/******** MÉTODOS ********/
double Horista::getSalarioPorHora() { return salarioPorHora; }
double Horista::getHorasTrabalhadas() { return horasTrabalhadas; }

void Horista::setSalarioPorHora(double sal){
    salarioPorHora = sal;
}

void Horista::setHorasTrabalhadas(double horas){
    horasTrabalhadas = horas;
}

double Horista::calcularSalario(){
    double salario = 0;

    if (horasTrabalhadas <= 40){
        salario = horasTrabalhadas * salarioPorHora * 4;
    }
    else {
        salario += 40 * salarioPorHora * 4;
        salario += (horasTrabalhadas - 40) * (salarioPorHora * 1.5) * 4;
    }

    return salario;
}

////////////////////////////////////////////////////////////////////////////////////////


/************************** Class Comissionado : Funcionario **************************/

/******** CONSTRUTORES E DESTRUTOR ********/
Comissionado::Comissionado()
            : Funcionario()
{
    vendasMensais = 0;
    percentualComissao = 0;
}

Comissionado::Comissionado(string nome, int matricula, double vendas, double percentual)
            : Funcionario(nome, matricula)
{
    this->vendasMensais = vendas;
    this->percentualComissao = percentual;
}

Comissionado::~Comissionado() { }

/******** MÉTODOS ********/
double Comissionado::getVendasMensais() { return vendasMensais; }
double Comissionado::getPercentualComissao() { return percentualComissao; }

void Comissionado::setVendasMensais(double vendas){
    vendasMensais = vendas;
}

void Comissionado::setPercentualComissao(double percentual){
    percentualComissao = percentual;
}

double Comissionado::calcularSalario(){
    return percentualComissao * vendasMensais;
}

//////////////////////////////////////////////////////////////////////////////////


/************************** Class SistemaGerenciaFolha **************************/

/******** CONSTRUTORES E DESTRUTOR ********/
SistemaGerenciaFolha::SistemaGerenciaFolha(double maximo) {
    orcamento_maximo = maximo;
}

SistemaGerenciaFolha::~SistemaGerenciaFolha(){
    for (auto&& it : funcionarios) delete it;
    funcionarios.clear();
}

/******** MÉTODOS ********/
void SistemaGerenciaFolha::setFuncionarios(Funcionario * func){
    funcionarios.push_back(func);
}

double SistemaGerenciaFolha::calculaValorTotalFolha(){
    double total = 0;

    for (auto&& it : funcionarios) total += it->calcularSalario();

    if (total > orcamento_maximo) throw OrcamentoEstouradoException().what() + to_string((int) total);

    return total;
}

double SistemaGerenciaFolha::consultaSalarioFuncionario(string nome){

    for (auto&& it : funcionarios) if (it->getNome() == nome) return it->calcularSalario();

    throw new FuncionarioNaoExisteException();
}


/*********************************************************/
/******************** FUNCAO MAIN ************************/
/*********************************************************/
int main(){
    Assalariado *assalariado = new Assalariado();
    Horista *horista = new Horista();
    Comissionado *comissionado = new Comissionado();

    //Variáveis auxiliares
    string nome;
    int matricula;
    double salario;
    double salarioHora, horasTrabalhadas;
    double vendasMensais, percentualComissao;
    //////////////////

    double orcamento_maximo;


    cin >> orcamento_maximo;
    cin.ignore();
    SistemaGerenciaFolha sistema(orcamento_maximo);


    getline(cin, nome);
    cin >> matricula >> salario;
    cin.ignore();
    *assalariado = Assalariado(nome, matricula, salario);
    sistema.setFuncionarios((Funcionario *) assalariado);


    getline(cin, nome);
    cin >> matricula >> salarioHora >> horasTrabalhadas;
    cin.ignore();
    *horista = Horista(nome, matricula, salarioHora, horasTrabalhadas);
    sistema.setFuncionarios((Funcionario *) horista);


    getline(cin, nome);
    cin >> matricula >> vendasMensais >> percentualComissao;
    cin.ignore();
    *comissionado = Comissionado(nome, matricula, vendasMensais, percentualComissao);
    sistema.setFuncionarios((Funcionario *) comissionado);


    getline(cin, nome);
    try
    {
        cout << sistema.consultaSalarioFuncionario(nome) << endl;
    }
    catch(FuncionarioNaoExisteException * e)
    {
        cout << e->what() << nome << '\n';
        delete e;
    }
    
    getline(cin, nome);
    try
    {
        cout << sistema.consultaSalarioFuncionario(nome) << endl;
    }
    catch(FuncionarioNaoExisteException * e)
    {
        cout << e->what() << nome << '\n';
        delete e;
    }

    getline(cin, nome);
    try
    {
        cout << sistema.consultaSalarioFuncionario(nome) << endl;
    }
    catch(FuncionarioNaoExisteException * e)
    {
        cout << e->what() << nome << '\n';
        delete e;
    }


    try
    {
        cout << sistema.calculaValorTotalFolha() << endl;
    }
    catch(string e)
    {
        cout << e << '\n';
    }
    


    return 0;
}