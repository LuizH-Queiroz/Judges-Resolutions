#include <iostream>
#include "Data02.h"

using namespace std;

int main(){
    Data data = Data();
    int num;


    cin >> num;
    data.setDia(num);

    cin >> num;
    data.setMes(num);

    cin >> num;
    data.setAno(num);


    data.printData();


    return 0;
}