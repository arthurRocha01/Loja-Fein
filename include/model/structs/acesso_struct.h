#ifndef ACESSO_STRUCT_H
#define ACESSO_STRUCT_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct {
    char *nome;
    char *sobrenome;
    char *email;
    char *telefone;
} Cliente;

typedef struct {
    char *usuario;
    char *senha;
} ContaLoja;

ContaLoja *criar_conta_acesso(const char *usuario, const char *senha);
void liberar_conta_acesso(ContaLoja *conta_acesso);

#endif