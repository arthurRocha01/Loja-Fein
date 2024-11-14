#include "view.h"
#include "controller.h"
#include "structs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Definições de cores e estilos para o terminal
#define RESET "\033[0m"
#define BOLD "\033[1m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define BG_BLUE "\033[44m"

static void limpar_terminal()
{
    printf("\033[H\033[J"); // Move o cursor para o topo e limpa o terminal
}

static void imprimir_cabecalho_menu()
{
    printf("\n%s%s++++++++   -- FEIN --   ++++++++%s\n\n", BG_BLUE, WHITE, RESET);
}

static void imprimir_cabecalho_compra()
{
    printf("\n%s%s++++++++   -- FEIN agradece sua compra! --   ++++++++%s\n\n", BG_BLUE, WHITE, RESET);
}

void imprimir_menu()
{
    imprimir_cabecalho_menu();
    printf("%sEscolha uma opção:%s\n", BOLD, RESET);
    printf("%s1.%s Camisas\n", GREEN, RESET);
    printf("%s2.%s Bermudas\n", GREEN, RESET);
    printf("%s3.%s Calçados\n", GREEN, RESET);
    printf("%s4.%s Acessórios\n", GREEN, RESET);
    printf("%s5.%s Sair\n", RED, RESET);
}

void imprimir_opcaos_produto()
{
    imprimir_cabecalho_menu();
    printf("%s1.%s Ver produto\n", GREEN, RESET);
    printf("%s2.%s Voltar\n", YELLOW, RESET);
}

void imprimir_produto(Produto *produto)
{
    printf("\nID: %d", produto->id);
    printf("\nMarca: %s", produto->marca);
    printf("\nNome: %s", produto->nome);
    printf("\nCategoria: %s", produto->categoria);
    printf("\nCor: %s", produto->cor);
    printf("\nTamanho: %s", produto->tamanhos);
    printf("\nPreço: R$ %.2f", produto->valor);
    printf("\nQuantidade em estoque: %d\n", produto->quantidade);
}

void imprimir_compra(const char *mensagem, Produto *produto)
{
    limpar_terminal();
    imprimir_cabecalho_compra();
    printf("\n%s%s%s\n", BOLD, mensagem, RESET);
    printf("+--------------------------------------+\n");
    printf("| %sMarca:%s %s\n", BOLD, RESET, produto->marca);
    printf("| %sNome:%s %s\n", BOLD, RESET, produto->nome);
    printf("| %sCategoria:%s %s\n", BOLD, RESET, produto->categoria);
    printf("| %sCor:%s %s\n", BOLD, RESET, produto->cor);
    printf("| %sTamanho:%s %s\n", BOLD, RESET, produto->tamanhos);
    printf("| %sPreço:%s R$ %.2f\n", BOLD, RESET, produto->valor);
    printf("+--------------------------------------+\n");
    sleep(2);
}

#define LINHA_BORDA "\033[34m" // Azul para borda
#define RESET "\033[0m"         // Reset de cor
#define BOLD "\033[1m"          // Negrito

#define LINHA_BORDA "\033[34m"  // Azul para borda
#define RESET "\033[0m"         // Reset de cor
#define BOLD "\033[1m"          // Negrito
#define ESPACO_COLUNA 30        // Definindo a largura das colunas

#define LINHA_BORDA "\033[34m"  // Azul para borda
#define RESET "\033[0m"         // Reset de cor
#define BOLD "\033[1m"          // Negrito
#define ESPACO_COLUNA 30        // Definindo a largura das colunas

void imprimir_produtos(ListaProdutos *lista)
{
    limpar_terminal();
    imprimir_cabecalho_menu();
    printf("%s%sProdutos disponíveis:%s\n\n", BOLD, BG_BLUE, RESET);

    const int produtos_por_linha = 2; // Dois produtos por linha
    const int colunas = 2; // Duas colunas de produtos

    for (size_t i = 0; i < lista->tamanho; i++)
    {
        Produto *produto = lista->produtos[i];

        // Estilizando a borda de cada produto
        if (i % colunas == 0)
            printf("\n");

        // Estilizando a borda superior
        printf("%s+----------------------------------------+%s", LINHA_BORDA, RESET);

        // Exibe ID e Nome centralizado dentro da mesma coluna, com negrito
        printf("\n%sID: %-3d  Nome: %-25s%s", BOLD, produto->id, produto->nome, RESET);

        // Fechando a borda após as informações
        printf("\n%s+----------------------------------------+%s", LINHA_BORDA, RESET);

        // Adiciona espaçamento entre os dois produtos na mesma linha
        if ((i + 1) % produtos_por_linha == 0 || i == lista->tamanho - 1)
        {
            // Quando a linha estiver cheia, vai para a próxima linha
            printf("\n");
        }
        else
        {
            // Espaço entre as duas colunas, ajustando para garantir centralização
            printf("%*s", ESPACO_COLUNA, ""); // Espaço entre as colunas
        }
    }

    printf("%sEscolha um produto pelo ID ou volte ao menu anterior.%s\n", CYAN, RESET);
}
