#ifndef VIEW_UTILS_H
#define VIEW_UTILS_H

#include "view/cores.h"
#include <stdio.h>
#include <unistd.h>

void limpar_terminal();
void imprimir_cabecalho(const char *titulo);
void mostrar_opcoes(int tipo);
void congelar_tela(float tempo);

#endif