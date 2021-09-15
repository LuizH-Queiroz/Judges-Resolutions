#include <iostream>
#include <string>

using namespace std;


namespace gastos
{
    class Despesa
    {
        private:
            std::string nome;
            float valor;
            std::string tipoDeGasto;

        
        public:
            /*/////// CONSTRUTORES ///////*/
            Despesa();


            /*/////// MÉTODOS ///////*/
            std::string getNome();
            float getValor();
            std::string getTipoDeGasto();


            void setNome(std::string);
            void setValor(float);
            void setTipoDeGasto(std::string);
    };


    class ControleDeGastos
    {
        private:
            Despesa *despesa;
            int quantElemVetor;


        public:
            /*/////// CONSTRUTORES ///////*/
            ControleDeGastos();
            ControleDeGastos(int); //O numero (parâmetro) é a quantidade de elementos do vetor
                                   // ATENÇÃO: O CONSTRUTOR DEVE SER CHAMADO APENAS NA INSTANCIAÇÃO


            /*/////// MÉTODOS ///////*/
            Despesa getDespesa(int);


            void setDespesa(Despesa, int);


            void novoVetorDespesa(int); //Cria novo vetor dinâmico e apaga o presente (se necessário)
            float calculaTotalDeDespesas();
            float calculaTotalDeDespesas(std::string);
            bool existeDespesaDoTipo(std::string);
            void limparVetor(); //delete [] despesa
    };

} // namespace gastos


/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////



/*/////////////// CLASSE Despesa ///////////////*/

/*/////// CONSTRUTORES ///////*/
gastos::Despesa::Despesa(){
    nome = "";
    valor = 0;
    tipoDeGasto = "";
}


/*/////// MÉTODOS ///////*/
std::string gastos::Despesa::getNome(){
    return nome;
}

float gastos::Despesa::getValor(){
    return valor;
}

std::string gastos::Despesa::getTipoDeGasto(){
    return tipoDeGasto;
}



void gastos::Despesa::setNome(std::string str){
    nome = str;
}

void gastos::Despesa::setValor(float val){

    if (val < 0){
        return;
    }

    valor = val;
}

void gastos::Despesa::setTipoDeGasto(std::string str){
    tipoDeGasto = str;
}




/*/////////////// CLASSE ControleDeGastos ///////////////*/

/*/////// CONSTRUTORES ///////*/
gastos::ControleDeGastos::ControleDeGastos(){
    despesa = NULL;
    quantElemVetor = 0;
}

gastos::ControleDeGastos::ControleDeGastos(int quant){

    despesa = new Despesa[quant];
    quantElemVetor = quant;
}


/*/////// MÉTODOS ///////*/
gastos::Despesa gastos::ControleDeGastos::getDespesa(int n){
    return despesa[n];
}



void gastos::ControleDeGastos::setDespesa(Despesa desp, int pos){

    if (pos < 0 || pos >= quantElemVetor){
        return;
    }

    despesa[pos] = desp;
}



void gastos::ControleDeGastos::novoVetorDespesa(int n){

    if (despesa != NULL){
        delete [] despesa;
    }

    despesa = new Despesa[n];
    quantElemVetor = n;
}

float gastos::ControleDeGastos::calculaTotalDeDespesas(){
    float soma = 0;

    for (int i = 0; i < quantElemVetor; i++)
    {
        soma += despesa[i].getValor();
    }

    return soma;
}

float gastos::ControleDeGastos::calculaTotalDeDespesas(std::string tipo){
    float soma = 0;

    for (int i = 0; i < quantElemVetor; i++)
    {
        if (despesa[i].getTipoDeGasto() == tipo){
            soma += despesa[i].getValor();
        }
    }

    return soma;
}

bool gastos::ControleDeGastos::existeDespesaDoTipo(std::string tipo){

    for (int i = 0; i < quantElemVetor; i++)
    {
        if (despesa[i].getTipoDeGasto() == tipo){
            return true;
        }
    }

    return false;
}

void gastos::ControleDeGastos::limparVetor(){

    if (despesa != NULL){
        delete [] despesa;
        despesa = NULL;
    }
}


/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////


int main(){

    gastos::ControleDeGastos gasto;
    int quantDespesas;

    string nome, tipoDeGasto;
    float valor;   
    gastos::Despesa despesa;

////////////////////////////////////////////////////

    cin >> quantDespesas;
    cin.ignore();
    gasto.novoVetorDespesa(quantDespesas);
    for (int i = 0; i < quantDespesas; i++)
    {
        getline(cin, nome);
        cin >> valor;
        cin.ignore();
        getline(cin, tipoDeGasto);


        despesa.setNome(nome);
        despesa.setValor(valor);
        despesa.setTipoDeGasto(tipoDeGasto);


        gasto.setDespesa(despesa, i);
    }


    string procurado;
    getline(cin, procurado);
    if (gasto.existeDespesaDoTipo(procurado) == false){
        cout << "Nenhuma despesa do tipo especificado" << endl;
    }
    else {
        for (int i = 0; i < quantDespesas; i++)
        {
            if (gasto.getDespesa(i).getTipoDeGasto() == procurado)
            {
                cout << gasto.getDespesa(i).getNome() << ", "
                     << "R$ " << gasto.getDespesa(i).getValor() << endl;
            }
        }
    }
    
    cout << "Total: "
         << gasto.calculaTotalDeDespesas(procurado) << "/"
         << gasto.calculaTotalDeDespesas() << endl;


    gasto.limparVetor();


    return 0;
}