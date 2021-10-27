#include <iostream>
#include <string>
#include "Insumo.h"

using namespace std;


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