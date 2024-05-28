#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char *concatena(char *s1, char *s2)
{
    int tam1, tam2;
    char *novaString;
    tam1 = strlen(s1), tam2 = strlen(s2);
    novaString = (char *)malloc(sizeof(char)*(tam1+tam2+1));
    if(novaString == NULL)
    {
        printf("Erro ao alocar memoria\n");
        return 0;
    }
    strcpy(novaString, s1);
    strcat(novaString, s2);

    printf("%s", novaString);
    free(novaString);

}

int main()
{
    char *s1, *s2;
    s1 = (char *)malloc(sizeof(char));
    s2 = (char *)malloc(sizeof(char));

    if (s1 == NULL || s2 == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    strcpy(s1, "Arthur");
    strcpy(s2, "Melo");

    char *resultado = concatena(s1, s2);
    printf("%s\n", resultado);


    free(s1);
    free(s2);
    return 0;
}
