#include <iostream>
#include "Data.hpp"

using namespace std;

int main(){
    Data data;

    cin >> data.dia >> data.mes >> data.ano;

    cout << data.dia << "/" << data.mes << "/" << data.ano << endl;


    return 0;
}