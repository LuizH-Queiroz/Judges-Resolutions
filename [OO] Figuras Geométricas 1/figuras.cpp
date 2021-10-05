#include <iostream>
#include "figuras.h"

/********************* Class FiguraGeometrica *********************/

/******** CONSTRUTORES ********/
FiguraGeometrica::FiguraGeometrica(){
    nome = "Indefinido";
    tipo = 0;
}

FiguraGeometrica::FiguraGeometrica(int tipo){

    if (tipo >= 1 && tipo <= 4){
        this->tipo = tipo;
    }
    else {
        return;
    }

    switch (tipo){
        case 1:
            nome = "Quadrado";
            break;
        case 2:
            nome = "Retângulo";
            break;
        case 3:
            nome = "Triângulo";
            break;
        case 4:
            nome = "Círculo";
            break;
    }
}


/******** MÉTODOS ********/
inline std::string FiguraGeometrica::getNome() const{
    return nome;
}



/********************* Class Circulo *********************/

const float Circulo::PI = 3.14;

/******** CONSTRUTORES ********/
Circulo::Circulo()
       : FiguraGeometrica(4)
{
    raio = 0;
}

Circulo::Circulo(float r)
       : FiguraGeometrica(4)
{
    if (r >= 0){
        raio = r;
    }
    else {
        raio = 0;
    }
}


/******** MÉTODOS ********/
void Circulo::lerAtributosArea(){
    float r;

    std::cin >> r;

    if (r >= 0){
        raio = r;
    }
}

float Circulo::calcularArea() const{
    return PI * raio * raio;
}



/********************* Class Triangulo *********************/

/******** CONSTRUTORES ********/
Triangulo::Triangulo()
         : FiguraGeometrica(3)
{
    base = altura = 0;
}

Triangulo::Triangulo(float b, float h)
         : FiguraGeometrica(3)
{
    if (b >= 0){
        base = b;
    }
    else {
        base = 0;
    }

    if (h >= 0){
        altura = h;
    }
    else {
        altura = 0;
    }
}

/******** MÉTODOS ********/
void Triangulo::lerAtributosArea(){
    float b, h;
    
    std::cin >> b >> h;

    if (b >= 0){
        base = b;
    }

    if (h >= 0){
        altura = h;
    }
}

float Triangulo::calcularArea() const{
    return (base * altura) / 2;
}



/********************* Class Quadrado *********************/

/******** CONSTRUTORES ********/
Quadrado::Quadrado()
        : FiguraGeometrica(1)
{
    lado = 0;
}

Quadrado::Quadrado(float l)
        : FiguraGeometrica(1)
{
    if (l >= 0){
        lado = l;
    }
    else {
        lado = 0;
    }
}

/******** MÉTODOS ********/
void Quadrado::lerAtributosArea(){
    float l;

    std::cin >> l;

    if (l >= 0){
        lado = l;
    }
}

float Quadrado::calcularArea() const{
    return lado * lado;
}



/********************* Class Quadrado *********************/

/******** CONSTRUTORES ********/
Retangulo::Retangulo()
         : FiguraGeometrica(2)
{
    lado_1 = lado_2 = 0;
}

Retangulo::Retangulo(float l1, float l2)
         : FiguraGeometrica(2)
{
    if (l1 >= 0){
        lado_1 = l1;
    }
    else {
        lado_1 = 0;
    }

    if (l2 >= 0){
        lado_2 = l2;
    }
    else {
        lado_2 = 0;
    }
}

/******** MÉTODOS ********/
void Retangulo::lerAtributosArea(){
    float l1, l2;

    std::cin >> l1 >> l2;

    if (l1 >= 0){
        lado_1 = l1;
    }

    if (l2 >= 0){
        lado_2 = l2;
    }
}

float Retangulo::calcularArea() const{
    return lado_1 * lado_2;
}