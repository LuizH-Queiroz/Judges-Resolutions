
/* ////////////////   ARQUIVO Data.hpp   ////////////////////*/
class Data {
    public:
        Data(); 
        int dia, mes, ano;
};


/* ////////////////   Data.cpp   ////////////////////*/
Data::Data(){
    dia = 1;
    mes = 1;
    ano = 1;
}

/* ////////////////   ARQUIVO Main.cpp   ////////////////////*/
#include <iostream>

using namespace std;

int main(){
    Data data;

    cin >> data.dia >> data.mes >> data.ano;

    cout << data.dia << "/" << data.mes << "/" << data.ano << endl;
    

    return 0;
}