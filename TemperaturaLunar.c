//Trabalho 3 - Temperatura Lunar
//Alunos:
//Lincoln Amorim, RGM: 41443
//Gabriela Marculino, RGM: 41431
//Leonardo Henrique, RGM: 41440

#include <stdio.h>
#include <stdlib.h>

//Declaração das variáveis globais
int test[1000];
    //Obs.: Vetores "maior" e "menor" usados apenas para o armazenamento dos resultados
int menor[100];
int maior[100];
int n;
int m;
    //Variáveis contadoras
int nt;
int i;
int j;


//Módulo do desenvolvimento das operações
void desenv(int n, int m){
    //Declaração das variáveis locais
    int soma;
    int media;
    int fim;
        //Variáveis contadoras
    int ii;
    int conts;
    int quants;

    //Preparação das variáveis para reiniciar o cálculo sempre que o módulo for chamado
    menor[nt]=201;
    maior[nt]=-201;
    conts=(i-n)+1;
    ii=conts;
    soma=0;
    quants=0;
    fim=0;

    do{
        do{
            //Operação para a soma dos valores da temperatura
            fim=conts;
            soma=soma+test[conts];
            conts=conts+1;
            quants=quants+1;
        }while(m>quants);

        //Cálculo da média com base no parâmetro M
        media=soma/m;

        //Teste para saber se a média é maior ou menor que a anterior
        if(media>maior[nt]){
            maior[nt]=media;
        }
        if(media<menor[nt]){
            menor[nt]=media;
        }
        //Preparação das variáveis para o próximo loop
        ii=ii+1;
        conts=ii;
        media=0;
        soma=0;
        quants=0;

    //O loop irá terminar quando a última temperatura for somada pela primeira vez
    }while(fim<j-1);
}

int main(){
    //Declaração das variáveis locais
    int ulti;
    int passou;

    //Inicialização das variáveis
    m=1;
    i=0;
    ulti=0;
    j=1;
    nt=0;
    passou=0;

    printf("\nDefina o valor de N:\n");
    //Loop para entrada dos valores no vetor
    do{
        i++;
        scanf("%d", &test[i]);
        if(i<=1){
            //Teste de validez do N, repetirá até que a entrada esteja correta
            while((test[i]<0)||(test[i]>800)){
                printf("\nEntrada invalida, reentre: ");
                scanf("%d", &test[i]);
            }
            n = test[i];
            printf("\nEntre o valor e M, e, em seguida, o das %d medicoes de temperatura: ", n);
            j = j+n+2;
            passou=1;
        }
        if(i>=2){
            //Sempre que passou for igual à 1 significa que a última entrada foi atribuída à N, logo, a atual será para M
            if(passou==1){
                if(n!=0){
                    //Teste de validez do M, repetirá até que a entrada esteja correta
                    while((test[i]<1)||(test[i]>n)){
                        printf("\nEntrada invalida, reentre: ");
                        scanf("%d", &test[i]);
                    }
                }
                m = test[i];
                passou=0;
                }
        }
            if((test[i]!=n)||(test[i]!=m)){
                //Teste de validez das temperaturas, repetirá até que a entrada esteja correta
                while((test[i]<-200)||(test[i]>200)){
                    printf("\nEntrada invalida, reentre: ");
                    scanf("%d", &test[i]);
                }
            }
            if(i==j-1){
                //Contagem do número de testes que serão realizados
                nt=nt+1;

                //Chamada do módulo de desenvolvimento
                desenv(n, m);
                printf("\nDefina o valor de N:\n");
            }
            if(i==j){
                //Teste de validez do novo N, repetirá até que a entrada esteja correta
                while((test[i]<0)||(test[i]>800)){
                    printf("\nEntrada invalida, reentre: ");
                    scanf("%d", &test[i]);
                }
                n=test[i];

                if(n!=0){
                    printf("\nEntre o valor e M, e, em seguida, o das %d medicoes de temperatura: ", n);
                    passou=1;
                    j = j+n+2;
                }
            }
            //Finalização do vetor
            if(n==0){
                printf("\nEntre 0 para finalizar: ");
                scanf("%d", &m);
            }
    }while(m!=0);

    //Loop para a saída dos resultados dos testes
    do{
        ulti=ulti+1;
        printf("\nTeste %d", ulti);
        printf("\n%d %d", menor[ulti], maior[ulti]);
        printf("\n");
    }while(ulti<nt);
}
