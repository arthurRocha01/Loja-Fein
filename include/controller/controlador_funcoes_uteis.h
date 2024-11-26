#ifndef CONTROLADOR_FUNCOES_UTEIS_H
#define CONTROLADOR_FUNCOES_UTEIS_H

#include "model/model.h"
#include "view/view.h"

int obter_opcao(int num_opcoes);
char *obter_entrada(const char *mensagem);
float obter_entrada_float(const char *mensagem);
int obter_entrada_int(const char *mensagem);

#endif