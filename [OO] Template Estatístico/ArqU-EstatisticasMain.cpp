#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;


template <class Type>
class Estatisticas {
    public:
        static int indexOfMaior(vector<Type> vec);
        static int indexOfMenor(vector<Type> vec);
        static float media(vector<Type> vec);
};


class Pedido {
    private:
        float valorUnitario;
        int quantidade;

    public:
        /******** CONSTRUTORES / DESTRUTOR ********/
        Pedido();
        Pedido(float valor, int quant);
        virtual ~Pedido();

        /******** MÉTODOS ********/
        float getTotal();
        string toString();
};


class Livro {
    private:
        string titulo;
        int totalPaginas;

    public:
        /******** CONSTRUTORES / DESTRUTOR ********/
        Livro();
        Livro(string titulo, int paginas);
        virtual ~Livro();

        /******** MÉTODOS ********/
        int getTotal();
        string toString();
};


/*************************** template <class Type> class Estatisticas ***************************/

template <class Type>
int Estatisticas<Type>::indexOfMaior(vector<Type> vec){
    int maior = (vec.size() == 0 ? -1 : 0);

    for (int i = 1; i < vec.size(); i++)
    {
        if (vec[i].getTotal() > vec[maior].getTotal()){
            maior = i;
        }
    }

    return maior;
}

template <class Type>
int Estatisticas<Type>::indexOfMenor(vector<Type> vec){
    int menor = (vec.size() == 0 ? -1 : 0);

    for (int i = 1; i < vec.size(); i++)
    {
        if (vec[i].getTotal() < vec[menor].getTotal()){
            menor = i;
        }
    }

    return menor;
}

template <class Type>
float Estatisticas<Type>::media(vector<Type> vec){
    float media = 0;

    for (int i = 0; i < vec.size(); i++)
    {
        media += vec[i].getTotal();
    }
    if (vec.size() != 0) media /= vec.size();

    return media;
}

//////////////////////////////////////////////////////////////////////


/*************************** class Pedido ***************************/

/******** CONSTRUTORES / DESTRUTOR ********/
Pedido::Pedido(){
    valorUnitario = 0;
    quantidade = 0;
}

Pedido::Pedido(float valor, int quant){
    valorUnitario = valor;
    quantidade = quant;
}

Pedido::~Pedido() { }

/******** MÉTODOS ********/
float Pedido::getTotal(){
    return valorUnitario * quantidade;
}

string Pedido::toString(){
    stringstream sout;

    sout << "R$ " << valorUnitario << ", quant: " << quantidade
            << ", total: R$ " << getTotal();

    return sout.str();
}

//////////////////////////////////////////////////////////////////////


/*************************** class Livro ***************************/

/******** CONSTRUTORES / DESTRUTOR ********/
Livro::Livro(){
    titulo = "";
    totalPaginas = 0;
}

Livro::Livro(string titulo, int paginas){
    this->titulo = titulo;
    this->totalPaginas = paginas;
}

Livro::~Livro() { }

/******** MÉTODOS ********/
int Livro::getTotal(){
    return totalPaginas;
}

string Livro::toString(){
    stringstream sout;

    sout << titulo << ", páginas: " << totalPaginas;

    return sout.str();
}


/***************************************************************/
/************************* FUNÇÃO MAIN *************************/
/***************************************************************/
int main(){
    int n_pedidos, n_livros;

    //Variáveis para Pedido
    float valorUnitario;
    int quantidade;

    //Variáveis para Livro
    string titulo;
    int totalPaginas;


    //Leitura dos pedidos
    cin >> n_pedidos;
    vector<Pedido> pedido(n_pedidos);
    
    for (int i = 0; i < n_pedidos; i++)
    {
        cin >> valorUnitario >> quantidade;
        cin.ignore();

        pedido[i] = Pedido(valorUnitario, quantidade);
    }

    cout << "Maior: " << pedido[Estatisticas<Pedido>::indexOfMaior(pedido)].toString() << endl;
    cout << "Menor: " << pedido[Estatisticas<Pedido>::indexOfMenor(pedido)].toString() << endl;
    cout << "Média: " << Estatisticas<Pedido>::media(pedido) << endl;


    //Leitura dos livros
    cin >> n_livros;
    cin.ignore();
    vector<Livro> livro(n_livros);

    for (int i = 0; i < n_livros; i++)
    {
        getline(cin, titulo);
        cin >> totalPaginas;
        cin.ignore();

        livro[i] = Livro(titulo, totalPaginas);
    }

    cout << "Maior: " << livro[Estatisticas<Livro>::indexOfMaior(livro)].toString() << endl;
    cout << "Menor: " << livro[Estatisticas<Livro>::indexOfMenor(livro)].toString() << endl;
    cout << "Média: " << Estatisticas<Livro>::media(livro) << endl;



    return 0;
}