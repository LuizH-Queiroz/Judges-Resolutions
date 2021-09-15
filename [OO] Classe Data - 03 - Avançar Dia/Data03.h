#ifndef DATA03_H
#define DATA03_H


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


#endif