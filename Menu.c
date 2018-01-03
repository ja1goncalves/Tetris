#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

extern sair, score, valor, valor2, contador, posicaoMenu, pontos[100], tempoUsuario, tempo, posicaoDificuldade;

void setaAqui(int posicaoReal, int posicaoSeta) // função para cor e desenho da seta do menu
{
    if(posicaoReal == posicaoSeta )
    {
        printf("--->");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
    }
}




void dificuldade() // função de dificuldade altera os valores do sleep, fazendo a peca descer mais rapido ou devagar
{
    char usuarioDificuldade = 5;
    posicaoDificuldade = 1;
    while(1)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        system("cls");
        printf("\t\t    ____  ______________________  ____    ____  ___    ____  ______\n");
        printf("\t\t   / __ \\/  _/ ____/  _/ ____/ / / / /   / __ \\/   |  / __ \\/ ____/\n");
        printf("\t\t  / / / // // /_   / // /   / / / / /   / / / / /| | / / / / __/   \n");
        printf("\t\t / /_/ // // __/ _/ // /___/ /_/ / /___/ /_/ / ___ |/ /_/ / /___   \n");
        printf("\t\t/_____/___/_/   /___/\\____/\\____/_____/_____/_/  |_/_____/_____/   \n");
        printf("\n\n\n");
        printf("\t\t\t Selecione a dificuldade do jogo:\n\n\n");
        setaAqui(1, posicaoDificuldade);
        printf("\t\t\t|\tFacil\t\t|\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
        setaAqui(2, posicaoDificuldade);
        printf("\t\t\t|\tMedio\t\t|\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        setaAqui(3, posicaoDificuldade);
        printf("\t\t\t|\tDificil\t\t|\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        if(posicaoDificuldade == 1) // Fácil
        {
            tempoUsuario = 300;
        }
        else if(posicaoDificuldade == 2) // Médio
        {
            tempoUsuario = 200;
        }
        else if(posicaoDificuldade == 3) // Díficil
        {
            tempoUsuario = 50;
        }
        fflush(stdin);
        usuarioDificuldade = getch();
        fflush(stdin);
        if(usuarioDificuldade == 's' || usuarioDificuldade == 83) // Mexe na seta dentro do meno de dificuldades
        {
            Beep(440, 150);
            if(posicaoDificuldade == 3)
                posicaoDificuldade = 1;
            else
                posicaoDificuldade++;
        }
        else if(usuarioDificuldade == 'w' || usuarioDificuldade == 87)
        {
            Beep(440, 150);
            if(posicaoDificuldade == 1)
                posicaoDificuldade = 3;
            else
                posicaoDificuldade--;
        }
        else if(usuarioDificuldade == 27 || usuarioDificuldade == 13)
        {
            Beep(440, 150);
            inicio();
        }
        else
            posicaoDificuldade = posicaoDificuldade;
    }
}




void ajuda() // funcao de ajuda apenas printa informacoes para ajudar o usuario
{
    system("cls");
    char usuarioAjuda;
    printf("\t\t    ___       ____  ______  ___ \n");
    printf("\t\t   /   |     / / / / / __ \\/   |\n");
    printf("\t\t  / /| |__  / / / / / / / / /| |\n");
    printf("\t\t / ___ / /_/ / /_/ / /_/ / ___ |\n");
    printf("\t\t/_/  |_\\____/\\____/_____/_/  |_|\n");
    printf("\n\n");
    printf("\n\n\n");
    printf("\t\t Movimentacao:\n\n\n");
    printf("\t\t Utilize as teclas WASD para jogar!\n");
    printf("\t\t 'A'  -->  Movimenta a peca para a esquerda.\n");
    printf("\t\t 'D'  -->  Movimenta a peca para a direita.\n");
    printf("\t\t 'W'  -->  Rotaciona a peca.\n");
    printf("\t\t 'S'  -->  Desce a peca ate o final do tabuleiro.\n");
    printf("\t\t Existem duas maneiras de se pontuar em um tetris:\n");
    printf("\t\t 1 - Quando uma peca chega ao final do tabuleiro.\n");
    printf("\t\t 2 - Quando uma linha horizontal eh formada.\n");
    fflush(stdin);
    usuarioAjuda = getch();
    fflush(stdin);
    if (usuarioAjuda == 27)
    {
        inicio();
    }
    else
    {
        system("cls");
        ajuda();

    }
}




typedef struct // dados do jogador
{
    char nome[25];
    int pontos; // score
}ranking;

ranking rank;

FILE *arqrank; // ponteiros para arquivos

int compar(const int *a, const int *b) // função de comparação dos pontos no vetor do arquivos
{ // valores aleatorios são selecionados para comparar seu tamanho
    if(*(int*)a == *(int*)b)
        return 0; // se forem iguais, não mudam o valor
    else
        if (*(int*)a < *(int*)b)
            return 1; // se um deles for menor que o outro, o menor vai para a posição inferior a ele
        else return -1; // se não for, faz o serviço contrario
}

int rankingT()
{
system("cls");
        printf("    _____   ______  __      __  __  __  ___  __      __  ____\n");
        printf("   / __ \\  / __  / /  \\    / / / /_/ / / _| /  \\    / / / ___/\n");
        printf("  / /_/ / / /_/ / / /\\ \\  / / /  ___/ / /  / /\ \\   / / / / __  \n");
        printf(" / / \\ \\_/ __  / / /  \\ \\/ / / _ \\   / /  / /  \\ \\/ / / /_| |\n");
        printf("/_/   \\___/ /_/ /_/    \\__/ /_/ \\_\\ /__/ /_/    \\__/ /______/\n");
        //comando para o usuario para melhor uso do ranking
        printf("\n\tAperte qualquer tecla se quiser atualizar o ranking\n\te 'esc' pra voltar ao menu.\n");

        mostrar();
}

int inserir(){
    arqrank=fopen("arqranking.txt","a+b"); // abre o arquivo para alteração e leitura
    rank.pontos = score; // pega a pontuação do jogador
    printf("\n\n\n\t   Inserir seu nome (Use apenas letras e numeros): ");
        fflush(stdin);
        scanf("%s", &rank.nome); // pega o nome do jogador

    fprintf(arqrank,"\n%s \t %i \n",rank.nome,rank.pontos); // printa no arquivo os dados do jogador
    fclose(arqrank); // fecha o arquivo

    system("pause");
}

int mostrar() // função que mostra os jogadores, suas pontuação e o ranking
{
     int atualizar, x = 1, i = 0;
        while(i != 2){
        arqrank=fopen("arqranking.txt","r"); // escreve o que esta escrito no ranking
        ++i;
        }
                printf("\n\t|NOME          |PONTUACAO: \n");
                  printf("\t|              |           \n");

while(1){

pontos[x] = rank.pontos;

    fscanf(arqrank, "%s \t %i \n",&rank.nome,&rank.pontos); // pega os dados do arquivos

        (strlen(rank.nome) <= 3 )? printf("\t|%s\t    \t %i \n",rank.nome,rank.pontos):
            printf("\t|%s   \t %i \n",rank.nome,rank.pontos); // printam os dados na tela

    if(feof(arqrank)) // Mostra o fim do arquivos e quebra o looping
            break;
        ++x;

  }

    qsort(pontos,x+1, sizeof(int), compar); // função de ordenação de um vetor com as pontuações dos jogadores

    printf("\n\n\t  RECORDES\n\n");

    for(i = 1; i <= x; ++i){
        printf("\t%i Colocado: %i\n", i, pontos[i]); // printa as pontuações de acordo com a quantidade no vator
    }

    printf("\n\n\nAtualize o ranking constantemente para ter\nnum resultado mais preciso dos recordes.\n");

    atualizar = getch(); // atualiza o ranking para atualizar a função qsort
    (atualizar == 27)?inicio():rankingT();

}



void menu() //Mostra a pagina inicial do menu
{
    posicaoMenu = 1;
    char usuario = 90;
    color(10);
    while(1)
    {
        system("cls");
        printf("    ___       ___       ___       ___       ___       ___   \n");
        printf("   /\\  \\     /\\  \\     /\\  \\     /\\  \\     /\\  \\     /\\  \\  \n");
        printf("   \\:\\  \\   /::\\  \\    \\:\\  \\   /::\\  \\   _\\:\\  \\   /::\\  \\ \n");
        printf("   /::\\__\\ /::\\:\\__\\   /::\\__\\ /::\\:\\__\\ /\\/::\\__\\ /\\:\\:\\__\\\n");
        printf("  /:/\\/__/ \\:\\:\\/  /  /:/\\/__/ \\;:::/  / \\::/\\/__/ \\:\\:\\/__/\n");
        printf("  \\/__/     \\:\\/  /   \\/__/     |:\/__/    \\:\\__\\    \\::/  / \n");
        printf("             \\/__/               \\|__|     \\/__/     \\/__/  \n");
        printf("\n\n\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        setaAqui(1, posicaoMenu);  //Posicao da seta 1
        printf("\t\t|\tJogar\t\t|\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
        setaAqui(2, posicaoMenu);  //Posicao da seta 2
        printf("\t\t|\tDificuldade\t|\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        setaAqui(3, posicaoMenu);  //Posicao da seta 3
        printf("\t\t|\tRecordes\t|\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        setaAqui(4, posicaoMenu);  //Posicao da seta 4
        printf("\t\t|\tAjuda\t\t|\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
        setaAqui(5, posicaoMenu);  //Posicao da seta 5
        printf("\t\t|\tSair\t\t|\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        usuario = getch();
        if(usuario == 's' || usuario == 83) // permite o usuario colocar a seta para baixo
        {

            Beep(440, 150);
            if(posicaoMenu == 5)
                posicaoMenu = 1;
            else
                posicaoMenu++;
        }
        else if(usuario == 'w' || usuario == 87) // permite o usuario colocar a seta para cima
        {
            Beep(440, 150);
            if(posicaoMenu == 1)
                posicaoMenu = 5;
            else
                posicaoMenu--;
        }
        else if(usuario == 13 )
            break;
    }
    if(posicaoMenu == 1) //Se a primeira opcao do menu for selecionada, chama o jogo em si
    {
        char continuar;
        score = 0;
        contador = 0;
        if(compararGameOver() == 1)
        {
            apagarTabuleiroTodo();
        }

        if(sair == 27)
        {
            system("cls");
            printf("\n\n");
            printf("\t\t\tVoce deseja continuar o jogo anterior?\n\n");
            printf("\t\t\tDigite 's' para sim e 'n' para nao:");
            continuar = getch();
            switch(continuar)
            {
            case 's':
                jogar();
            case 'n':
                apagarTabuleiroTodo();
                zerarTudo();
                break;
            }
        }
        zerarTudo();
    }
    else if(posicaoMenu == 2) // Se a segunda opcao do menu for selecionada, chama o menu de dificuldades
    {
        dificuldade();
    }
    else if(posicaoMenu == 3)// Se a terceira opcao do menu for selecionada, chama o ranking
    {
        rankingT();
    }
    else if(posicaoMenu == 4)// Se a quarta opcao do menu for selecionada, chama o menu de ajuda
    {
        ajuda();
    }
    else if(posicaoMenu == 5) // Se a quinta opcao do menu for selecionada, encerra o programa
    {
        exit(0);
    }
}

