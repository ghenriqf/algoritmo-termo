#include <iostream>
#include <ctime>
#include "csv.hpp"
#include <string.h>
#include <windows.h>


using namespace std;


string dataAtual();

int main(){

    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "pt_BR.UTF-8");


}

string dataAtual(){

    time_t agora = time(0);

    tm* tempo = localtime(&agora);

    char dataFormatada[11];

    strftime(dataFormatada, sizeof(dataFormatada), "%d/%m/%Y", tempo);

    return dataFormatada;
}