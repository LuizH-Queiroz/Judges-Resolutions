#include <iostream>
#include <string>

#define N_FUNC 1 //Quantidade de funcionarios
#define N_CONSULT 1 //Quantidade de consultores

using namespace std;


class Funcionario
{
    protected:
        int matricula;
        string nome;
        float salario;

    public:
        /******** MÉTODOS ********/
        int getMatricula() const { return matricula; }
        string getNome() const { return nome; }
        float getSalario() const { return salario; }

        void setMatricula(int);
        void setNome(string);
        void setSalario(float);
};

class Consultor : public Funcionario
{
    public:
        /******** MÉTODOS ********/
        float getSalario() const { return salario * 1.1; }
        float getSalario(float) const;
};



/********************* Class Funcionario *********************/

/******** MÉTODOS ********/
void Funcionario::setMatricula(int mat){
    
    if (mat > 0){
        matricula = mat;
    }
}

void Funcionario::setNome(string n){
    nome = n;
}

void Funcionario::setSalario(float sal){
    
    if (sal >= 0){
        salario = sal;
    }
}



/********************* Class Funcionario *********************/

/******** MÉTODOS ********/
float Consultor::getSalario(float percent) const{
    return salario * (1 + percent);
}



/******************************************************/
/**************     FUNÇÃO MAIN        ****************/
/******************************************************/
int main(){
    Funcionario funcionario;
    Consultor consultor;

    //Variaveis auxiliares:
    int matricula;
    string nome;
    float salario;
    ////////////////////////////////////////////


    for (int i = 0; i < N_FUNC; i++)
    {
        cin >> matricula;
        cin.ignore();
        getline(cin, nome);
        cin >> salario;

        funcionario.setMatricula(matricula);
        funcionario.setNome(nome);
        funcionario.setSalario(salario);

        cout << funcionario.getMatricula() << " - " << funcionario.getNome()
             << " - R$ " << funcionario.getSalario() << endl;
    }

    for (int i = 0; i < N_CONSULT; i++)
    {
        cin >> matricula;
        cin.ignore();
        getline(cin, nome);
        cin >> salario;

        consultor.setMatricula(matricula);
        consultor.setNome(nome);
        consultor.setSalario(salario);

        cout << consultor.getMatricula() << " - " << consultor.getNome()
             << " - R$ " << consultor.getSalario() << endl;
    }


    return 0;
}