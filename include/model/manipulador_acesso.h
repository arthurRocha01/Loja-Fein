#ifndef MANIPULADOR_ACESSO_H
#define MANIPULADOR_ACESSO_H

#include "model/manipulador_loja.h"

int criar_nova_conta_acesso(const char *usuario, const char *senha);
int entrar_conta_acesso(const char *usuario, const char *senha);

#endif