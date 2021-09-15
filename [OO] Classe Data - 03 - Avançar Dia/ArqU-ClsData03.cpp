#include <iostream>
#include <iomanip>

#define QUANT_DATA 1

using namespace std;


class Data {
    private:
        int dia;
        int mes;
        int ano;

        /*/////// MÉTODOS PRIVADOS ///////*/
        bool diaValido(int, int); //O mês também deve ser recebido
        bool mesValido(int);
        bool anoValido(int);

    public:
        /*/////// CONSTRUTORES ///////*/
        Data();
        Data(int, int, int);


        /*/////// MÉTODOS ///////*/
        int getDia();
        int getMes();
        int getAno();


        void setDia(int);
        void setMes(int);
        void setAno(int);


        void avancarDia();
};



enum DiasMes 
{ 
    JANEIRO = 31,
    FEVEREIRO = 28,
    MARCO = 31,
    ABRIL = 30,
    MAIO = 31,
    JUNHO = 30,
    JULHO = 31,
    AGOSTO = 31,
    SETEMBRO = 30,
    OUTUBRO = 31,
    NOVEMBRO = 30,
    DEZEMBRO = 31
};



/*/////// MÉTODOS PRIVADOS ///////*/
bool Data::diaValido(int dia, int mes){

    if (dia <= 0){
        return false;
    }

    switch (mes){
        case 1:
            if (dia > DiasMes::JANEIRO) return false;
            break;
        case 2:
            if (dia > DiasMes::FEVEREIRO) return false;
            break;
        case 3:
            if (dia > DiasMes::MARCO) return false;
            break;
        case 4:
            if (dia > DiasMes::ABRIL) return false;
            break;
        case 5:
            if (dia > DiasMes::MAIO) return false;
            break;
        case 6:
            if (dia > DiasMes::JUNHO) return false;
            break;
        case 7:
            if (dia > DiasMes::JULHO) return false;
            break;
        case 8:
            if (dia > DiasMes::AGOSTO) return false;
            break;
        case 9:
            if (dia > DiasMes::SETEMBRO) return false;
            break;
        case 10:
            if (dia > DiasMes::OUTUBRO) return false;
            break;
        case 11:
            if (dia > DiasMes::NOVEMBRO) return false;
            break;
        case 12:
            if (dia > DiasMes::DEZEMBRO) return false;
            break;
        default: //Aqui é considerado um mês qualquer de 31 dias
            if (dia <= 31){
                return true;
            }
            else {
                return false;
            }
    }


    return true;
}

bool Data::mesValido(int mes){

    if (mes <= 0 || mes > 12){
        return false;
    }
    else {
        return true;
    }
}

bool Data::anoValido(int ano){

    if (ano < 0){
        return false;
    }
    else {
        return true;
    }
}



/*/////// CONSTRUTORES ///////*/
Data::Data(){
    dia = 1;
    mes = 1;
    ano = 1;
}

Data::Data(int dia, int mes, int ano){

    if (anoValido(ano)){
        this->ano = ano;
    }
    else {
        cout << "Atributo ano Inválido" << endl;
        this->ano = 1;
    }

    if (mesValido(mes)){
        this->mes = mes;
    }
    else {
        cout << "Atributo mês Inválido" << endl;
        this->mes = 1;
    }

    if (diaValido(dia, mes)){
        this->dia = dia;
    }
    else {
        cout << "Atributo dia Inválido" << endl;
        this->dia = 1;
    }

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



void Data::setDia(int d){

    if (diaValido(d, mes)){
        dia = d;
    }
}

void Data::setMes(int m){

    if (mesValido(m)){
        mes = m;
    }
}

void Data::setAno(int a){

    if (anoValido(a)){
        ano = a;
    }
}



void Data::avancarDia(){

    if (diaValido(dia + 1, mes)){
        dia++;
    }
    else if (mesValido(mes + 1)){
        dia = 1;
        mes++;
    }
    else { //ANO NOVO!
        ano++;
        mes = 1;
        dia = 1;
    }
}



/*////////////////////////////////////////*/
/*///////////// FUNÇÃO MAIN //////////////*/
/*////////////////////////////////////////*/
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