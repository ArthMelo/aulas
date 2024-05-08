#include <stdio.h>
#include <string.h>

void minusculo(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] += 'a' - 'A';
        }
        if (str[i] == ' ' || str[i] == '\0')
        {
            str[i] = ' ';
        }
    }
}

int contarPalavra(FILE *busca, char *palavra)
{
    char linha[81];
    int contador = 0;
    int tamanhoPalavra = strlen(palavra);

    while (fgets(linha, sizeof(linha), busca) != NULL)
    {
        int i = 0, j = 0, k;
        minusculo(linha);
        while (linha[i] != '\0')
        {
            if (linha[i] == palavra[j])
            {
                j++;
                if (j == tamanhoPalavra && (linha[i+1] == ' ' || linha[i+1] == '\0' || linha[i+1] == '\n') && (linha[i-j] == ' ' || i -j == -1))
                {
                    contador++;
                    j = 0;                        
                }
            }
            else
            {
                j = 0;
            }
            i++;
        }
    }

    return contador;
}

int main()
{
    char nomeArquivo[40], palavra[40];
    printf("Informe o nome do arquivo.txt: ");
    scanf("%s", nomeArquivo);

    printf("Informe a palavra repetida: ");
    scanf("%s", palavra);
    minusculo(palavra);

    FILE *busca;

    busca = fopen(nomeArquivo, "r");
    if (busca == NULL)
    {
        printf("ERROR\n");
        return -1;
    }

    int contador = contarPalavra(busca, palavra);

    printf("%d", contador);

    fclose(busca);
    return 0;
}
