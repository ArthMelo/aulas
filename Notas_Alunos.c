#include<stdio.h>

typedef struct alunos_{
    char nome[40];
    float P1, P2, T;
} ALUNOS;

int main()
{
    FILE *arquivo;
    char nomeArquivo[40];
    int numeroAlunos;

    printf("Insira o numero de alunos: ");
    scanf("%d", &numeroAlunos);
    printf("Insira o nome do arquivo: ");
    scanf("%s", nomeArquivo);

    ALUNOS alunos[numeroAlunos];

    arquivo = fopen(nomeArquivo, "w+");

    if(arquivo == NULL)
    {
        printf("Erro ao abrir arquivo\n");
        return -1;
    }

    for(int i = 0; i < numeroAlunos; i++)
    {
        printf("Insira o nome do aluno %d: ", i+1);
        scanf("%s", alunos[i].nome);
        printf("Insira as notas do %s: ", alunos[i].nome);
        scanf("%f %f %f", &alunos[i].P1, &alunos[i].P2, &alunos[i].T);

        fprintf(arquivo, "%s %.1f %.1f %.1f\n", alunos[i].nome, alunos[i].P1, alunos[i].P2, alunos[i].T);
    }

    fclose(arquivo);
    return 0;
}
