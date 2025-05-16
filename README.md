# 🎮 Jogo da Velha em C++

Este é um simples **Jogo da Velha** implementado em C++, com interface de texto no terminal. O jogo é para dois jogadores locais e segue as regras clássicas, com detecção de vitória e empate ("deu velha").

## 🧠 Regras

- Dois jogadores se revezam: jogador 1 é **X** e jogador 2 é **O**.
- O tabuleiro é uma matriz 3x3.
- Vence quem alinhar três símbolos na horizontal, vertical ou diagonal.
- Caso todas as posições sejam preenchidas e ninguém vença, o jogo termina em empate ("deu velha").

## 🕹️ Como Jogar

1. Execute o programa.
2. O jogo exibe o tabuleiro vazio e alterna entre os jogadores.
3. Para jogar, o jogador deve digitar:
   - A linha (0 a 2)
   - A coluna (0 a 2)
4. O programa verifica se a posição é válida e não está ocupada.
5. Após cada jogada, o tabuleiro é atualizado e o jogo verifica se alguém venceu.

### 📌 Exemplo de entrada

Jogador 1 (X) faça sua jogada:
Primeiro digite a linha e depois a coluna
0 1

## 📋 Funcionalidades

- Jogo local para dois jogadores
- Validação de posição (fora dos limites ou já ocupada)
- Mensagens de vitória para o jogador correto
- Empate detectado automaticamente  