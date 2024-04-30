#include <stdio.h>
#include <stdlib.h>

void contador(FILE *arquivo, char vogal, char vogalMaiuscula)
{
    int c, conta = 0;
    c = fgetc(arquivo);
    while (!feof(arquivo))
    {
        if (c == vogal || c == vogalMaiuscula)
        {
            conta++;
        }
        c = fgetc(arquivo);
    }

    rewind(arquivo);

    printf("A letra %c aparece %d vezes\n", vogalMaiuscula, conta);
}

int main()
{
    char nome[40];
    int a, e, i, o, u;
    printf("Insira o nome do arquivo.txt: ");
    scanf("%s", nome);
    FILE *arquivo;

    arquivo = fopen(nome, "r");

    if (arquivo == NULL)
    {
        printf("Arquivo nao pode ser aberto ou nao existe.\n");
        return -1;
    }

    contador(arquivo, 'a', 'A');
    contador(arquivo, 'e', 'E');
    contador(arquivo, 'i', 'I');
    contador(arquivo, 'o', 'O');
    contador(arquivo, 'u', 'U');

    fclose(arquivo);
    return 0;
}
