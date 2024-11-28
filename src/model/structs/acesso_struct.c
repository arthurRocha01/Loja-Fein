#include "model/structs/acesso_struct.h"

ContaLoja *criar_conta_acesso(const char *usuario, const char *senha) {
    ContaLoja *conta_acesso = malloc(sizeof(ContaLoja));
    conta_acesso->usuario = strdup(usuario);
    conta_acesso->senha = strdup(senha);
    return conta_acesso;
}

void liberar_conta_acesso(ContaLoja *conta_acesso) {
    free(conta_acesso->usuario);
    free(conta_acesso->senha);
    free(conta_acesso);
}