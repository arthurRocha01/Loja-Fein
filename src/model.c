#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "model.h"
#include "controller.h"

// Protótipos
static FILE* ler_arquivo(const char *caminho_arquivo);
static int verificar_categoria(char *produto, const char *categoria);
static void imprimir_produto(char *produto);

// Funções model
static FILE* ler_arquivo(const char *caminho_arquivo)
{
    FILE *arquivo = fopen(caminho_arquivo, "r");
    if (arquivo == NULL)
    {
        perror("Erro ao abrir o arquivo");
    }
    return arquivo;
}

int pegar_produtos(const char *categoria)
{
    FILE *arquivo = ler_arquivo("data/database.csv");
    if (arquivo == NULL)
    {
        return 1;
    }

    int tamanho_produto = 100;
    char produto[tamanho_produto];
    while(fgets(produto, tamanho_produto, arquivo))
    {
        if (verificar_categoria(produto, categoria))
        {
            imprimir_produto(produto);
        }
    }
    fclose(arquivo);
    return 0;
}

static int verificar_categoria(char *produto, const char *categoria)
{
    char copia_produto[100];
    strncpy(copia_produto, produto, sizeof(copia_produto));

    char *campo = strtok(copia_produto, ",");
    int coluna = 1;

    while (campo != NULL)
    {
        if (coluna == 3)
        {
            return (strcmp(campo, categoria) == 0);
        }
        campo = strtok(NULL, ",");
        coluna++;
    }
}