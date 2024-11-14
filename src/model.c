#include "model.h"
#include "controller.h"
#include "structs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void terminar()
{
    printf("Obrigado por utilizar a Fein Store!\n");
    exit(1);
}

void limpar_terminal()
{
    #if defined(_WIN32) || defined(_WIN64)
    system("cls");
    #else
    system("clear");
    #endif
}

static FILE* ler_arquivo(char *caminho_arquivo)
{
    FILE *arquivo = fopen(caminho_arquivo, "r");
    if (arquivo == NULL)
    {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }
    return arquivo;
}

static int categoria_correspondente(char *produto, char *categoria)
{
    char copia_produto[100];
    strncpy(copia_produto, produto, sizeof(copia_produto));
    char *campo = strtok(copia_produto, ",");
    int coluna = 1;

    while (campo != NULL)
    {
        if (coluna == 3)
        {
            return (strcmp(campo, categoria) == 0); // Retorna true se for a categoria correspondente.
        }
        campo = strtok(NULL, ",");
        coluna++;
    }
    return 1;
}

static Produto* criar_novo_produto_e_adcionar(char *info, ListaProdutos *lista_produtos)
{
    Produto *produto = criar_produto(info);
    adcionar_produto(lista_produtos, produto);
}

static void processar_linha_arquivo(ListaProdutos *lista_produtos, FILE *arquivo, char *categoria)
{
    char info[100];
    while(fgets(info, sizeof(info), arquivo))
    {
        if (categoria_correspondente(info, categoria))
        {
            criar_novo_produto_e_adcionar(info, lista_produtos);
        }
    }
}

ListaProdutos pegar_produtos_por_categoria(char *categoria)
{
    ListaProdutos lista_produtos;
    FILE *arquivo = ler_arquivo("data/database.csv");
    inicializar_lista(&lista_produtos);
    processar_linha_arquivo(&lista_produtos, arquivo, categoria);
    fclose(arquivo);
    return lista_produtos;
}

int pegar_entrada()
{
    int entrada;
    do
    {
        if (scanf("%d", &entrada) == 1)
        {
            return entrada;
        }
        else
        {
            printf("Entrada inválida. Tente novamente.\n");
            printf("Qual a opção desejada? ");
            while(getchar() != '\n');
        }
    } while (1);
}

static void verficar_forma_pagamento()
{
    return;
}

void efetuar_compra()
{
    verficar_forma_pagamento();
}