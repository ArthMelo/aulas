#include <stdio.h>
#include <stdlib.h>

int main()
{
    char entradaArquivo[40], saidaArquivo[40], texto[80];

    printf("Informe o nome do arquivo de entrada: ");
    scanf("%s", entradaArquivo);
    printf("Informe o nome do arquivo de saida: ");
    scanf("%s", saidaArquivo);

    FILE *alunos;
    FILE *saida;

    char nome[40];
    float p1, p2, trab, media;

    alunos = fopen(entradaArquivo, "r");
    saida = fopen(saidaArquivo, "w");

    if(alunos == NULL || saida == NULL)
    {
        printf("ERROR\n");
        return -1;
    }

    while(fscanf(alunos, "%s %f %f %f", nome, &p1, &p2, &trab) == 4)
    {
        media = (((p1+p2)/2)*0.8) + (trab*0.2);
        fprintf(saida, "%s %.2f\n", nome, media);
    }

    fclose(alunos);
    fclose(saida);

    return 0;
}
