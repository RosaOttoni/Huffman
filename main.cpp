#include "Review.h"
#include "FileIO.h"
#include "Ordenacao.h"
#include "TabelaHash.h"
#include "ArvoreVermelhoPreto.h"
#include "Arvores.h"
#include "Huffman.h"
#include "testaHuffman.h"
#include <fstream>
#include <iomanip>
#include <chrono>
#include <cstdlib>

using namespace std;
using namespace std::chrono;

void imprimeMenu(){
    cout<<"____________________MENU__________________________"<<endl;
    cout<<"| Para executar, escolha uma das opcoes abaixo:  |"<<endl;
    cout<<"| 1 - Compressao de N registros                  |"<<endl;
    cout<<"| 2 - Descompressao do arquivo binario           |"<<endl;
    cout<<"| 3 - Gerar metricas                             |"<<endl;
    cout<<"| 4 - SAIR                                       |"<<endl;
    cout<<"|________________________________________________|"<<endl<<endl;
}

int main(int argc, char *argv[])
{
    int opcao, n;

    Huffman *huffman = nullptr;

    Review **reviews;

    srand(time(NULL));

    if(argc != 2){
        cout << "Erro: Diretorio nao especificado" << endl;
        return 0;
    }

    leituraCsv(argv[1]);

    imprimeMenu();

    cin >> opcao;

    while(opcao != 4){
        switch(opcao){
            case 1:{
                cout << "Digite a quantidade de registros que deseja comprimir: ";

                cin >> n;

                reviews = new Review*[n];

                importaConjunto(n, reviews);

                if(huffman != nullptr){
                    delete huffman;
                }

                huffman = new Huffman(reviews, n);

                huffman->compressao(reviews, n);

                for(int i = 0; i < n; i++){
                    delete reviews[i];
                }

                delete []reviews;
            }
            break;
            case 2:{
                if(huffman != nullptr){
                    huffman->descompressao("reviewsComp.bin");
                }
                else{
                    cout << "Erro: realize a compressao antes de descomprimir!" << endl;
                }
            }
            break;
            case 3:{
                testaHuffman();
            }
            default:
                cout << "Opcao invalida!" << endl;
        }
        imprimeMenu();
        cin >> opcao;
    }

    return 0;
}
