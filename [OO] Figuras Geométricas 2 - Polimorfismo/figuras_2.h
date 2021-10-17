#ifndef FIGURAS_2
#define FIGURAS_2

#include <string>


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
        std::string nome;
        int tipo;

    public:
        /******** CONSTRUTORES / DESTRUTOR ********/
        FiguraGeometrica();
        FiguraGeometrica(Figura tipo);
        virtual ~FiguraGeometrica() { /* VAZIO */ }

        /******** MÉTODOS ********/
        virtual float calcularArea() const = 0;
        virtual void lerAtributosArea() = 0;

        std::string getNome() const { return nome; }
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


#endif