#include "model/manipulador_acesso.h"

static int manipular_arquivo(const char *modo, int (*operacao)(FILE*, const char*, const char*), const char *usuario, const char *senha) {
    FILE *arquivo = fopen("data/acesso_contas.csv", modo);
    if (!arquivo) {
        perror("Erro ao abrir o arquivo");
        return 0;
    }
    int resultado = operacao(arquivo, usuario, senha);
    fclose(arquivo);
    return resultado;
}

static int salvar_nova_conta(FILE *arquivo, const char *usuario, const char *senha) {
    return fprintf(arquivo, "%s,%s\n", usuario, senha) > 0;
}

static int verificar_login(FILE *arquivo, const char *usuario, const char *senha) {
    char buffer[100];
    while (fgets(buffer, sizeof(buffer), arquivo)) {
        char *usuario_token = strtok(buffer, ",");
        usuario_token[strcspn(usuario_token, "\r\n")] = '\0';

        if (strcmp(usuario_token, usuario) == 0) {
            char *senha_token = strtok(NULL, ",");
            senha_token[strcspn(senha_token, "\r\n")] = '\0';
            return strcmp(senha_token, senha) == 0;
        }
    }
    return 0;
}

int criar_nova_conta_acesso(const char *login, const char *senha) {
    return manipular_arquivo("a", salvar_nova_conta, login, senha);
}

int entrar_conta_acesso(const char *login, const char *senha) {
    return manipular_arquivo("r", verificar_login, login, senha);
}