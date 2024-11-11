#include <stdio.h>
#include "controller.h"
#include "model.h"
#include "view.h"

int menu(int opc)
{
    switch (opc)
    {
    case 1:
        visualizar_produtos("Camisa");
        break;

    case 2:
        visualizar_produtos("Bermuda");
        break;

    case 3:
        visualizar_produtos("Calçados");
        break;

    case 4:
    visualizar_produtos("Acessório");
        break;

    default:
        printf("Opção inválida!\n");
        break;
    }
}

int pesquisar_produtos(const char *categoria)
{
    pegar_produtos(categoria);
}

int imprimir_produto(const char *produto)
{
    renderizar_produto(produto);
}