#include <iostream>
#include <string>

using namespace std;

class FiguraGeometrica
{
    protected:
        string nome;
        int tipo;

    public:
        /******** CONSTRUTORES ********/
        FiguraGeometrica();
        FiguraGeometrica(int);

        /******** MÉTODOS ********/
        string getNome() const;

        void lerAtributosArea();
        float calcularArea() const;
};

class Circulo : public FiguraGeometrica
{
    private:
        float raio;

    public:
        static const float PI;

        /******** CONSTRUTORES ********/
        Circulo();
        Circulo(float);

        /******** MÉTODOS ********/
        void lerAtributosArea();
        float calcularArea() const;
};

class Triangulo : public FiguraGeometrica
{
    private:
        float base, altura;

    public:
        /******** CONSTRUTORES ********/
        Triangulo();
        Triangulo(float, float);

        /******** MÉTODOS ********/
        void lerAtributosArea();
        float calcularArea() const;
};

class Quadrado : public FiguraGeometrica
{
    private:
        float lado;

    public:
        /******** CONSTRUTORES ********/
        Quadrado();
        Quadrado(float);

        /******** MÉTODOS ********/
        void lerAtributosArea();
        float calcularArea() const;
};

class Retangulo : public FiguraGeometrica
{
    private:
        float lado_1, lado_2;

    public:
        /******** CONSTRUTORES ********/
        Retangulo();
        Retangulo(float, float);

        /******** MÉTODOS ********/
        void lerAtributosArea();
        float calcularArea() const;
};



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
inline string FiguraGeometrica::getNome() const{
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

    cin >> r;

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
    
    cin >> b >> h;

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

    cin >> l;

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

    cin >> l1 >> l2;

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



/*********************************************/
/********        FUNÇÃO MAIN         *********/
/*********************************************/
int main(){
    Triangulo triangulo;
    Quadrado quadrado;
    Retangulo retangulo;
    Circulo circulo;
    int figura;


    while(true)
    {
        cin >> figura;
        if (figura == 0){
            break;
        }

        switch (figura){
            case 1:
                quadrado.lerAtributosArea();
                cout << "Quadrado de área " << quadrado.calcularArea() << endl;
                break;
            case 2:
                retangulo.lerAtributosArea();
                cout << "Retângulo de área " << retangulo.calcularArea() << endl;
                break;
            case 3:
                triangulo.lerAtributosArea();
                cout << "Triângulo de área " << triangulo.calcularArea() << endl;
                break;
            case 4:
                circulo.lerAtributosArea();
                cout << "Círculo de área " << circulo.calcularArea() << endl;
                break;
        }
    }


    return 0;
}