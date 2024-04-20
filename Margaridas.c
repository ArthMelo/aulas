#include <stdio.h>
#include <stdlib.h>

int **aloca_linhas(int linhas);
void aloca_colunas(int **matriz, int linhas, int colunas);
void le_dados(int **matriz, int linhas, int colunas);
void max_lote(int **matriz, int linhas, int colunas, int M, int N);

int main()
{
    int **matriz;
    int linhas, colunas, M, N;

    puts("Informe o numero de linhas e colunas de vasos existentes: ");
    scanf("%d %d", &linhas, &colunas);
    puts("Informe o numero de linhas e colunas dos lotes: ");
    scanf("%d %d", &M, &N);

    puts("Alocando memoria...\n");
    matriz = aloca_linhas(linhas);
    aloca_colunas(matriz, linhas, colunas);
    le_dados(matriz, linhas, colunas);

    max_lote(matriz, linhas, colunas, M, N);

    return 0;
}

int **aloca_linhas(int linhas)
{
    return (int **)malloc(sizeof(int *) * linhas);
}

void aloca_colunas(int **matriz, int linhas, int colunas)
{
    for (int i = 0; i < linhas; i++)
    {
        *(matriz + i) = (int *)malloc(sizeof(int) * colunas);
    }
}

void le_dados(int **matriz, int linhas, int colunas)
{
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            printf("matriz[%d][%d]: ", i, j);
            scanf("%d", *(matriz + i) + j);
        }
    }
}

void max_lote(int **matriz, int linhas, int colunas, int M, int N)
{
    int max = 0;

    for (int l = 0; l < colunas; l += N)
    {
        for (int k = 0; k < linhas; k += M)
        {
            int aux = 0;
            for (int i = k; i < M + k; i++)
            {
                for (int j = l; j < N + l; j++)
                {
                    aux += *(*(matriz+i)+j);
                }
            }
            if (aux > max)
            {
                max = aux;
            }
        }
    }
    printf("O numero maximo de margaridas colhidas em um unico lote eh: %d\n", max);
}
