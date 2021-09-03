#include <iostream>
#include <string>

using namespace std;


class Funcionario {

    public:
        string nome;
        string sobrenome;
        int salarioMensal;


        int getSalarioAnual();
};


int Funcionario::getSalarioAnual(){
    return salarioMensal * 12;
}


int main(){
    int quantFuncionarios;
    Funcionario *funcionario;

    cin >> quantFuncionarios;
    getchar(); //Limpar buffer
    funcionario = new Funcionario[quantFuncionarios];

    for (int i = 0; i < quantFuncionarios; i++)
    {
        getline(cin, funcionario[i].nome);
        getline(cin, funcionario[i].sobrenome);
        cin >> funcionario[i].salarioMensal;
        getchar(); //Limpar buffer

        
        cout << funcionario[i].nome << " " << funcionario[i].sobrenome 
        << " - " << funcionario[i].salarioMensal << " - " << funcionario[i].getSalarioAnual() 
        << endl;
    }


    delete [] funcionario;


    return 0;
}