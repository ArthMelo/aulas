#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *concatena(char *s1, char *s2);

int main()
{
    char *s1, *s2;
    s1 = (char *)malloc(sizeof(char) * 7);
    s2 = (char *)malloc(sizeof(char) * 7);
    strcpy(s1, "arthur");
    strcpy(s2, "melo");

    *concatena(s1, s2);
}

char *concatena(char *s1, char *s2)
{
    char *novaCadeia = s1;

    int tamanho1 = strlen(s1), tamanho2 = strlen(s2);

    novaCadeia = (char *)malloc(sizeof(char) * (tamanho1 + tamanho2));

    strcpy(novaCadeia, s1);
    strcat(novaCadeia, s2);
    

    printf("%s\n", novaCadeia);

    return 0;
}
