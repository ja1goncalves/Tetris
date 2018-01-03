#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <dos.h>

char tetris[6] = {'T','E','T','R','I','S'};
extern larg, alt, peca[6][6], cor, corPecasEncaixadas, tabuleiro[21][21], score, contador, valor, colision, avantColision, valor2;

escolherPeca() //Essa funcao escolhe onde a peca esta dentro da sua matriz e suas cores
{
    switch(valor)
    {
    case 1:
        peca[2][2] = 2;
        peca[3][1] = 2;
        peca[3][2] = 2;
        peca[3][3] = 2;
        cor = 14;
        break;
    case 2:
        peca[2][1] = 2;
        peca[2][2] = 2;
        peca[3][2] = 2;
        peca[3][3] = 2;
        cor = 13;
        break;
    case 3:
        peca[2][1] = 2;
        peca[3][1] = 2;
        peca[3][2] = 2;
        peca[3][3] = 2;
        cor = 12;
        break;
    case 4:
        peca[2][2] = 2;
        peca[2][3] = 2;
        peca[3][1] = 2;
        peca[3][2] = 2;
        cor =11;
        break;
    case 5:
        peca[4][1] = 2;
        peca[4][2] = 2;
        peca[4][3] = 2;
        peca[4][4] = 2;
        cor = 10;
        break;
    case 6:
        peca[2][3] = 2;
        peca[3][1] = 2;
        peca[3][2] = 2;
        peca[3][3] = 2;
        cor = 15;
        break;
    case 7:
        peca[2][1] = 2;
        peca[2][2] = 2;
        peca[3][1] = 2;
        peca[3][2] = 2;
        cor = 8;
    }
}



apagarRastro(char mov) // apaga rastros laterais
{
    int a;
    if(mov == 'a')
    {
        for(a = 0; a < 6; ++a) // verifica a matriz da peça
        {
            if(tabuleiro[alt+a][larg + 3] != 1) // determina as laterais dela
                tabuleiro[alt + a][larg + 3] = 0; // torna o tabuleiro tudo o que não da peça o proprio tabuleiro == 0;
        }
    }
    if(mov == 'd')
    {
        for(a = 0; a < 6; ++a)
        {
            if(tabuleiro[alt + a][larg] != 1)
                tabuleiro[alt + a][larg] = 0;
        }
    }
}



desenharPeca() // desenha a peça na matriz do tabuleiro, tornando ela parte do tabuleiro
{
    int x, y, i, j;
    system("cls");
    for(x = 3; x < 21; ++x) // verifica o tabuleiro
    {
        for(y = 0; y < 21; ++y)
        {
            if((x >= alt && x < alt + 6) && (y >= larg && y < larg + 6)) // delimita a parte da matriz da peça
            {
                if(peca[x - alt][y - larg] == 2) // delimita as partes da matriz da peça que são iguais a 2
                {
                    tabuleiro[x][y] = 2;
                }
            }
        }
    }
    for(i = 0; i < 21; i++) // criação de novo tabuleiro pra os detalhes do jogo
    {
        switch(i)
        {

        case 5: // na linha 5 da matriz é escrito a pontuação
            color(12);
            printf(" | ");
            color(10);
            printf("Score : %d\t", score);
            color(12);
            printf("|\t");
            break;
        case 6: // na linha 6 da matriz é escrito a linhas para a pontuação (100)
            color(12);
            printf(" | ");
            color(13);
            printf("Linhas : %d\t", contador);
            color(12);
            printf("|\t");
            break;
        default:
            printf("\t\t\t");
            break;
        }
        for(j = 0; j < 21; j++) // mostra a peça posterior
        {
            if(j == 0 || j == 20)
            {
                color(3);
                putchar(186);
                tabuleiro[i][j] = 4;
            }
            else if(i == 1 && j > 6 && j < 14)
            {
                color(20 + rand()%7);
                putchar(tetris[j - 8]);
            }
            else if(i == 20)
            {
                tabuleiro[i][j] = 1;
                color(2);
                putchar(219);
            }
            else if(i == 3)
            {
                color(12);
                putchar(178);
            }
            else if(tabuleiro[i][j] == 0)
            {
                color(30);
                putchar(' ');
            }
            else if(tabuleiro[i][j]== 2)
            {
                color(cor);
                putchar(219);
            }
            else
            {
                color(corPecasEncaixadas);
                putchar(219);
            }
        }
        printf("\n");
    }
            printf("\n\tProxima Peca:\n\n");
            esbocoPeca();
}


limparPeca() // limpa os rastros laterais da peça
{
    int ct1, ct2;
    for(ct1 = 0; ct1 < 6; ++ct1)
    {
        for(ct2 = 0; ct2 < 6; ++ct2)
        {
            peca[ct1][ct2] = 0;
        }
    }
}


rotacionarD() // rotaciona a peça
{
    int container[6][6] = {0};
    int a, b;
    for(a=0; a<6; ++a)
    {
        for(b=0; b<6; ++b) // contruimos uma matriz nova para inverter a da peça
        {
            container[a][b] = peca[a][b]; // igualamos as matrizes para uso da peça
        }
    }
    limparPeca(); // limpamos os rastros deixados no movimento
    int x1, y1;
    for(x1=0; x1<6; ++x1)
    {
        for(y1=0; y1<6; ++y1)
        {
            peca[x1][y1] = container[5-y1][x1]; // invertemos apenas a coluna para que ela seja printada para o lado direito

        }
    }
}



int colisaoPecas() // função para o encaixe das peças
{
    int x, y;
    colision = 0;
    avantColision = 0;
    for(x = 0; x < 21; ++x) // lemos o tabuleiro
    {
        for(y = 0; y < 21; ++y)
        {
            if(tabuleiro[x][y] == 2) // consideramos as parte do tabuleiro/peça que são iguais a 2
            {
                if(tabuleiro[x+1][y]== 1) // derificamos se a linha a baixo já tem peça (parte do tabuleiro = 1)
                {
                    Beep(516, 300); // som
                    avantColision = 1;
                    return 1;
                }
                if(tabuleiro[x][y+1]==4 || tabuleiro[x][y+1]==1) // verificação da lateral direita da peça
                {
                    colision = 1;
                }
                if(tabuleiro[x][y-1]==4 || tabuleiro[x][y-1]==1) // verificação da lateral esquerda da peça
                {
                    colision = 2;
                }
            }

        }
    }
}



esbocoPeca() // desenha as peças posteriores do jogo
{
    switch(valor2)
    {
    case 1:
        printf("\t %c\n",219);
        printf("\t%c%c%c\n",219,219,219);
        break;
    case 2:
        printf("\t%c%c\n",219,219);
        printf("\t %c%c\n",219,219);
        break;
    case 3:
        printf("\t%c\n",219);
        printf("\t%c%c%c\n",219,219,219);
        break;
    case 4:
        printf("\t %c%c\n",219,219);
        printf("\t%c%c\n",219,219);
        break;
    case 5:
        printf("\t%c%c%c%c\n",219,219,219,219);
        break;
    case 6:
        printf("\t  %c\n",219);
        printf("\t%c%c%c\n",219,219,219);
        break;
    case 7:
        printf("\t%c%c\n",219,219);
        printf("\t%c%c\n",219,219);
    }
}


int checarCD(){
    int x, y;
    for(x = 0; x < 6; x++){
        for(y = 0; y < 6; y++){
            if((peca[x][y] == 2 && tabuleiro[x+alt][y+larg+1] == 4) || (peca[x][y] == 2 && tabuleiro[x+alt][y+larg+1] == 1)){
                return 1;
            }
        }
    }
}

int checarCE(){
    int x, y;
    for(x = 0; x < 6; x++){
        for(y = 0; y < 6; y++){
            if((peca[x][y] == 2 && tabuleiro[alt+x][larg+y-1] == 4) || (peca[x][y] == 2 && tabuleiro[x+alt][y+larg-1] == 1))
                {
                return 1;
            }
        }
    }
}


