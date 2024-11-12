#include <stdio.h>
#include "controller.h"
#include "model.h"
#include "view.h"

static int manipulador_entrada()
{
    int entrada;
    pegar_entrada(&entrada);
    return entrada;
}

static void exibir_produtos(char *categoria)
{
    // produtos (linked list)
}

static void menu(int opc)
{
    switch (opc)
    {
    case 1:
        // camisas
        break;

    case 2:
    // bermudas
    break;

    case 3:
        // calçados
        break;

    case 4:
        // acessórios
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
}

void iniciar_loja()
{
    manipulador_fluxo();
}