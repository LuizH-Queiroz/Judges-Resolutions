#include <iostream>
#include <iomanip>
#include "Data03.h"

#define QUANT_DATA 1

using namespace std;


int main(){
    Data *data = new Data[QUANT_DATA];
    int dia, mes, ano;
    int avancar;


    for (int i = 0; i < QUANT_DATA; i++)
    {
        cin >> dia >> mes >> ano;

        data[i] = Data(dia, mes, ano);


        cin >> avancar;
        for (int j = 0; j < avancar; j++)
        {
            data[i].avancarDia();
        }

        cout << setfill('0') << setw(2)
             << data[i].getDia() << "/"
             << setfill('0') << setw(2)
             << data[i].getMes() << "/"
             << data[i].getAno();
    }


    delete [] data;


    return 0;
}