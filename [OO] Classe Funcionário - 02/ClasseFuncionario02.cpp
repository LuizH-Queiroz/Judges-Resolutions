#include <iostream>
#include <string>
#include "Funcionario02.h"

using namespace std;

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