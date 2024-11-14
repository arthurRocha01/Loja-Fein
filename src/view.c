#include "view.h"
#include "controller.h"
#include "structs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static void limpar_terminal()
{
    #if defined(_WIN32) || defined(_WIN64)
    system("cls");
    #else
    system("clear");
    #endif
}

static void imprimir_cabeçalho()
{
    printf("\n\n");
    printf("++++++++   -- FEIN --   ++++++++");
    printf("\n\n");
}

void imprimir_menu()
{
    imprimir_cabeçalho();
    printf("Escolha um opção:\n");
    printf("1. Camisas\n");
    printf("2. Bermudas\n");
    printf("3. Calçados\n");
    printf("4. Acessórios\n");
    printf("5. Sair\n");
    printf("Qual a opção desejada? ");
}

void imprimir_opcs_catalago()
{
    imprimir_cabeçalho();
    printf("1. Comprar\n");
    printf("2. Voltar\n");
    printf("Qual a opção desejada? ");
}

void imprimir_produtos(ListaProdutos *lista)
{
    limpar_terminal();
    for (size_t i = 0; i < lista->tamanho; i++)
    {
        Produto *produto = lista->produtos[i];
        printf("\nID: %li", i);
        printf("\nMarca: %s", produto->marca);
        printf("\nNome: %s", produto->nome);
        printf("\nCategoria: %s", produto->categoria);
        printf("\nCor: %s", produto->cor);
        printf("\nTamanho: %s", produto->tamanhos);
        printf("\nPreço: R$ %.2f", produto->valor);
        printf("\nQuantidade em estoque: %d\n", produto->quantidade);
        if (i+1 < lista->tamanho) printf("-----------------------------\n");
    }
    // limpar_terminal();
}