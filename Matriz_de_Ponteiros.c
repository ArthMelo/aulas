#include <stdio.h>
#include <stdlib.h>
int **aloca_linhas(int);
void aloca_colunas(int **, int, int);
void le_dados(int **, int, int);
void imprime_matriz(int **, int, int);
void troca_linhas(int **matriz, int linha1, int linha2);
int main(void)
{
    int **matriz;
    int lin, col;
    int linha1, linha2;
    puts("Qual o numero de linhas?");
    scanf("%d", &lin);
    matriz = aloca_linhas(lin);
    puts("Qual o numero de colunas?");
    scanf("%d", &col);
    printf("Alocando espaco para linhas.\n");
    aloca_colunas(matriz, lin, col);
    le_dados(matriz, lin, col);
    imprime_matriz(matriz, lin, col);
    puts("Qual a primeira linha a ser trocada?");
    scanf("%d", &linha1);
    puts("Qual a segunda linha a ser trocada?");
    scanf("%d", &linha2);
    troca_linhas(matriz, linha1-1, linha2-1);
    imprime_matriz(matriz, lin, col);
    return 0;
}

int **aloca_linhas(int lin)
{
    return ((int **)malloc(sizeof(int *) * lin));
}

void aloca_colunas(int **matriz, int lin, int col)
{
    for (int i = 0; i < lin; i++)
    {
        *(matriz + i) = (int *)malloc(sizeof(int) * col);
    }
}

void le_dados(int **matriz, int lin, int col)
{
    printf("linhas: %d\ncolunas:%d\n", lin, col);
    for (int i = 0; i < lin; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("matriz[%d][%d]: ", i, j);
            scanf("%d", *(matriz + i) + j);
        }
    }
}

void imprime_matriz(int **matriz, int lin, int col)
{
    for (int i = 0; i < lin; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("[%d]", *(*(matriz + i) + j));
        }
        printf("\n");
    }
}

void troca_linhas(int **matriz, int linha1, int linha2)
{
    int *temp = *(matriz + linha1); 
    *(matriz + linha1) = *(matriz + linha2); 
    *(matriz + linha2) = temp; 
}
