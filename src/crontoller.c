#include <stdio.h>
#include "controller.h"
#include "model.h"
#include "view.h"
#include "structs.h"

static int manipulador_entrada()
{
    int entrada;
    pegar_entrada(&entrada);
    return entrada;
}

static void exibir_produtos(char *categoria)
{
    ListaProdutos produtos = pegar_produtos(categoria);
    imprimir_produtos(&produtos);
}

static void menu(int opc)
{
    switch (opc)
    {
    case 1:
        exibir_produtos("Camisa");
        break;

    case 2:
        exibir_produtos("Bermuda");
        break;

    case 3:
        exibir_produtos("Calçado");
        break;

    case 4:
        exibir_produtos("Acessório");
        break;
    
    default:
        printf("Opção inválida\n");
        break;
    }
}

static void manipulador_fluxo()
{
    imprimir_menu();
    int opc = manipulador_entrada();
    menu(opc);
}

void iniciar_loja()
{
    manipulador_fluxo();
}