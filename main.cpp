#include <iostream>
#include <ctime>
#include <string.h>
#include <windows.h>
#include <fstream>
#include <sstream>

using namespace std;

string dataAtual();

void mudarCor(const string& letra, int corANSI);

int main(){

    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "pt_BR.UTF-8");

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

        cin >> palavraUsuario;

        if (palavraUsuario.size() != 5){
        
        cout << "O jogo TERMO aceita apenas palavras com 5 letras";
        return 1;
            
        }

        for(int l = 0; l<=4; l++){
            if(palavraUsuario[l] == palavraDia[l]){
                
            }else{
                cout << palavraUsuario[l];
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

void mudarCor(const string& letra, int corANSI){

    cout << "\033[" << corANSI << "m" << letra << "\033[0m";

}