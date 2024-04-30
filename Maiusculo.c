#include <stdio.h>
#include <stdlib.h>

int main()
{
    int c;
    char nomeArquivo1[40], nomeArquivo2[40];
    printf("Digite o nome do primeiro arquivo.txt: ");
    scanf("%s", nomeArquivo1);
    printf("Digite o nome do segundo arquivo.txt: ");
    scanf("%s", nomeArquivo2);

    FILE *arquivo1;
    FILE *arquivo2;

    arquivo1 = fopen(nomeArquivo1, "r");
    arquivo2 = fopen(nomeArquivo2, "w");

    if (arquivo1 == NULL || arquivo2 == NULL)
    {
        printf("Erro ao abrir arquivos\n");
        return -1;
    }

    c = fgetc(arquivo1);

    while (!feof(arquivo1))
    {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        {
            if (c >= 'a' && c <= 'z')
            {
                c = c - 'a' + 'A';
            }
            putc(c, arquivo2);
        }
        else
        {
            putc(c, arquivo2);
        }
        c = fgetc(arquivo1);
    }

    fclose(arquivo1);
    fclose(arquivo2);

    return 0;
}
