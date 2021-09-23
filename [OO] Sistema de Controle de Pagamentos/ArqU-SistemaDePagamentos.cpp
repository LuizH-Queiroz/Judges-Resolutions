#include <iostream>
#include <string>

using namespace std;

class Pagamento
{
    private:
        string nomeDoFuncionario;
        float valorPagamento;

    
    public:
        /*/////// CONSTRUTORES ///////*/
        Pagamento();
        Pagamento(string, float);


        /*/////// MÉTODOS ///////*/
        string getNomeDoFuncionario();
        float getValorPagamento();


        void setNomeDoFuncionario(string);
        void setValorPagamento(float);
};


class ControleDePagamentos
{
    private:
        Pagamento *pagamento;
        int quantElemVetor;


    public:
        /*/////// CONSTRUTORES ///////*/
        ControleDePagamentos();
        ControleDePagamentos(int);


        /*/////// MÉTODOS ///////*/
        Pagamento getPagamento(int);
        int getIndexFuncionario(string);


        void setPagamento(Pagamento, int);


        float calculaTotalDePagamentos();
        void novoArray(int);
        void limparArray();
};


/*//////////////////// Class Pagamento ////////////////////*/

/*////////// CONSTRUTORES //////////*/
Pagamento::Pagamento(){
    nomeDoFuncionario = "";
    valorPagamento = 0;
}

Pagamento::Pagamento(string nome, float valor){
    nomeDoFuncionario = nome;
    valorPagamento = valor;
}


/*////////// MÉTODOS //////////*/
string Pagamento::getNomeDoFuncionario(){
    return nomeDoFuncionario;
}

float Pagamento::getValorPagamento(){
    return valorPagamento;
}


void Pagamento::setNomeDoFuncionario(string nome){
    nomeDoFuncionario = nome;
}

void Pagamento::setValorPagamento(float valor){

    if (valor >= 0){
        valorPagamento = valor;
    }
}



/*//////////////////// Class ControleDePagamentos ////////////////////*/

/*////////// CONSTRUTORES //////////*/
ControleDePagamentos::ControleDePagamentos(){
    pagamento = NULL;
    quantElemVetor = 0;
}

ControleDePagamentos::ControleDePagamentos(int quantElemVetor){

    pagamento = new Pagamento[quantElemVetor];
    this->quantElemVetor = quantElemVetor;
}


/*////////// MÉTODOS //////////*/
Pagamento ControleDePagamentos::getPagamento(int indice){
    
    if (indice >= 0 && indice < quantElemVetor){
        return pagamento[indice];
    }
}

int ControleDePagamentos::getIndexFuncionario(string nome){

    for (int i = 0; i < quantElemVetor; i++)
    {
        if (pagamento[i].getNomeDoFuncionario().find(nome) != string::npos){
            return i;
        }
    }

    return -1;
}


void ControleDePagamentos::setPagamento(Pagamento pag, int indice){

    if (indice >= 0 && indice < quantElemVetor){
        pagamento[indice] = pag;
    }
}


float ControleDePagamentos::calculaTotalDePagamentos(){
    float total = 0;

    for (int i = 0; i < quantElemVetor; i++)
    {
        total += pagamento[i].getValorPagamento();
    }

    return total;
}

void ControleDePagamentos::novoArray(int quant){

    if (pagamento != NULL){
        delete [] pagamento;
    }

    pagamento = new Pagamento[quant];
    quantElemVetor = quant;
}

void ControleDePagamentos::limparArray(){

    if (pagamento != NULL){
        delete [] pagamento;
        pagamento = NULL;
    }
}


/**************************************************/
/****************** FUNÇÂO MAIN *******************/
/**************************************************/
int main(){
    ControleDePagamentos pagamento;
    int quantPag;

    cin >> quantPag;
    pagamento.novoArray(quantPag);

    float valor;
    string nome;
    for (int i = 0; i < quantPag; i++)
    {
        cin >> valor;
        cin.ignore();
        getline(cin, nome);

        pagamento.setPagamento(Pagamento(nome, valor), i);
    }

    int indice;
    getline(cin, nome);
    indice = pagamento.getIndexFuncionario(nome);
    if (indice != -1){
        cout << pagamento.getPagamento(indice).getNomeDoFuncionario()
             << ": R$ " << pagamento.getPagamento(indice).getValorPagamento() << endl;
    }
    else {
        cout << nome << " não encontrado(a)." << endl;
    }
    cout << "Total: R$ " << pagamento.calculaTotalDePagamentos() << endl;


    pagamento.limparArray();


    return 0;
}