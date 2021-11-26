#include <iostream>
#include <string>
#include <vector>
#include "Estatisticas.h"

using namespace std;


int main(){
    int n_pedidos, n_livros;

    //Variáveis para Pedido
    float valorUnitario;
    int quantidade;

    //Variáveis para Livro
    std::string titulo;
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