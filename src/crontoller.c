#include "controller.h"
#include "model.h"
#include "view.h"
#include "structs.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef enum {
    MENU,
    PRODUTO,
    CAIXA
} Sessao;

Sessao sessao_atual = MENU;
ListaProdutos *produtos;

void static gerenciar_menu();
void static gerenciar_caixa(Produto *produto);
void static escolher_produto();

static void alternar_sessao(Sessao nova_sessao, Produto *produto) {
    sessao_atual = nova_sessao;
    if (nova_sessao == MENU) gerenciar_menu();
    if (nova_sessao == PRODUTO) escolher_produto();
    if (nova_sessao == CAIXA) gerenciar_caixa(produto);
}

static void efetuar_compra(Produto *produto) {
    comprar_produto(produto);
    printf("Produto comprado com sucesso!\n");
    mostrar_compra(produto);
    alternar_sessao(MENU, NULL);
}

static void gerenciar_caixa(Produto *produto) {
    if (produto) {
        int opc = pegar_entrada();
        if (opc == 1) efetuar_compra(produto);
        if (opc == 2) alternar_sessao(MENU, NULL);
    }
}

static void exibir_produto(Produto *produto) {
    if (!produto) {
        mostrar_mensagem("Nenhum produto encontrado.\n");
        return;
    }
    mostrar_produto(produto);
}

static Produto* selecionar_produto() {
    mostrar_mensagem("Digite o ID do produto escolhido: ");
    int id = pegar_entrada();
    Produto *produto = buscar_produto(id, produtos);
    exibir_produto(produto);
    alternar_sessao(CAIXA, produto);
}

static void escolher_produto() {
    int opcao = pegar_entrada();
    if (opcao == 1) selecionar_produto();
    else alternar_sessao(MENU, NULL);
}

static void selecionar_categoria(const char *categoria) {
    produtos = pegar_produtos_por_categoria(categoria);
    mostrar_categoria(produtos);
    alternar_sessao(PRODUTO, NULL);
}

static void gerenciar_menu() {
    mostrar_menu();
    int opcao = pegar_entrada();
    switch (opcao) {
        case 1: selecionar_categoria("Camisa"); break;
        case 2: selecionar_categoria("Bermuda"); break;
        case 3: selecionar_categoria("Calçado"); break;
        case 4: selecionar_categoria("Acessório"); break;
        case 5: terminar(); break;
        default: alternar_sessao(MENU, NULL);
    }
}

void iniciar() {
    inicializar_sgd();
    alternar_sessao(MENU, NULL);
}