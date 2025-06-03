#include <iostream>
#include <ctime>

using namespace std;


string dataAtual();

int main(){

    cout << dataAtual();

    return 0;


}

string dataAtual(){

    time_t agora = time(0);

    tm* tempo = localtime(&agora);

    char dataFormatada[11];

    strftime(dataFormatada, sizeof(dataFormatada), "%d/%m/%Y", tempo);

    return dataFormatada;
}

