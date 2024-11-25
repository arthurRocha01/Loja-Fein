#ifndef VIEW_UTILS_H
#define VIEW_UTILS_H

#include <stdio.h>
#include <unistd.h>
#include "model/manipulador_struct.h"
#include "view/cores.h"

void limpar_terminal();
void congelar_tela(float tempo);
void imprimir_cabecalho(const char *titulo);
void mostrar_opcoes(int tipo);
void mostrar_mensagem(const char* mensagem);
void mostrar_saida();



#endif