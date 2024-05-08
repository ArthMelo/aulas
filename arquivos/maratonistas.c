#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A, C;

    FILE *tempos;
    tempos = fopen("tempos.txt", "r");
    if(tempos == NULL)
    {
        printf("ERROR\n");
        fclose(tempos);
        return -1;
    }

    fscanf(tempos, "%d %d", &A, &C);

    int cronometro[A][C][3];

    for(int i = 0; i < A; i++)
    {
        for(int j = 0; j < C; j++)
        {
            fscanf(tempos, "%d %d %d", &cronometro[i][j][0], &cronometro[i][j][1], &cronometro[i][j][2]);
        }
    }

    float menorMedia[A], media;

    for(int i = 0; i < A; i++)
    {
        menorMedia[i] = 0;
        for(int j = 0; j < C; j++)
        {
            media = (cronometro[i][j][0] * 3600) + (cronometro[i][j][1] * 60)+ cronometro[i][j][2];
            menorMedia[i] += media;
        }
        menorMedia[i] /= C;
    }

    float min = 10000000;
    int bolt;

    for(int i = 0; i < A; i++)
    {
        if(menorMedia[i] < min)
        {
            min = menorMedia[i];
            bolt = i;
        }
    }

    printf("%d", bolt + 1);

    fclose(tempos);
    return 0;
}

