#include <stdio.h>
#include <stdlib.h>

typedef struct _notas
{
    char nome[40];
    float p1, p2, trab;
} ALUNO;

int main()
{
    int numeroAlunos;
    char nomeArquivo[40];
    printf("Informe o nome do arquivo de saida.txt: ");
    scanf("%s", nomeArquivo);
    printf("Informe o numero de alunos: ");
    scanf("%d", &numeroAlunos);

    FILE *backup;
    ALUNO alunos[numeroAlunos];

    backup = fopen(nomeArquivo, "w");

    for (int i = 0; i < numeroAlunos; i++)
    {
        printf("Informe o nome do aluno %d: ", i + 1);
        scanf("%s", (alunos[i].nome));
        printf("Informe as 3 notas do %s: ", (alunos[i].nome));
        scanf("%f %f %f", &alunos[i].p1, &alunos[i].p2, &alunos[i].trab);
        fprintf(backup, "%s %.1f %.1f %.1f\n", (alunos[i].nome), (alunos[i].p1), (alunos[i].p2), (alunos[i].trab));
    }

    fclose(backup);
}
