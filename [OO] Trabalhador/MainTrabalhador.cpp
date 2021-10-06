#include <iostream>
#include <string>
#include "trabalhador.h"

using namespace std;


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