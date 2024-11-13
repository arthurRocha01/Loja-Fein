#include <stdio.h>
#include <string.h>
#include "view.h"
#include "controller.h"
#include "structs.h"

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

void imprimir_produtos(ListaProdutos *lista)
{
    for (size_t i = 0; i < lista->tamanho; i++)
    {
        printf("%s\n", lista->produtos[i]);
    }
}