#include <iostream>
#include <ctime>
#include <fstream>
#include <sstream>
#include <thread>
#include <chrono>

using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

string dataAtual();

void mudarCor(char letra, int corANSI);

void limparLinhaAnterior();

int main(){

    ifstream arquivo("palavras.csv");

    string linha;
    string data = dataAtual();
    string palavraDia;

    while(getline(arquivo, linha)){
        stringstream ss(linha);
        string valor;

        while(getline(ss, valor, ',')){
            if(valor == data){
                while(getline(ss,valor)){

                    palavraDia = valor;

                }
            }
        }
    }

    cout << "-=-=-=-=-=-=TERMO=-=-=-=-=-=-" << endl;

    string palavraUsuario;
    
    for(int tent = 0; tent <= 5; tent++){

        cout << endl;
        cin >> palavraUsuario;


        if (palavraUsuario.size() != 5){
        
        cout << "O jogo TERMO aceita apenas palavras com 5 letras";
        return 1;
            
        }

        for(int l = 0; l<=4; l++){
            if(palavraUsuario[l] == palavraDia[l]){

                mudarCor(palavraUsuario[l],32);
                sleep_for(milliseconds(100)); 
                
            }else{
                cout << palavraUsuario[l] << flush;
                sleep_for(milliseconds(100)); 
            }
        }

    }

    return 0;
    
}


string dataAtual(){

    time_t agora = time(0);
    tm* tempo = localtime(&agora);

    char dataFormatada[11];

    strftime(dataFormatada, sizeof(dataFormatada), "%d/%m/%Y", tempo);

    return dataFormatada;
}

void mudarCor(char letra, int corANSI){

    cout << "\033[" << corANSI << "m" << letra << "\033[0m" << flush;

}

void limparLinhaAnterior(){

    cout << "\033[F" << "\033[2K" << endl;
}