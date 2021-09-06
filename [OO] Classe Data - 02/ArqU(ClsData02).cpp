#include <iostream>

using namespace std;


class Data {
    private:
        int dia, mes, ano;

    
    public:
        /* Construtor */
        Data();


        /* Métodos */
        int getDia();
        int getMes();
        int getAno();

        void setDia(int);
        void setMes(int);
        void setAno(int);

        void printData();
};


/*/////// CONSTRUTOR ///////*/
Data::Data(){
    dia = 1;
    mes = 1;
    ano = 1;
}


/*/////// MÉTODOS ///////*/
int Data::getDia(){
    return dia;
}

int Data::getMes(){
    return mes;
}

int Data::getAno(){
    return ano;
}


void Data::setDia(int dia){
    this->dia = dia;
}

void Data::setMes(int mes){
    this->mes = mes;
}

void Data::setAno(int ano){
    this->ano = ano;
}


void Data::printData(){

    std::cout << getDia() << " de ";

    switch (getMes()){
        case 1:
            std::cout << "Janeiro";
            break;
        case 2:
            std::cout << "Fevereiro";
            break;
        case 3:
            std::cout << "Março";
            break;
        case 4:
            std::cout << "Abril";
            break;
        case 5:
            std::cout << "Maio";
            break;
        case 6:
            std::cout << "Junho";
            break;
        case 7:
            std::cout << "Julho";
            break;
        case 8:
            std::cout << "Agosto";
            break;
        case 9:
            std::cout << "Setembro";
            break;
        case 10:
            std::cout << "Outubro";
            break;
        case 11:
            std::cout << "Novembro";
            break;
        case 12:
            std::cout << "Dezembro";
            break;
        default:
            std::cout << "Indefinido";
            break;
    }

    std::cout << " de " << getAno() << std::endl;
}


/*///////////////////////////*/
/*/////// FUNÇÃO MAIN ///////*/
/*////////////////////////// */
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