#include <iostream>
#include <locale>


using namespace std;

int main()
{
    setlocale(LC_ALL, "portuguese");
    char tabuleiro[3][3], vitoria, jogador;
    int jogadas, linha, coluna;

    jogador = 'x';
    vitoria=false;
    jogadas = 9;

    cout << "*TABULEIRO*" << endl;
    for(int l=0; l < 3; l++){
        for(int c=0; c < 3; c++){
            tabuleiro[l][c] = '-';
        }
    }

    for(int l=0; l < 3; l++){
        for(int c=0; c < 3; c++){
            cout << tabuleiro[l][c] << " ";
        }
        cout << endl;
    }

do{
    if(jogador == 'x'){
        cout << "Jogador 1 (X) faça sua jogada: " << endl;
    } else {
        cout << "Jogador 2 (O) faça sua jogada: " << endl;
    }
    cout << "Primeiro digite a linha e depois a coluna" << endl;
    cin >> linha >> coluna;

    if((linha >= 0 && linha < 3) && (coluna >=0 && coluna < 3)){
        if(tabuleiro[linha][coluna] == '-'){
            tabuleiro[linha][coluna] = jogador;
            jogadas--;
        } else {
            cout << "Posição já ocupada, tente novamente" << endl;
            continue;
            jogadas++;
        }
    } else {
        cout << "Posição inválida, tente novamente" << endl;
        continue;
        jogadas++;
    }


    if(jogador == 'x'){
        jogador = 'o';
    } else {
        jogador = 'x';
    }


    for(int l=0; l < 3; l++){
        for(int c=0; c < 3; c++){
            cout << tabuleiro[l][c] << " ";
        }
        cout << endl;
    }

    if(tabuleiro[linha][0] == tabuleiro[linha][1] && tabuleiro[linha][1] == tabuleiro[linha][2] && tabuleiro [linha][0] != '-'){
        cout << "jogador " << (jogador == 'x' ? "2 (O)" : "1 (X)") << " Você venceu!!";
        vitoria = true;
    } else if(tabuleiro[0][coluna] == tabuleiro[1][coluna] && tabuleiro[1][coluna] == tabuleiro[2][coluna] && tabuleiro[0][coluna] != '-'){
        cout << "jogador " << (jogador == 'x' ? "2 (O)" : "1 (X)") << " Você venceu!!";
        vitoria = true;
    } else if(tabuleiro[0][0] == tabuleiro [1][1] && tabuleiro [1][1] == tabuleiro[2][2] && tabuleiro[0][0] != '-'){
        cout << "jogador " << (jogador == 'x' ? "2 (O)" : "1 (X)") << " Você venceu!!";
        vitoria = true;
    } else if(tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0] && tabuleiro[0][2] != '-'){
        cout << "jogador " << (jogador == 'x' ? "2 (O)" : "1 (X)") << " Você venceu!!";
        vitoria = true;
    }

}while((!vitoria) && (jogadas > 0));

if(!vitoria && jogadas == 0){
    cout << "Deu velha!!!";
}



    return 0;
}
