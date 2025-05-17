#include <iostream>
#include <locale>

using namespace std;

void inicializarTabuleiro(char tabuleiro[3][3]);
void mostrarTabuleiro(char tabuleiro[3][3]);
bool jogarRodada(int linha, int coluna, char tabuleiro[3][3], char jogador);
bool verificarVitoria(char tabuleiro[3][3], int linha, int coluna);
void trocaJogador(char& jogador);

int main()
{
    setlocale(LC_ALL, "portuguese");

    char jogador, tabuleiro[3][3], opc;
    int linha, coluna, jogadas;
    bool vitoria, jogadaValida;

    vitoria = false;
    jogador = 'x';
    linha = 0;
    coluna = 0;
    jogadas = 9;
    jogadaValida = false;

    cout << "Bem vindo ao jogo da velha!" << endl;

    inicializarTabuleiro(tabuleiro);

    mostrarTabuleiro(tabuleiro);

do{
    if(jogador == 'x'){
        cout << "Jogador 1 (X) faça sua jogada" << endl;
    } else {
        cout << "Jogador 2 (O) faça sua jogada" << endl;
    }
    cout << "Primeiro digite a linha e depois digite a coluna da jogada: ";
    cin >> linha >> coluna;

    jogadaValida = jogarRodada(linha, coluna, tabuleiro, jogador);

    mostrarTabuleiro(tabuleiro);

    if(jogadaValida){
        if(verificarVitoria(tabuleiro, linha, coluna)){
            cout << "Jogador" << (jogador == 'x' ? " 1 (X)" : " 2 (O)") << " Parabéns, você venceu" << endl;
            vitoria = true;
        } else {
            jogadas--;
            trocaJogador(jogador);
        }
    }

}while(!vitoria && jogadas > 0);

    if(jogadas == 0){
        cout << "Deu velha";
    }

    return 0;
}

void inicializarTabuleiro(char tabuleiro[3][3]){
    for(int l=0; l < 3; l++){
        for(int c=0; c < 3; c++){
            tabuleiro[l][c] = '-';
        }
    }
}

void mostrarTabuleiro(char tabuleiro[3][3]){
    for(int l=0; l < 3; l++){
        for(int c=0; c < 3; c++){
            cout << tabuleiro[l][c];
        }
    cout << endl;
    }
}

bool jogarRodada(int linha, int coluna, char tabuleiro[3][3], char jogador){
    if(linha >= 0 && linha < 3 && coluna >= 0 && coluna < 3){
        if(tabuleiro[linha][coluna] == '-'){
            tabuleiro[linha][coluna] = jogador;
            return true;
        } else {
            cout << "Casa já ocupada" << endl;
            return false;
        }
    }else {
        cout << "Jogada inválida" << endl;
        return false;
    }
}

bool verificarVitoria(char tabuleiro[3][3], int linha, int coluna){
    if(tabuleiro[linha][0] == tabuleiro[linha][1] && tabuleiro[linha][1] == tabuleiro[linha][2] && tabuleiro[linha][0] != '-'){
        return true;

    }if(tabuleiro[0][coluna] == tabuleiro[1][coluna] && tabuleiro[1][coluna] == tabuleiro[2][coluna] && tabuleiro[0][coluna] != '-'){
        return true;

    }if(tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2] && tabuleiro[0][0] != '-'){
        return true;

    }if(tabuleiro[2][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[0][2] && tabuleiro[2][0] != '-'){
        return true;
    }

    return false;
}

void trocaJogador(char& jogador){
    if(jogador == 'x'){
        jogador = 'o';
    } else {
        jogador = 'x';
    }

}
