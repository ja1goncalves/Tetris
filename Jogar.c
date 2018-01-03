#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <dos.h>
#include "mmsystem.h"

extern larg, alt,tempo, salvarAltura, contador, colision, avantColision, posicaoDificuldade, tempoUsuario, score, comparador, valor, valor2, sair,  tabuleiro[21][21];

int jogar()
{
    int y;

    while(1)
    {
        while(!kbhit()) // função para rodar o jogo mesmo sem entrada de nenhum comando
        {
            Sleep(tempo); // tempo de descida da peça
            apagarTabuleiro();
             for(y = 1; y < 20; ++y) // verificação da matriz para gamer over
            {
                if(tabuleiro[4][y] == 1) // se a ultima linha tiver peça estatica, para o jogo
                {
                    printarGameOver(); // retorna o game over e vai ao menu
                    menu();
                }
            }
            ++alt;
            Beep(440, 125);
            desenharPeca();
            apagarTabuleiro();
            tempo=tempoUsuario;
        }
        char mov = getch();
        switch(mov)
        {
        case 'd': // comando para movimento
            if(checarCD() != 1){
                tempo = 50;
                larg++;
            }
            break;

        case 'a':
            if(checarCE() != 1){
                tempo = 50;
                larg--;
            }
            break;
        case 'w': // comando para rotação
            if(colision == 0)
            {
                rotacionarD();
            }
            break;
        case 's': // descer a peça mais rapido
            tempo = 1;

            break;
        case 'p': // pausa do jogo
            color(10);
            printf("\n\t\t\t\tJogo Pausado!\n\n\t\tAperte qualquer tecla para continuar ou Esc para sair");
            sair = getch();
            if(sair == 27)
            {
                menu();
            }
            else
                break;
        }
    }
}
