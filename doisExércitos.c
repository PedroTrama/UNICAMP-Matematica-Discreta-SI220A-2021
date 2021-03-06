#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//VARIAVEIS GLOBAIS
int capturado = 0,impossibilitar,sair=1;
int ganhou=0, mensageiro=1;
int seqMensageiros=1, sinalizador,utilizadosVer,utilizadosAzul;
int mensageirosVer = 5, mensageirosAzul = 10;
int sobreviveu = 1;
int tempoMensageiro, tempoTotal=0;
int horas = 0,minutos = 0;

//sorteio pra ver qnt tempo o mensageiro demorou
void sorteioTempo(){
    tempoMensageiro = 3600 + (rand()) % (4201-3600);
    tempoTotal = tempoTotal + tempoMensageiro;
}

//Conferindo se o mensageiro foi capturado
void captura()
{
    capturado = 1 + (rand() % 101);
    if (capturado <= 45)
    {
        sobreviveu = 0;
    }
    else sobreviveu = 1;
}

//Chance do exercito azul n poder fazer o ataque naquele horario
void imposibilita()
{
    impossibilitar = 1 + (rand() % 101);

    if (impossibilitar <= 1)
    {
        sair = 0;
    }
}

//verifica qual exercito vai enviar o mensageiro
void qualExercito(){
    if(seqMensageiros == 1) //se a varivel seqMensageiros == 1 entao é a vez do exercito vermelho
        {
            mensageirosVer = mensageirosVer - 1;
            seqMensageiros = 0;
            sorteioTempo();
            captura();
            imposibilita();
        }
        else  //se a variavel é == 0 é a vez do azul
        {
            mensageirosAzul = mensageirosAzul - 1;
            seqMensageiros = 1;
            sorteioTempo();
            captura();
            imposibilita();
        }
}

void transformarEmHoras(){
    do
    {
        if(tempoTotal>=3600)
        {
            horas = horas + 1;
            tempoTotal = tempoTotal - 3600;
        }
        if (tempoTotal>=60)
        {
            minutos = minutos +1;
            tempoTotal = tempoTotal - 60;
        }
    }
    while(tempoTotal>60);
}

void verficiaGanhou(){
    if(ganhou == 1)
    {
        printf("O exercito ganhou a batalha! :) \n");
    }
    else
    {
        printf("O exercito perdeu a batalha! :( \n");
    }
}

int main()
{
    int i, cont=0;
    srand((unsigned)time(NULL));

    //repetição pra ver quantos mensageiros foram usados por exercito
     while(1)
    {
        if((mensageirosVer == 0) || (mensageirosAzul == 0))
        {
            ganhou = 0;
            sair = 0;
            break;
        }

        qualExercito();

        if((tempoMensageiro > 4200) || ((tempoTotal>12601) && (mensageirosAzul==9)))
        {
            sobreviveu=0;
            sair = 1;
        }
        if((mensageirosVer<=4)&&(mensageirosAzul<=9)&&(sobreviveu==1))
        {
            ganhou = 1;
            sair = 0;
            break;
        }
        if(sobreviveu==0)
        {
            sair=1;
        }
    }

    verficiaGanhou();

    //calcula quantos mensageiros foram utilizados
    utilizadosVer = 5 - mensageirosVer;
    utilizadosAzul = 10 - mensageirosAzul;

    transformarEmHoras();

    printf("Tempo da troca de mensagens: %i : %i : %i \n",horas,minutos,tempoTotal);
    printf("Mensageiros utilizado do exercito vermelho: %i \n",utilizadosVer);
    printf("Mensageiros utilizado do exercito azul: %i\n", utilizadosAzul);
}