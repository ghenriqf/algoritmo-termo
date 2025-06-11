#include <iostream>
#include <ctime>
#include <fstream>
#include <sstream>
#include <chrono>
#include <thread>


using namespace std;
using namespace std::chrono;
using namespace std::this_thread;


string dataAtual();
void mudarCor(char letra, int corANSI);
void apagarLinha();

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
                getline(ss,valor);
                palavraDoDia = valor;
            }
        }
    }
    
    cout << "-=-=-=-=-=-=TERMO=-=-=-=-=-=-" << endl;
    
    string palavraUsuario;
    int tentativas = 0;
    
    while (tentativas < 6) {
        cin >> palavraUsuario;
        apagarLinha();
        
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
                sleep_for(milliseconds(200));
            }else{
                bool achou = false;
                for (int j = 0; j < 5; j++) {
                    if (palavraUsuario[i] == palavraDoDia[j] && !usadasNaPalavra[j]) {
                        mudarCor(palavraUsuario[i], 33);
                        sleep_for(milliseconds(200));
                        usadasNaPalavra[j] = true;
                        achou = true;
                        break;
                    }
                }
                if(!achou){
                    mudarCor(palavraUsuario[i], 0);
                    sleep_for(milliseconds(200));
                    
                }
            }
        }
        tentativas++;
        
        if (palavraUsuario == palavraDoDia) {
            cout << "\nParabens, voce acertou!" << endl;
            return 1;
        }
        
        if (tentativas == 6) {
            cout << "\nAcabaram as tentativas! A palavra era: " << palavraDoDia << endl;
            return 1;
        }
        cout << endl;
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

void apagarLinha(){

    cout << "\033[F"; 
    cout << "\33[2K";
  
}