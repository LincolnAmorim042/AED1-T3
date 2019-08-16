//Trabalho 3 - Vampiros
//Alunos:
//Lincoln Amorim, RGM: 41443
//Gabriela Marculino, RGM: 41431
//Leonardo Henrique, RGM: 41440

#include <stdio.h>
#include <stdlib.h>

//Declaração das variáveis globais
int bat[100];
int ev1;
int ev2;
int at;
int d;
int t;
int dado;

//Módulo de execução da batalha
int batalha(int ev1, int ev2, int at, int d, int t){
    //Declaração e inicialização da variável local
    int duel;
    duel=1;

    printf("EV1     EV2     AT      D       T       DADO        VENCEDOR DO TURNO\n");
    printf("%d       %d       %d       %d       %d       \n", ev1, ev2, at, d, t);
        do{
            dado = (rand()%5)+1; //Dado aleatório de 1 a 6

            //Critério para definir o vencedor de cada turno
            if (dado<=at){
                ev1 = ev1+d;
                ev2 = ev2-d;
                printf("%d       %d       %d       %d       %d       %d           VAMPIRO 1\n", ev1, ev2, at, d, duel, dado);
            }else{
                ev2 = ev2+d;
                ev1 = ev1-d;
                printf("%d       %d       %d       %d       %d       %d           VAMPIRO 2\n", ev1, ev2, at, d, duel, dado);
            }

            //Critério para definir o vencedor antes do final dos turnos
            if (ev1<=0){
                return(2);
            }
            if (ev2<=0){
                return(1);
            }
            duel = duel+1;
        }while(duel<=t);

        //Critério para definir o vencedor no final dos turnos
        if (ev1<ev2){
           return (2);
        }
        if(ev2<ev1){
            return(1);
        }

        //Caso não entre em nenhum critério será definido como empate
        return (0);
}


int main(){
    //Declaração das variaveis locais
    int pause;
    int tamanho;
    int comb;
    int i;
    int fim;
    //Inicialização da variável "fim"
    fim=1;
    srand(time(NULL));  //Zerando o "time" do dado

    //Entrada dos valores
    printf("\nDefina os valores do combate:\n");
    i=0;  //Contador do próximo "do"
    do{
        i++;

        //Entrada dos valores no vetor, terminará quando houverem dois zeros seguidos
        scanf("%d", &bat[i]);

        if (i>1){
        if (bat[i]==0){
                if (bat[i-1]==0){
                    fim=0;
                }
            }
        }
        tamanho = i-1;
    }while(fim!=0);

    //Transforma o "tamanho do vetor" num inteiro múltiplo de 6
    tamanho = (tamanho/6)*6;

    i=1;  //Contador do próximo "do"
    do{
        //Definindo o valor das variáveis
        ev1 = bat[i];
        ev2 = bat[i+1];
        at = bat[i+2];
        d = bat[i+3];
        t = bat[i+4];
        pause = bat[i+5];
        printf("\n");

        //Restrições de valores
        if ((ev1<1)||(ev2>10)||(at<1)||(at>5)||(d<1)||(d>10)||(t<1)||(t>100)||(pause!=0)){
            printf("Valor invalido, duelo cancelado\n");
        }else{
            //Caso os valores estejam corretos, chamada do módulo "batalha"
            comb = batalha(ev1, ev2, at, d, t);

            //Teste do vencedor e saída
            if (comb==1){
                printf("Vitoria Vampiro 1!\n");
            }
            if (comb==2){
                printf("Vitoria Vampiro 2!\n");
            }
            if (comb==0){
                printf("Empate!\n");
            }
        }
        i=i+6; //Contador para ir para o próximo duelo
    }while(i<=tamanho);

   return 0;
}
