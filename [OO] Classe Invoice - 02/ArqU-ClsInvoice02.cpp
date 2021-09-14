#include <iostream>
#include <string>

#define QUANT_INVOICE 2

using namespace std;


class Invoice {
    private:
        int numero;
        std::string descricao;
        int quantComprada;
        float preco;


    public:
        /*/////// CONSTRUTOR ///////*/
        Invoice();
        Invoice(int, std::string, int, float);


        /*/////// MÉTODOS ///////*/
        int getNumero();
        std::string getDescricao();
        int getQuantComprada();
        float getPreco();


        void setNumero(int);
        void setDescricao(std::string);
        void setQuantComprada(int);
        void setPreco(float);


        float getInvoiceAmount();
        void print();
};


/*/////// DEFINIÇÕES/IMPLEMENTAÇÕES DOS CONSTRUTORES ///////*/
Invoice::Invoice(){
    numero = 0;
    descricao = "";
    quantComprada = 0;
    preco = 0;
}

Invoice::Invoice(int num, std::string desc, int comprado, float custo){
    numero = num;
    descricao = desc;
    
    if (comprado < 0){
        quantComprada = 0;
    }
    else {
        quantComprada = comprado;
    }

    if (custo < 0){
        preco = 0;
    }
    else {
        preco = custo;
    }
}


/*/////// DEFINIÇÕES/IMPLEMENTAÇÕES DOS MÉTODOS ///////*/
int Invoice::getNumero(){
    return numero;
}

std::string Invoice::getDescricao(){
    return descricao;
}

int Invoice::getQuantComprada(){
    return quantComprada;
}

float Invoice::getPreco(){
    return preco;
}



void Invoice::setNumero(int n){
    numero = n;
}

void Invoice::setDescricao(std::string desc){
    descricao = desc;
}

void Invoice::setQuantComprada(int quant){

    if (quant < 0){
        quantComprada = 0;
    }
    else {
        quantComprada = quant;
    }
}

void Invoice::setPreco(float custo){

    if (custo < 0){
        preco = 0;
    }
    else {
        preco = custo;
    }
}



float Invoice::getInvoiceAmount(){
    return quantComprada * preco;
}

void Invoice::print(){

    std::cout << numero << " - "
              << descricao << " - "
              << quantComprada << " - "
              << preco << " - "
              << getInvoiceAmount() << std::endl;
}


/*/////////////////////////////////////////////////////*/
/*//////////////////// FUNÇÃO MAIN ////////////////////*/
/*/////////////////////////////////////////////////////*/
int main(){
    Invoice *invoice = new Invoice[QUANT_INVOICE];
    int numero, quantComprada;
    string descricao;
    float preco;


    for (int i = 0; i < QUANT_INVOICE; i++)
    {
        cin >> numero;
        getchar();
        getline(cin, descricao);
        cin >> quantComprada >> preco;


        invoice[i] = Invoice(numero, descricao, quantComprada, preco);


        invoice[i].print();
    }


    delete [] invoice;


    return 0;
}