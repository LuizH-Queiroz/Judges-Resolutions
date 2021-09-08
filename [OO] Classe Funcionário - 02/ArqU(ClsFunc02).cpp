#include <iostream>
#include <string>

using namespace std;

class Funcionario{
    private:
        /* Atributos */
        string nome;
        string sobrenome;
        int salarioMensal;


    public:
        /* Construtor */
        Funcionario();
        Funcionario(string, string, int);


        /* Métodos (Protótipos) */
        string getNome();
        string getSobrenome();
        int getSalarioMensal();

        void setNome(string);
        void setSobrenome(string);
        void setSalarioMensal(int);

        int getSalarioAnual();
        void aumentaSalario(float percent);
};


/*/////// CONSTRUTORES ///////*/
Funcionario::Funcionario(){
    nome = "\0";
    sobrenome = "\0";
    salarioMensal = 0;
}

Funcionario::Funcionario(string nome, string sobrenome, int salario){
    this->nome = nome;
    this->sobrenome = sobrenome;
    this->salarioMensal = salario; //Uso opcional do ponteiro "this"
}


/*/////// MÉTODOS ///////*/
string Funcionario::getNome(){
    return nome;
}

string Funcionario::getSobrenome(){
    return sobrenome;
}

int Funcionario::getSalarioMensal(){
    return salarioMensal;
}


void Funcionario::setNome(string nome){
    this->nome = nome;
}

void Funcionario::setSobrenome(string sobrenome){
    this->sobrenome = sobrenome;
}

void Funcionario::setSalarioMensal(int salario){
    salarioMensal = salario;
}


int Funcionario::getSalarioAnual(){
    return salarioMensal * 12;
}

void Funcionario::aumentaSalario(float percent){
    salarioMensal += salarioMensal * percent;
}


/*///////////////////////////*/
/*/////// FUNÇÃO MAIN ///////*/
/*///////////////////////////*/
int main(){
    Funcionario *func; //func = funcionário
    int quantFunc; //"Func" = Funcionário
    string nome; //Nome
    string snome; //Sobrenome
    int salario; //Salário mensal


    cin >> quantFunc;
    getchar(); //Limpar '\n' do buffer de entrada
    func = new Funcionario[quantFunc];

    for (int i = 0; i < quantFunc; i++)
    {
        getline(cin, nome);
        getline(cin, snome);
        cin >> salario;
        getchar(); //Limpar '\n' do buffer

        if (salario < 0){
            salario = 0;
        }

        func[i] = Funcionario(nome, snome, salario);
    }

    for (int i = 0; i < quantFunc; i++)
    {
        cout << func[i].getNome() << " " << func[i].getSobrenome()
             << " - " << func[i].getSalarioMensal() << " - " << func[i].getSalarioAnual()
             << endl;


        func[i].aumentaSalario(0.1); //Aumenta salário em 10%

        cout << func[i].getSalarioAnual() << endl;
    }


    delete [] func;


    return 0;
}