#ifndef DATA02_H
#define DATA02_H


class Data {
    private:
        int dia, mes, ano;

    
    public:
        /* Construtor */
        Data();


        /* Métodos */
        int getDia();
        int getMes();
        int getAno();

        void setDia(int);
        void setMes(int);
        void setAno(int);

        void printData();
};


#endif