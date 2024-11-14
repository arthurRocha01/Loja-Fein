#include "controller.h"
#include "model.h"
#include "view.h"
#include "structs.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static Produto* selecionar_produto(ListaProdutos *produtos)
{
    int id = pegar_entrada("Digite o ID do produto desejado: ");
    Produto *produto = buscar_produto(id, produtos);
    if (!produto)
    {
        printf("\nProduto não encontrado\n");
    }
    return produto;
}

static void fluxo_compra(ListaProdutos *produtos)
{
    Produto *produto = selecionar_produto(produtos);
    if (produto)
    {
        imprimir_compra("Produto comprado com sucesso!", produto);
    }
}

int selecionar_opcao(ListaProdutos *produtos)
{
    imprimir_opcaos_produto();
    int entradas[] = {1, 2};
    int opcao = pegar_entrada_personalizada("Escolha uma opção: ", entradas, 2);
    if (opcao == 1)
    {
        fluxo_compra(produtos);
    }
}

static void exibir_categoria(const char *categoria)
{
    ListaProdutos produtos = pegar_produtos_por_categoria(categoria);
    imprimir_produtos(&produtos);
    selecionar_opcao(&produtos);
}

static void gerenciar_menu()
{
    int opcao;
    do
    {
        imprimir_menu();
        opcao = pegar_entrada("Digite a opção desejada: ");
        switch (opcao)
        {
            case 1: exibir_categoria("Camisa"); break;
            case 2: exibir_categoria("Bermuda"); break;
            case 3: exibir_categoria("Calçado"); break;
            case 4: exibir_categoria("Acessório"); break;
            case 5: terminar(); break;
            default: printf("Opção inválida. Tente novamente.\n");
        }
    } while (1);
}

void iniciar_loja()
{
    gerenciar_menu();
}