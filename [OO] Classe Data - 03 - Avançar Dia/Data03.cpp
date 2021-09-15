#include <iostream>
#include "Data03.h"


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
        std::cout << "Atributo ano Inválido" << std::endl;
        this->ano = 1;
    }

    if (mesValido(mes)){
        this->mes = mes;
    }
    else {
        std::cout << "Atributo mês Inválido" << std::endl;
        this->mes = 1;
    }

    if (diaValido(dia, mes)){
        this->dia = dia;
    }
    else {
        std::cout << "Atributo dia Inválido" << std::endl;
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