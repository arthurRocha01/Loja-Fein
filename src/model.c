#include "model.h"
#include "controller.h"
#include "structs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void limpar_terminal()
{
    #if defined(_WIN32) || defined(_WIN64)
    system("cls");
    #else
    system("clear");
    #endif
}

void terminar()
{
    printf("Obrigado por utilizar a Fein Store!\n");
    exit(EXIT_SUCCESS);
}

static FILE* carregar_banco_de_dados(const char *caminho_arquivo)
{
    FILE *arquivo = fopen(caminho_arquivo, "r");
    if (!arquivo)
    {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }
    return arquivo;
}

static int categoria_correspondente(const char *produto, const char *categoria)
{
    char copia[100];
    strncpy(copia, produto, sizeof(copia));
    copia[sizeof(copia) - 1] = '\0';

    char *token = strtok(copia, ",");
    for (int coluna = 1; token != NULL; coluna++)
    {
        if (coluna == 3 & strcmp(token, categoria) == 0)
        {
            return 1;
        }
        token = strtok(NULL, ",");
    }
    return 0;
}

static Produto* criar_novo_produto_e_adcionar_lista(const char *linha, int id, ListaProdutos *lista_produtos)
{
    Produto *novo_produto = criar_produto(linha, id);
    adcionar_produto(lista_produtos, novo_produto);
}

static void processar_produtos_banco_de_dados(ListaProdutos *lista_produtos, FILE *arquivo, const char *categoria)
{
    char linha[100];
    int id = 0;

    while(fgets(linha, sizeof(linha), arquivo))
    {
        if (categoria_correspondente(linha, categoria))
        {
            criar_novo_produto_e_adcionar_lista(linha, id++, lista_produtos);
        }
    }
}

ListaProdutos pegar_produtos_por_categoria(const char *categoria)
{
    FILE *arquivo = carregar_banco_de_dados("data/database.csv");
    ListaProdutos lista_produtos;
    inicializar_lista(&lista_produtos);

    processar_produtos_banco_de_dados(&lista_produtos, arquivo, categoria);
    fclose(arquivo);

    return lista_produtos;
}

int pegar_entrada_personalizada(const char *mensagem, int entradas_validas[], int num_entradas)
{
    int entrada;
    while (1)
    {
        printf("%s ", mensagem);

        if (scanf("%d", &entrada) != 1)
        {
            printf("Entrada inválida. Por favor, insira um número.\n");
            while (getchar() != '\n');
            continue;
        }

        for (int i = 0; i < num_entradas; i++)
        {
            if (entrada == entradas_validas[i])
            {
                return entrada;
            }
        }

        printf("Opção inválida. Tente novamente.\n");
    }
}

int pegar_entrada(const char *mensagem)
{
    int entrada;
    while (1)
    {
        printf("%s ", mensagem);

        if (scanf("%d", &entrada) == 1)
        {
            return entrada;
        }

        printf("Entrada inválida. Por favor, insira um número.\n");
        while (getchar() != '\n');
    }
}

Produto *buscar_produto(int id, ListaProdutos *produtos)
{
    for (size_t i = 0; i < produtos->tamanho; i++)
    {
        Produto *produto = produtos->produtos[i];
        if (produto->id == id)
        {
            return produto;
        }
    }
}