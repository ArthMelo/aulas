#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int *i, j;
    float *notas;
    char *nome;

    // coloque na variável *i o valor 10 de duas formas distintas ...
    i = &j;

    j = 10;  // primeira forma
    *i = 10; // segunda forma

    printf("%d\n", *i);

    // carregue na variável ’notas’ 5 valores distintos de notas ...

    notas = (float *)malloc(sizeof(float) * 5);
    for (int i = 0; i < 5; i++)
    {
        scanf("%f", notas + i);
    }

    for (int i = 0; i < 5; i++)
    {
        printf("%.1f\n", *(notas + i));
    }

    // carregue na variável ’nome’ o seu primeiro e ultimo nome usando somente letras minúsculas ...

    nome = (char *)malloc(sizeof(char) * 14);
    strcpy(nome, "arthur barbosa");

    // altere as letras iniciais do seu nome para letras maiúsculas ...

    nome[0] = nome[0] - ('a' - 'A');

    for (int i = 1; i < 14; i++)
    {
        if (nome[i] == ' ')
        {
            nome[i + 1] = nome[i + 1] - ('a' - 'A');
        }
    }

    printf("%s\n", nome);

    free(nome);

    return 0;
}
