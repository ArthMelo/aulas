#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int posicao(char *substr, char *str);

int main()
{
    char *string, *subString;
    string = (char *)malloc(sizeof(char) * 41);
    subString = (char *)malloc(sizeof(char) * 41);

    strcpy(string, "Amendobobo");
    strcpy(subString, "bobo");

    int resposta = posicao(subString, string);

    printf("%d\n", resposta);

    free(string);
    free(subString);
    return 0;
}

int posicao(char *substr, char *str)
{
    int posicao;
    int tamanhoString = strlen(str);
    int tamanhoSub = strlen(substr);
    int j;

    for (int i = 0; str[i] != '\0'; i++)
    {
        j = 0;
        while (substr[j] != '\0' && substr[j] == str[i + j])
        {
            j++;
        }

        if (substr[j] == '\0')
        {
            posicao = i+1;
            return posicao;
        }
    }
}
