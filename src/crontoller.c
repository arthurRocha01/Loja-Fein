#include "controller.h"
#include "model.h"
#include "view.h"
#include "structs.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef enum {
    MENU,
    VISUALIZAR_PRODUTOS
} Sessao;

Sessao sessao_atual = MENU;
ListaProdutos produtos;

void static gerenciar_menu();
void static escolher_produto();

static void alternar_sessao(Sessao nova_sessao) {
    sessao_atual = nova_sessao;
    if (nova_sessao == MENU) gerenciar_menu();
    if (nova_sessao == VISUALIZAR_PRODUTOS) escolher_produto();
}

static void exibir_produto(Produto *produto)
{
    if (!produto) {
        printf("Nenhum produto encontrado.\n");
        return;
    }
    imprimir_produto(produto);
}

static Produto* selecionar_produto() {
    int id = pegar_entrada("Digite o ID do produto desejado: ");
    Produto *produto = buscar_produto(id, &produtos);
    exibir_produto(produto);
    if (produto) {
        int entradas_validas[] = {1, 2};
        int opc = pegar_entrada_personalizada("1. Comprar\n2. Voltar\nEscolha uma opção: ", entradas_validas, sizeof(entradas_validas));
        if (opc == 1) printf("Produto comprado com sucesso!\n");
        if (opc == 2) alternar_sessao(MENU);
    }
}

static void visualizar_produtos() {
    imprimir_produtos(&produtos);
    int entradas_validas[] = {1, 2};
    int opcao = pegar_entrada_personalizada("1. Selecionar Produto\n2. Voltar ao Menu\nEscolha: ", entradas_validas, sizeof(entradas_validas));
    if (opcao == 1) selecionar_produto();
    else alternar_sessao(MENU);
}

static void escolher_produto() {
    imprimir_opcaos_produto();
    visualizar_produtos();
}

static void selecionar_categoria(const char *categoria)
{
    produtos = pegar_produtos_por_categoria(categoria);
    imprimir_produtos(&produtos);
    if (produtos.tamanho == 0) alternar_sessao(MENU);
    else alternar_sessao(VISUALIZAR_PRODUTOS);
}

static void gerenciar_menu()
{
    imprimir_menu();
    int opcao = pegar_entrada("Digite a opção desejada: ");
    switch (opcao) {
        case 1: selecionar_categoria("Camisa"); break;
        case 2: selecionar_categoria("Bermuda"); break;
        case 3: selecionar_categoria("Calçado"); break;
        case 4: selecionar_categoria("Acessório"); break;
        case 5: terminar(); break;
        default: printf("Opção inválida. Tente novamente.\n");
    }
}

void iniciar_sessao()
{
    alternar_sessao(MENU);
}