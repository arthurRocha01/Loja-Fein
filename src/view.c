#include <stdio.h>
#include <string.h>
#include "view.h"
#include "controller.h"

static void imprimir_cabeçalho()
{
    printf("------------------");
    printf(" FEIN ");
    printf("------------------");
    printf("\n\n");
}

void imprimir_menu()
{
    imprimir_cabeçalho();
    printf("1. Camisas\n");
    printf("2. Bermudas\n");
    printf("3. Calçados\n");
    printf("4. Acessórios\n");
    printf("Qual a opção desejada? ");
}

void imprimir_produto(char *produto)
{
    char *campo = strtok(produto, ",");
    while (campo != NULL)
    {
        printf("%s ", campo);
        campo = strtok(NULL, ",");
    }
    printf("\n");
}