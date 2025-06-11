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

int main(){

    ifstream arquivo("palavras.csv");

    string linha;
    string data = dataAtual();
    string palavraDoDia;

    while(getline(arquivo, linha)){
        stringstream ss(linha);
        string valor;

        while(getline(ss, valor, ',')){
            if(valor == data){
                while(getline(ss,valor)){

                    palavraDoDia = valor;

                }
            }
        }
    }

    cout << "-=-=-=-=-=-=TERMO=-=-=-=-=-=-" << endl;

    string palavraUsuario;
    int tentativas = 0;

    while (tentativas < 6) {
        cout << "\n";
        cin >> palavraUsuario;

        if (palavraUsuario.size() != 5) {
            cout << "A palavra deve ter 5 letras!" << endl;
            continue;
        }
        
        bool usadasNaPalavra[5] = {false, false, false, false, false};
        bool letrasPalpites[5] = {false, false, false, false, false};

        for(int i = 0; i < 5; i++){
            if (palavraUsuario[i] == palavraDoDia[i]) {
                letrasPalpites[i] = true;
                usadasNaPalavra[i] = true;
            }
        }

        for(int i = 0; i < 5; i++){
            if (letrasPalpites[i]) {
                mudarCor(palavraUsuario[i], 32);
            }else{
                bool achou = false;
                for (int j = 0; j < 5; j++) {
                    if (palavraUsuario[i] == palavraDoDia[j] && !usadasNaPalavra[j]) {
                        mudarCor(palavraUsuario[i], 33);
                        usadasNaPalavra[j] = true;
                        achou = true;
                        break;
                    }
                }
                if(!achou){
                    mudarCor(palavraUsuario[i], 0);
                }
            }
        }

        tentativas++;

        if (palavraUsuario == palavraDoDia) {
            cout << "Parabens, voce acertou!" << endl;
            return 1;
        }

        if (tentativas == 6) {
            cout << "Acabaram as tentativas! A palavra era: " << palavraDoDia << endl;
            return 1;
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