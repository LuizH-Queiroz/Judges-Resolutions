#ifndef DATA03_H
#define DATA03_H

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