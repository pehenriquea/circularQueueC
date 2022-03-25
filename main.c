#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

double listaCircular();
int mostrarArray();
bool pesquisaElemento();
void retornaPos();
double remover();

int main()
{
    int tamanho, posicao=0, primeiro=0, auxPos, resp1, resp2, resp3;
    double numero, pesquisa=0;

    printf("Digite o tamanho da fila: ");
    scanf("%d", &tamanho);

    if (tamanho<=0){
        printf("Array Vazio!!!!");
        exit(0);
    }

    double array[tamanho+1];

    for (int i=0; i<tamanho; i++){

        printf("Digite o valor do %d numero da fila: ", i+1);
        scanf("%lf", &numero);
        listaCircular(array, posicao, tamanho, numero);
        posicao++;

    }

    printf("\nDeseja adicionar outro numero? Digite 1 para sim e 2 para nao: ");
    scanf("%d", &resp1);

    while(resp1 == 1){

        printf("Digite o numero: ");
        int k = scanf("%lf", &numero);
        array[posicao] = remover(array, posicao+2, primeiro, tamanho);
        int auxPosicao = tamanho-1;
        listaCircular(array, auxPosicao, tamanho, numero);
        printf("\nDeseja adicionar outro numero? Digite 1 para sim e 2 para nao: ");
        scanf("%d", &resp1);

    }

    printf("\nDeseja pesquisar um numero? Digite 1 para sim e 2 para nao: ");
    scanf("%d", &resp2);

    if (resp2 == 1){
        printf("Digite o numero: ");
        scanf("%lf", &numero);

        if (pesquisaElemento(array, tamanho, numero) == true){
            printf("Elemento encontrado!\n");
        } else{
            printf("Elemento nao encontrado!\n");
        }

    }

    printf("\nDeseja pesquisar a posicao de um elemento? Digite 1 para sim e 2 para nao: ");
    scanf("%d", &resp3);

    if (resp3 == 1){

        retornaPos(array);

    }

    mostrarArray(array, tamanho);

    return 0;
}

double listaCircular(double vetor[], int pos, int tam, double x){

    tam+=1;
    pos = (pos+1) % tam;
    vetor[pos] = x;

    return *vetor;

}

int mostrarArray(double *vetor, int tam){

    if (tam>0){
        mostrarArray(vetor, tam-1);
        printf("   %.2f\n", vetor[tam]);
    }
    else{
        printf("|| Array ||\n");
        return 0;
    }

}

bool pesquisaElemento(double *vetor, int tam, double elemento){

    for (int i=0; i<tam+1; i++){
        if (vetor[i]==elemento){
            return true;
        }
    }
    return false;
}

void retornaPos(double *vetor[]){

    int auxPos;
    printf("Digite a posicao: ");
    scanf("%d", &auxPos);

    if (auxPos == 0){
        printf("Posicao invalida!\n");
    } else {
         printf("Posicao %d, elemento %.2f\n\n", auxPos, vetor[auxPos]);
    }

}

double remover(double *vetor, int u, int p, int tam){

    if (p == u) {
    printf("Erro no remover!");
    exit(0);
    }

    for (int i = 0; i < tam; i++){
         vetor[i] = vetor[i+1];
      }

    p = (p + 1) % tam;
    return 0;

    }
