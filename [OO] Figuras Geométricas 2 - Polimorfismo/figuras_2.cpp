#include <iostream>
#include "figuras_2.h"


/******************************* Class FiguraGeometrica *******************************/

/******** CONSTRUTORES / DESTRUTOR ********/
FiguraGeometrica::FiguraGeometrica(){
    tipo = 0;
    nome = "Indefinido";
}

FiguraGeometrica::FiguraGeometrica(Figura tipo)
{
    this->tipo = tipo;

    switch (tipo){
        case Figura::QUADRADO:
            nome = "Quadrado";
            break;
        case Figura::RETANGULO:
            nome = "Retângulo";
            break;
        case Figura::TRIANGULO:
            nome = "Triângulo";
            break;
        case Figura::CIRCULO:
            nome = "Círculo";
            break;
        default:
            nome = "Indefinido";
            break;
    }
}


/******************************* Class Triangulo : public FiguraGeometrica *******************************/

/******** CONSTRUTORES / DESTRUTOR ********/
Triangulo::Triangulo()
         : FiguraGeometrica(Figura::TRIANGULO)
{
    base = altura = 0;
}

Triangulo::Triangulo(float base, float altura)
         : FiguraGeometrica(Figura::TRIANGULO)
{
    this->base = base;
    this->altura = altura;
}

/******** MÉTODOS ********/
float Triangulo::calcularArea() const{
    return (base * altura) / 2;
}

void Triangulo::lerAtributosArea(){
    std::cin >> base;
    std::cin >> altura;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////


/******************************* Class Quadrado : public FiguraGeometrica *******************************/

/******** CONSTRUTORES / DESTRUTOR ********/
Quadrado::Quadrado()
        : FiguraGeometrica(Figura::QUADRADO)
{
    lado = 0;
}

Quadrado::Quadrado(float lado)
        : FiguraGeometrica(Figura::QUADRADO)
{
    this->lado = lado;
}

/******** MÉTODOS ********/
float Quadrado::calcularArea() const{
    return lado * lado;
}

void Quadrado::lerAtributosArea(){
    std::cin >> lado;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////

/******************************* Class Retangulo : public FiguraGeometrica *******************************/

/******** CONSTRUTORES / DESTRUTOR ********/
Retangulo::Retangulo()
         : FiguraGeometrica(Figura::RETANGULO)
{
    lado_1 = lado_2 = 0;
}

Retangulo::Retangulo(float lado_1, float lado_2)
         : FiguraGeometrica(Figura::RETANGULO)
{
    this->lado_1 = lado_1;
    this->lado_2 = lado_2;
}

/******** MÉTODOS ********/
float Retangulo::calcularArea() const{
    return lado_1 * lado_2;
}

void Retangulo::lerAtributosArea(){
    std::cin >> lado_1;
    std::cin >> lado_2;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////

/******************************* Class Circulo : public FiguraGeometrica *******************************/

const float Circulo::PI = 3.14;

/******** CONSTRUTORES / DESTRUTOR ********/
Circulo::Circulo()
       : FiguraGeometrica(Figura::CIRCULO)
{
    raio = 0;
}

Circulo::Circulo(float raio)
       : FiguraGeometrica(Figura::CIRCULO)
{
    this->raio = raio;
}

/******** MÉTODOS ********/
float Circulo::calcularArea() const{
    return PI * raio * raio;
}

void Circulo::lerAtributosArea(){
    std::cin >> raio;
}