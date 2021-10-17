#include <iostream>
#include <string>

using namespace std;


enum Figura
{
    INDEFINIDO = 0,
    QUADRADO = 1,
    RETANGULO = 2,
    TRIANGULO = 3,
    CIRCULO = 4
};


class FiguraGeometrica
{
    protected:
        string nome;
        int tipo;

    public:
        /******** CONSTRUTORES / DESTRUTOR ********/
        FiguraGeometrica();
        FiguraGeometrica(Figura tipo);
        virtual ~FiguraGeometrica() { /* VAZIO */ }

        /******** MÉTODOS ********/
        virtual float calcularArea() const = 0;
        virtual void lerAtributosArea() = 0;

        string getNome() const { return nome; }
};


class Triangulo : public FiguraGeometrica
{
    private:
        float base;
        float altura;

    public:
        /******** CONSTRUTORES / DESTRUTOR ********/
        Triangulo();
        Triangulo(float base, float altura);
        virtual ~Triangulo() { /* VAZIO */ }

        /******** MÉTODOS ********/
        virtual float calcularArea() const override;
        virtual void lerAtributosArea() override;
};


class Quadrado : public FiguraGeometrica
{
    private:
        float lado;

    public:
        /******** CONSTRUTORES / DESTRUTOR ********/
        Quadrado();
        Quadrado(float lado);
        virtual ~Quadrado() { /* VAZIO */ }

        /******** MÉTODOS ********/
        virtual float calcularArea() const override;
        virtual void lerAtributosArea() override;
};


class Retangulo : public FiguraGeometrica
{
    private:
        float lado_1;
        float lado_2;

    public:
        /******** CONSTRUTORES / DESTRUTOR ********/
        Retangulo();
        Retangulo(float lado_1, float lado_2);
        virtual ~Retangulo() { /* VAZIO */ }

        /******** MÉTODOS ********/
        virtual float calcularArea() const override;
        virtual void lerAtributosArea() override;
};


class Circulo : public FiguraGeometrica
{
    private:
        float raio;

    public:
        static const float PI;

        /******** CONSTRUTORES / DESTRUTOR ********/
        Circulo();
        Circulo(float raio);
        virtual ~Circulo() { /* VAZIO */ }

        /******** MÉTODOS ********/
        virtual float calcularArea() const override;
        virtual void lerAtributosArea() override;
};


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
    cin >> base;
    cin >> altura;
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
    cin >> lado;
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
    cin >> lado_1;
    cin >> lado_2;
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
    cin >> raio;
}


/***************************************************************************/
/***********************        Funcao main        *************************/
/***************************************************************************/
int main(){
    FiguraGeometrica *figura;
    int tipo;


    while (true)
    {
        cin >> tipo;
        if (tipo == Figura::INDEFINIDO){
            break;
        }

        switch (tipo){
            case Figura::TRIANGULO:
                figura = new Triangulo();
                figura->lerAtributosArea();
                break;
            case Figura::QUADRADO:
                figura = new Quadrado();
                figura->lerAtributosArea();
                break;
            case Figura::RETANGULO:
                figura = new Retangulo();
                figura->lerAtributosArea();
                break;
            case Figura::CIRCULO:
                figura = new Circulo();
                figura->lerAtributosArea();
                break;
        }

        cout << figura->getNome() << " polimórfico de área " << figura->calcularArea() << endl;

        delete figura;
        figura = NULL;
    }


    return 0;
}