#include <iostream>
#include <vector>
#include <string>

#define MESAS_REST 5

using namespace std;


class Pedido
{
    private:
        int numero;
        string descricao;
        float preco;
        int quantComprada;


    public:
        /******** CONSTRUTORES ********/
        Pedido();
        Pedido(int, string, float, int);


        /******** MÉTODOS ********/
        int getNumero();
        string getDescricao();
        float getPreco();
        int getQuantComprada();


        void setNumero(int);
        void setDescricao(string);
        void setPreco(float);
        void setQuantComprada(int);


        void aumentaQuantComprada(int);
        float getTotal();
};


class MesaDeRestaurante
{
    private:
        vector<Pedido> pedido;


    public:
        /******** MÉTODOS ********/
        void adicionarPedido(Pedido);
        void zeraPedidos();
        float calculaTotal();
        void exibeConta();
};


class Restaurante
{
    private:
        MesaDeRestaurante *mesa;
        int quantMesas;


    public:
        /******** CONSTRUTORES ********/
        Restaurante();
        Restaurante(int);


        /******** MÉTODOS ********/
        MesaDeRestaurante getMesa(int);
        int getQuantMesas();


        void adicionarPedido(Pedido, int);
        float calculaTotalRestaurante();
        void NovoArray(int);


        void limparArray();
};



/********************* Class Pedido *********************/

/******** CONSTRUTORES ********/
Pedido::Pedido(){
    numero = 0;
    descricao = "";
    preco = 0;
    quantComprada = 0;
}

Pedido::Pedido(int num, string desc, float custo, int quant){
    
    if (num > 0){
        numero = num;
    }
    else {
        numero = 0;
    }

    descricao = desc;

    if (custo >= 0){
        preco = custo;
    }
    else {
        preco = 0;
    }

    if (quant >= 0){
        quantComprada = quant;
    }
    else {
        quantComprada = 0;
    }
}


/******** MÉTODOS ********/
int Pedido::getNumero(){
    return numero;
}

string Pedido::getDescricao(){
    return descricao;
}

float Pedido::getPreco(){
    return preco;
}

int Pedido::getQuantComprada(){
    return quantComprada;
}


void Pedido::setNumero(int num){

    if (num > 0){
        numero = num;
    }
}

void Pedido::setDescricao(string desc){
    descricao = desc;
}

void Pedido::setPreco(float custo){

    if (custo >= 0){
        preco = custo;
    }
}

void Pedido::setQuantComprada(int quant){

    if (quant >= 0){
        quantComprada = quant;
    }
}


void Pedido::aumentaQuantComprada(int quant){
    quantComprada += quant;
}

float Pedido::getTotal(){
    return preco * quantComprada;
}



/********************* Class MesaDeRestaurante *********************/

/******** MÉTODOS ********/
void MesaDeRestaurante::adicionarPedido(Pedido p){
    
    for(int i = 0; i < pedido.size(); i++)
    {
        if (pedido[i].getDescricao().find(p.getDescricao()) != string::npos){
            pedido[i].aumentaQuantComprada(p.getQuantComprada());
            return;
        }
    }

    pedido.push_back(p);
}

void MesaDeRestaurante::zeraPedidos(){

    for (int i = 0; i < pedido.size(); i++)
    {
        pedido[i].setQuantComprada(0);
    }
}

float MesaDeRestaurante::calculaTotal(){
    float total = 0;

    for (int i = 0; i < pedido.size(); i++)
    {
        total += pedido[i].getPreco() * pedido[i].getQuantComprada();
    }

    return total;
}

void MesaDeRestaurante::exibeConta(){

    for(int i = 0; i < pedido.size(); i++)
    {
        cout << pedido[i].getNumero() << " - " << pedido[i].getDescricao() << " - "
                  << pedido[i].getQuantComprada() << " - " << pedido[i].getPreco() << " - "
                  << "R$ " << pedido[i].getTotal() << endl;
    }

    cout << "Total: R$ " << calculaTotal() << endl;
}



/********************* Class Restaurante *********************/

/******** CONSTRUTORES ********/
Restaurante::Restaurante(){
    mesa = NULL;
    quantMesas = 0;
}

Restaurante::Restaurante(int quant){

    if (quant > 0){
        mesa = new MesaDeRestaurante[quant];
        quantMesas = quant;
    }
}


/******** MÉTODOS ********/
void Restaurante::adicionarPedido(Pedido p, int mesa){

    if (mesa < quantMesas){
        this->mesa[mesa-1].adicionarPedido(p);
    }
}

float Restaurante::calculaTotalRestaurante(){
    float total = 0;

    for (int i = 0; i < quantMesas; i++)
    {
        total += mesa[i].calculaTotal();
    }

    return total;
}

MesaDeRestaurante Restaurante::getMesa(int i){
    
    if (i <= quantMesas){
        return mesa[i];
    }
}

void Restaurante::NovoArray(int quant){

    if (quant > 0){

        if (mesa != NULL){
            delete [] mesa;
        }

        mesa = new MesaDeRestaurante[quant];
        quantMesas = quant;
    }
}


void Restaurante::limparArray(){

    if (mesa != NULL){
        delete [] mesa;
        quantMesas = 0;
    }
}


/******************************************/
/************* FUNÇÃO MAIN ****************/
/******************************************/
int main(){
    Restaurante mesas(MESAS_REST);

    //Para passar os dados:
    int numero, quantComprada, numMesa;
    float preco;
    string descricao;
    ///////////////////////////////////

    while(true)
    {
        cin >> numero;
        if (numero < 0){
            break;
        }

        cin.ignore();
        getline(cin, descricao);
        cin >> quantComprada >> preco >> numMesa;


        mesas.adicionarPedido(Pedido(numero, descricao, preco, quantComprada), numMesa);
    }

    for (int i = 0; i < MESAS_REST; i++)
    {
        if(mesas.getMesa(i).calculaTotal() > 0){
            cout << "Mesa " << i + 1 << endl;
            mesas.getMesa(i).exibeConta();
            cout << endl;
        }
    }
    cout << "Total Restaurante: R$ " << mesas.calculaTotalRestaurante() << endl;


    mesas.limparArray();


    return 0;
}