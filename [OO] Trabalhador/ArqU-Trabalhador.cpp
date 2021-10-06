#include <iostream>
#include <string>

using namespace std;


class Trabalhador
{
    protected:
        string nome;
        float salario;

    public:
        /******** CONSTRUTORES ********/
        Trabalhador();

        /******** MÉTODOS ********/
        string getNome() const { return nome; }
        float getSalario() const { return salario; }

        void setNome(string);
        void setSalario(float);
};


class TrabalhadorAssalariado : public Trabalhador
{
    public:
        /******** CONSTRUTORES ********/
        TrabalhadorAssalariado();
        TrabalhadorAssalariado(float);

        /******** MÉTODOS ********/
        float calcularPagamentoSemanal() const;
};


class TrabalhadorPorHora : public Trabalhador
{
    private:
        float valorDaHora;

    public:
        static const int maxHorasSemanais; // Maximo de horas em que o pagamento eh nomal.
                                           // Apos isso o trabalhador recebe 150% do valorDaHora

        /******** CONSTRUTORES ********/
        TrabalhadorPorHora();
        TrabalhadorPorHora(float);

        /******** MÉTODOS ********/
        float getValorDaHora() const { return valorDaHora; }
        float getPagamentoSemanal() const { return salario / 4; }

        void setValorDaHora(float);

        float calcularPagamentoSemanal(int);
};



/********************* Class Trabalhador *********************/

/******** CONSTRUTORES ********/
Trabalhador::Trabalhador(){
    nome = "";
    salario = 0;
}

/******** MÉTODOS ********/
void Trabalhador::setNome(string nome){
    this->nome = nome;
}

void Trabalhador::setSalario(float sal){

    if (sal >= 0){
        salario = sal;
    }
}



/********************* Class TrabalhadorAssalariado *********************/

/******** CONSTRUTORES ********/
TrabalhadorAssalariado::TrabalhadorAssalariado() // Chamada implicita ao contrutor padrao
{                                                // Trabalhador::Trabalhador()
    //Nada para adicionar
}

TrabalhadorAssalariado::TrabalhadorAssalariado(float sal)
{
    nome = "";
    
    if (sal >= 0){
        salario = sal;
    }
    else {
        salario = 0;
    }
}

/******** MÉTODOS ********/
float TrabalhadorAssalariado::calcularPagamentoSemanal() const {
    return salario / 4;
}



/********************* Class TrabalhadorPorHora *********************/

const int TrabalhadorPorHora::maxHorasSemanais = 40;

/******** CONSTRUTORES ********/
TrabalhadorPorHora::TrabalhadorPorHora()
                  : Trabalhador()
{
    valorDaHora = 0;
}

TrabalhadorPorHora::TrabalhadorPorHora(float valor)
{ //Chamada implicita ao construtor Trabalhador::Trabalhador()
    if (valor >= 0){
        valorDaHora = valor;
    }
    else {
        valor = 0;
    }
}

/******** MÉTODOS ********/
void TrabalhadorPorHora::setValorDaHora(float valor){

    if (valor >= 0){
        valorDaHora = valor;
    }
}

float TrabalhadorPorHora::calcularPagamentoSemanal(int horasSemanais){

    if (horasSemanais < 0){
        return -1;
    }

    if (horasSemanais <= maxHorasSemanais){
        salario = (valorDaHora * horasSemanais) * 4; //O salario eh mensal
        return valorDaHora * horasSemanais;
    }
    else {
        int horasExcedentes = horasSemanais - maxHorasSemanais;
        salario = ((maxHorasSemanais * valorDaHora) + (horasExcedentes * valorDaHora * 1.5)) * 4;
        return salario / 4;
    }

}



/*********************************************/
/********       FUNÇÃO MAIN           ********/
/*********************************************/
extern void LerTrabalhadorSal(TrabalhadorAssalariado *);
extern void LerTrabalhadorHora(TrabalhadorPorHora *);

int main(){
    TrabalhadorAssalariado trab_sal;
    TrabalhadorPorHora trab_hora;
    int quantTrab, tipoTrab;


    cin >> quantTrab;
    for (int i = 0; i < quantTrab; i++)
    {
        cin >> tipoTrab; // 1 = TrabalhadoAssalariado; 2 = TrabalhadorPorHora
        cin.ignore();
        
        if (tipoTrab == 1){
            LerTrabalhadorSal(&trab_sal);
            cout << trab_sal.getNome() << " - Semanal: R$ " << trab_sal.calcularPagamentoSemanal()
                 << " - Mensal: R$ " << trab_sal.getSalario() << endl;
        }
        else {
            LerTrabalhadorHora(&trab_hora);
            cout << trab_hora.getNome() << " - Semanal: R$ " << trab_hora.getPagamentoSemanal()
                 << " - Mensal: R$ " << trab_hora.getSalario() << endl;
        }
    }


    return 0;
}


void LerTrabalhadorSal(TrabalhadorAssalariado *trab){

    string nome;
    float salario;

    getline(cin, nome);
    cin >> salario;

    trab->setNome(nome);
    trab->setSalario(salario);
}

void LerTrabalhadorHora(TrabalhadorPorHora *trab){

    string nome;
    float valorHora, horasSemanais;

    getline(cin, nome);
    cin >> valorHora >> horasSemanais;

    trab->setNome(nome);
    trab->setValorDaHora(valorHora);
    trab->calcularPagamentoSemanal(horasSemanais);
}