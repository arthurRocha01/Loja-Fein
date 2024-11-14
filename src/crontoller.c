#include "controller.h"
#include "model.h"
#include "view.h"
#include "structs.h"
#include <stdio.h>
#include <stdlib.h>

static void gerenciador_opcs_catalago(int opc)
{
    switch (opc)
    {
        case 1: return; break;
        case 2: return; break;
    }
}

static void iniciar_opcs_catalago()
{
    imprimir_opcs_catalago();
    int entrada = pegar_entrada();
    gerenciador_opcs_catalago(entrada);
}

static void carregar_produtos(char *categoria)
{
    ListaProdutos produtos = pegar_produtos_por_categoria(categoria);
    imprimir_produtos(&produtos);
}

static void gerenciador_catalago(int opc)
{
    switch (opc)
    {
        case 1: carregar_produtos("Camisa"); break;
        case 2: carregar_produtos("Bermuda"); break;
        case 3: carregar_produtos("Calçado"); break;
        case 4: carregar_produtos("Acessório"); break;
        case 5: terminar(); break;
    }
}

static void carregar_catalago()
{
    imprimir_menu();
    int entrada = pegar_entrada();
    gerenciador_catalago(entrada);
    iniciar_opcs_catalago();
}

static void iniciar_fluxo()
{
    while (1)
    {
        carregar_catalago();
    }
}

void iniciar_loja()
{
    iniciar_fluxo();
}