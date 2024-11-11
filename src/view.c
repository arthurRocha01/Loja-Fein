#include <stdio.h>
#include <string.h>
#include "view.h"
#include "controller.h"

void inicializar_loja()
{
    printf("------------------");
    printf(" LOJA VIRTUAL ");
    printf("------------------\n");
}

void visualizar_produtos(const char *categoria)
{
    pesquisar_produtos(categoria);
}

void renderizar_produto(char *produto)
{
    char *campo = strtok(produto, ",");
    while (campo != NULL)
    {
        printf("%s ", campo);
        campo = strtok(NULL, ",");
    }
    printf("\n");
}