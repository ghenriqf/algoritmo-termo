#include <iostream>
#include <ctime>
#include <string.h>
#include <windows.h>
#include <fstream>
#include <sstream>

using namespace std;

string dataAtual();

int main(){

    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "pt_BR.UTF-8");

    ifstream arquivo("palavras.csv");

    string linha;

    string data = dataAtual();

    while(getline(arquivo, linha)){
        stringstream ss(linha);

        string valor;

        while(getline(ss, valor, ',')){
            if(valor == data){
                while(getline(ss,valor)){
                    cout << valor;
                }

            }
        }
    }
}



string dataAtual(){

    time_t agora = time(0);

    tm* tempo = localtime(&agora);

    char dataFormatada[11];

    strftime(dataFormatada, sizeof(dataFormatada), "%d/%m/%Y", tempo);

    return dataFormatada;
}