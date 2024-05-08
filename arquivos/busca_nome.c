#include <stdio.h>
#include <string.h>

int main() {
    char nomeArquivo[40], palavra[40];
    printf("Informe o nome do arquivo.txt: ");
    scanf("%s", nomeArquivo); 

    printf("Informe a palavra repetida: ");
    scanf("%s", palavra); 

    FILE *busca;

    busca = fopen(nomeArquivo, "r");
    if (busca == NULL) {
        printf("ERROR\n");
        return -1;
    }

    char linha[81];
    int contador = 0;
    int tamanhoPalavra = strlen(palavra);

    while (fgets(linha, sizeof(linha), busca) != NULL) {
        int i = 0, j = 0, k = 0;
        while (linha[i] != '\0') {
            if (linha[i] == palavra[j]) {
                k++;
                j++;
                if (j == tamanhoPalavra) {
                    contador++;
                    j = 0; 
                }
            } else {
                j = 0; 
                k = 0;
            }
            i++;
        }
    }

    printf("%d", contador);

    fclose(busca);
    return 0;
}
