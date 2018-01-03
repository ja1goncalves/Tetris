#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <dos.h>

extern tabuleiro[21][21], alt, larg, valor, valor2, corPecasEncaixadas, cor, score, contador, qntLinhas, tempoUsuario;

apagarTabuleiro() // apaga o rastros e limpa o tabuleiro quando a peça se movimenta
{
    int x, y;
    if(colisaoPecas() != 1)
    {
        for(x = 0; x < 21; ++x)
        {
            for(y = 0; y < 21; ++y)
            {
                if(tabuleiro[x][y] == 2)
                    tabuleiro[x][y] = 0;
            }
        }
    }
    else // quando a peça chega ao fim do tabuleiro
    {
        score += 10; // somamos na pontuação
        corPecasEncaixadas = cor; // muda a cor
        for(x = 0; x < 21; ++x)
        {
            for(y = 0; y < 21; ++y)
            {
                if(tabuleiro[x][y] == 2) // quando a peça chega no na ultima linha ou entra outra peça, se torna = 1;
                    tabuleiro[x][y] = 1;
            }
        }
        verificarLinhas(); // pra isso se verificamos as linhas laterais e posteriores
        alt = 0;
        larg = 8;
        valor = valor2;
        valor2 = 1 + rand()%7;
        limparPeca();
        escolherPeca();
    }
}

verificarLinhas() // verificação de linhas
{
    int y;
    int posicaoX;
    for(posicaoX = 0; posicaoX < 20; ++posicaoX) // revisamos a matriz do tabuleiro
    {
        int qntd_blocos = 0;
        for(y = 1; y < 20; ++y)
        {
            if(tabuleiro[posicaoX][y] == 1) // verificamos se alguma linha do tabuleiro é igual a 1
                ++qntd_blocos;
            if(qntd_blocos == 19)
            {
                Beep(600, 300);
                ++contador;
                eliminarLinha(posicaoX);
            }
        }
    }
}


eliminarLinha(int posicaoX)
{
    int x, y;
    qntLinhas++;
    if(qntLinhas == 2 && tempoUsuario >= 25){
        tempoUsuario -= 25;
        qntLinhas = 0;
    }
    score += 100; // adicionamos 100 pontos a cada linha eliminada
    for(x = posicaoX; x > 1; --x) // verificamos a matriz de baixo pra cima
    {
        for(y = 1; y < 20; ++y) // se completar o valor de 1 da função verificarLinha
        {
            tabuleiro[x][y] = tabuleiro[x-1][y]; // transformamos a posterior nas inferiores

        }
    }
}

