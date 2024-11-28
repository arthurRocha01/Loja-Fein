#ifndef INTERFACE_ACESSO_H
#define INTERFACE_ACESSO_H

#include "view/view_utils.h"

void mostrar_menu_acesso();
void mostrar_boas_vindas_usuario(const char* nome_usuario);
void mostrar_falha_login();
void mostrar_registro_sucesso(const char* nome_usuario);
void mostrar_registro_falha();


#endif