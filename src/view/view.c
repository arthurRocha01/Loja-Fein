#include "view/view.h"
#include "controller/controller.h"
#include "model/structs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Definições de cores e estilos para o terminal
#define RESET "\033[0m"
#define BOLD "\033[1m"
#define UNDERLINE "\033[4m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define BG_BLUE "\033[44m"
#define BG_GREEN "\033[42m"
#define LINHA_BORDA "\033[34m"
#define ESPACO_COLUNA 30

static void limpar_terminal() {
    printf("\033[H\033[J");
}

static void imprimir_cabecalho(const char *titulo) {
    printf("\n%s%s+--------------------------------------+%s\n", LINHA_BORDA, BOLD, RESET);
    printf("%s%s|%s%-38s%s|%s\n", LINHA_BORDA, BOLD, RESET, titulo, BOLD, RESET);
    printf("%s%s+--------------------------------------+%s\n\n", LINHA_BORDA, BOLD, RESET);
}

void mostrar_menu() {
    limpar_terminal();
    imprimir_cabecalho("  MENU PRINCIPAL  ");
    printf("%sEscolha uma opção:%s\n\n", BOLD, RESET);
    printf("%s[1]%s Camisas\n", GREEN, RESET);
    printf("%s[2]%s Bermudas\n", GREEN, RESET);
    printf("%s[3]%s Calçados\n", GREEN, RESET);
    printf("%s[4]%s Acessórios\n", GREEN, RESET);
    printf("%s[5]%s Sair\n", RED, RESET);
    printf("\n%sDigite sua escolha: %s", CYAN, RESET);
}

static void mostrar_opcoes(int tipo) {
    imprimir_cabecalho("  OPÇÕES  ");
    if (tipo == 0) printf("%s[1]%s Ver produto\n", GREEN, RESET);
    if (tipo == 1) printf("%s[1]%s Comprar\n", GREEN, RESET);
    printf("%s[2]%s Voltar\n", YELLOW, RESET);
    printf("\n%sEsolha a opção: %s", CYAN, RESET);
}

void mostrar_categoria(ListaProdutos *lista) {
    limpar_terminal();
    imprimir_cabecalho("  PRODUTOS DISPONÍVEIS  ");
    printf("%sEscolha um produto pelo ID ou volte ao menu anterior.%s\n\n", BOLD, RESET);

    const int colunas = 2;
    for (size_t i = 0; i < lista->tamanho; i++) {
        Produto *produto = lista->produtos[i];
        if (i % colunas == 0) printf("\n");
        printf("%s+----------------------------+%s", LINHA_BORDA, RESET);
        printf("\n%sID:%s %-3d  %sNome:%s %-15s", BOLD, RESET, produto->id, BOLD, RESET, produto->nome);
        printf("\n%s+----------------------------+%s", LINHA_BORDA, RESET);
        if ((i + 1) % colunas != 0 && i != lista->tamanho - 1) {
            printf("%*s", ESPACO_COLUNA, "");
        }
    }
    mostrar_opcoes(0);
}

static void congelar_tela(float tempo) {
    sleep(tempo);
}

void mostrar_mensagem(const char* mensagem) {
    printf("%s", CYAN);
    printf("%s", mensagem);
    printf("%s", RESET);
}

void mostrar_produto(Produto *produto) {
    limpar_terminal();
    imprimir_cabecalho("  DETALHES DO PRODUTO  ");
    printf("%sID:%s %d\n", BOLD, RESET, produto->id);
    printf("%sMarca:%s %s\n", BOLD, RESET, produto->marca);
    printf("%sNome:%s %s\n", BOLD, RESET, produto->nome);
    printf("%sCategoria:%s %s\n", BOLD, RESET, produto->categoria);
    printf("%sCor:%s %s\n", BOLD, RESET, produto->cor);
    printf("%sTamanho:%s %s\n", BOLD, RESET, produto->tamanhos);
    printf("%sPreço:%s R$ %.2f\n", BOLD, RESET, produto->valor);
    printf("%sQuantidade em estoque:%s %d\n", BOLD, RESET, produto->quantidade);
    congelar_tela(1.5);
    mostrar_opcoes(1);
}

void mostrar_produto_nao_encontrado() {
    limpar_terminal();
    imprimir_cabecalho("  PRODUTO NÃO ENCONTRADO  ");
    printf("%sNenhum produto encontrado com o ID informado.%s\n", RED, RESET);
    printf("%sPor favor, tente novamente ou escolha outro produto.%s\n", CYAN, RESET);
    congelar_tela(3);
}

void mostrar_compra(Produto *produto) {
    limpar_terminal();
    imprimir_cabecalho("  COMPRA REALIZADA  ");
    printf("%s+--------------------------------------+%s\n", BG_GREEN, RESET);
    printf("| %sMarca:%s %-28s |\n", BOLD, RESET, produto->marca);
    printf("| %sNome:%s %-29s |\n", BOLD, RESET, produto->nome);
    printf("| %sCategoria:%s %-24s |\n", BOLD, RESET, produto->categoria);
    printf("| %sCor:%s %-30s |\n", BOLD, RESET, produto->cor);
    printf("| %sTamanho:%s %-26s |\n", BOLD, RESET, produto->tamanhos);
    printf("| %sPreço:%s R$ %-26.2f |\n", BOLD, RESET, produto->valor);
    printf("%s+--------------------------------------+%s\n\n", BG_GREEN, RESET);
    printf("%sObrigado por comprar com a FEIN!%s\n", CYAN, RESET);
    congelar_tela(2);
}

void mostrar_saida() {
    limpar_terminal();
    imprimir_cabecalho("  SAÍDA  ");
    printf("%s+--------------------------------------+%s\n", BG_BLUE, RESET);
    printf("| %sObrigado por usar a FEIN Store!    %s|\n", BOLD, RESET);
    printf("| %sAté logo!                         %s|\n", BOLD, RESET);
    printf("%s+--------------------------------------+%s\n\n", BG_BLUE, RESET);
    congelar_tela(1);
}