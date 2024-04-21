#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _func
{
    char nome[40];
    int ano_nasc;
    float renda;
} Tfunc;

void *inicializa(Tfunc *cadastro, int n);
void *inclui_novos(Tfunc *cadastro, int n, int a);
void imprime(Tfunc *cadastro, int zero, int todos_func);

int main(void)
{
    Tfunc *cadastro;
    int funcionarios, adicionais;
    printf("Quantos funcionarios? ");
    scanf("%d", &funcionarios);
    cadastro = inicializa(cadastro, funcionarios);
    if (!cadastro)
        return -1;
    printf("Quantos funcionarios a mais deseja adicionar? ");
    scanf("%d", &adicionais);
    cadastro = inclui_novos(cadastro, funcionarios, adicionais);
    if (!cadastro)
        return -1;
    printf("Lista de funcionarios cadastrados:\n");
    imprime(cadastro, 0, funcionarios + adicionais);
    free(cadastro);
    return 0;
}

void *inicializa(Tfunc *cadastro, int n)
{
    cadastro = (Tfunc *)malloc(n * sizeof(Tfunc));
    if (!cadastro)
    {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }

    printf("Digite os dados dos funcionarios:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Nome do funcionario %d: ", i + 1);
        scanf("%s", (cadastro + i)->nome);
        printf("Ano de nascimento do funcionario %d: ", i + 1);
        scanf("%d", &((cadastro + i)->ano_nasc));
        printf("Renda do funcionario %d: ", i + 1);
        scanf("%f", &((cadastro + i)->renda));
    }

    return cadastro;
}

void *inclui_novos(Tfunc *cadastro, int n, int a)
{
    cadastro = (Tfunc *)realloc(cadastro, (n + a) * sizeof(Tfunc));

    if (!cadastro)
    {
        printf("Erro ao realocar memória.\n");
        exit(1);
    }

    for (int i = n; i < (n + a); i++)
    {
        printf("Nome do funcionario %d: ", i + 1);
        scanf("%s", (cadastro + i)->nome);
        printf("Ano de nascimento do funcionario %d: ", i + 1);
        scanf("%d", &((cadastro + i)->ano_nasc));
        printf("Renda do funcionario %d: ", i + 1);
        scanf("%f", &((cadastro + i)->renda));
    }

    return cadastro;
}

void imprime(Tfunc *cadastro, int zero, int todos_func)
{
    for (int i = zero; i < todos_func; i++)
    {
        printf("Nome: %s\nAno de Nascimento: %d\nRenda: R$%.2f\n", (cadastro + i)->nome, (cadastro + i)->ano_nasc, (cadastro + i)->renda);
        printf("\n");
    }
}
