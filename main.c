#include <windows.h>
#include "Menu.h"
#include "Jogar.h"
#include "Inicio e Termino.h"
#include "Funcoes Tabuleiro.h"
#include "Funcoes Peca.h"



int salvarAltura, colision, avantColision, cor, corPecasEncaixadas, valor, valor2, posicaoDificuldade;
int contador = 0;
int tempo = 300;
int alt = -1;
int larg = 8;
int peca[6][6] = {0};
int tabuleiro[21][21] = {0};
int escudo[6][6] = {0};
int posicaoMenu = 1;
int tempoUsuario = 300;
int score = 0;
int comparador = 0;
int pontos[100] = {0};
int qntLinhas = 0;
char sair;

int main(){
    system("mode 1080"); // inicia o jogo em 1080p
    inicio();
    return 0;
}
