#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <dos.h>
#include <time.h>


extern posicaoMenu, valor, score, tabuleiro[21][21], contador, alt, larg, valor2, comparador;

void inicio()
{
    menu();

}

int compararGameOver() // verificação para o fim do jogo
{
    int y;
    for(y = 1; y < 20; ++y)
    {
        if(tabuleiro[4][y] == 1) // quando a quantidad de peças fixas chega na primeira linha
            return 1;

    }
}



void color(int cc) // função de cor
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), cc);
}


void gotoxy(int x,int y) // função para movimentação do READY
{
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);
 }


int comecoJogo()
{
    int contador = 0;
    int x = 26;
    int y = 3;
    while(contador < 20)
    {
 // Introdução para o jogo em movimento pelo gotoxy
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10 + rand()%5);
        gotoxy(x, y);
        printf("    ____  ______          __     \n");
        gotoxy(x, y+1);
        printf("   / __ \\/ ____/___ _____/ /_  __\n");
        gotoxy(x, y+2);
        printf("  / /_/ / __/ / __ `/ __  / / / /\n");
        gotoxy(x, y+3);
        printf(" / _, _/ /___/ /_/ / /_/ / /_/ / \n");
        gotoxy(x, y+4);
        printf("/_/ |_/_____/\\__,_/\\__,_/\\__, /  \n");
        gotoxy(x, y+5);
        printf("                        /____/   \n");
        Sleep(50);
        contador++;
        --x;
    }
    contador = 0;
    while(contador < 10)
    {
        system("cls");
        printf("\n\n\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10 + rand()%5);
        printf("\t   ______   ____     __   __   __   __   __\n");
        printf("\t  / ____/  / __ \\   / /  / /  / /  / /  / /\n");
        printf("\t / / __   / / / /  / /  / /  / /  / /  / / \n");
        printf("\t/ /_/ /  / /_/ /  /_/  /_/  /_/  /_/  /_/  \n");
        printf("\t\\____/   \\____/  (_)  (_)  (_)  (_)  (_)   \n");
        Sleep(300);
        contador++;
    }
    jogar(); // chama a função do jogo
}



printarGameOver()
{
    system("cls");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    printf("\t ______     ______     __    __     ______    \n");
    printf("\t/\\  ___\\   /\\  __ \\   /\\ \"-./  \\   /\\  ___\\   \n");
    printf("\t\\ \\ \\__ \\  \\ \\  __ \\  \\ \\ \\-./\\ \\  \\ \\  __\\   \n");
    printf("\t \\ \\_____\\  \\ \\_\\ \\_\\  \\ \\_\\ \\ \\_\\  \\ \\_____\\ \n");
    printf("\t  \\/_____/   \\/_/\\/_/   \\/_/  \\/_/   \\/_____/ \n");
    printf("\t                                              \n");
    printf("\t ______     __   __   ______     ______       \n");
    printf("\t/\\  __ \\   /\\ \\ / /  /\\  ___\\   /\\  == \\     \n");
    printf("\t\\ \\ \\/\\ \\  \\ \\ \\'/   \\ \\  __\\   \\ \\  __<      \n");
    printf("\t \\ \\_____\\  \\ \\__|    \\ \\_____\\  \\ \\_\\ \\_\\    \n");
    printf("\t  \\/_____/   \\/_/      \\/_____/   \\/_/ /_/    \n");
    score -= 10;
    printf("\t\n\t\t SUA PONTUACAO FOI DE: %d PONTOS", score);
    Sleep(6000);
    inserir(); // função de alocação dos dados do jogador
}



zerarTudo() // função em que torna tudo como no inicio ao fim de cada jogo
{
        larg = 8;
        alt = 0;
        limparPeca();
        srand ( time(NULL) );
        valor = 1 + rand()%7;
        valor2 = 1 + rand()%7;
        escolherPeca(valor);
        comecoJogo();
        jogar(valor);
}



apagarTabuleiroTodo() // funação que zera o tabuleiro ao fim do jogo
{
    int x, y;

    for(x = 0; x < 21; ++x)
    {
        for(y = 0; y < 21; ++y)
        {
            tabuleiro[x][y] = 0;
        }
    }
}
