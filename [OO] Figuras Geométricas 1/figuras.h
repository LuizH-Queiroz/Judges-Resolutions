#ifndef FIGURAS
#define FIGURAS

#include <string>

class FiguraGeometrica
{
    protected:
        std::string nome;
        int tipo;

    public:
        /******** CONSTRUTORES ********/
        FiguraGeometrica();
        FiguraGeometrica(int);

        /******** MÉTODOS ********/
        std::string getNome() const;

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

#endif