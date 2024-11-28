#include "controller/controlador_acesso.h"

typedef void (*AcaoMenu)();

static void sair() {
    mostrar_saida();
    terminar();
}

static ContaLoja* obter_login() {
    char *usuario = obter_entrada("Digite um nome de usúario: ");
    char *senha = obter_entrada("Digite uma senha: ");
    return criar_conta_acesso(usuario, senha);
}

static void entrar_conta() {
    ContaLoja *conta = obter_login();
    if (entrar_conta_acesso(conta->usuario, conta->senha)) {
        mostrar_boas_vindas_usuario(conta->usuario);
        iniciar_controlador_loja();
    } else {
        mostrar_falha_login();
    }
}

static void criar_conta() {
    ContaLoja *conta = obter_login();
    if (criar_nova_conta_acesso(conta->usuario, conta->senha)) {
        mostrar_registro_sucesso(conta->usuario);
    } else {
        mostrar_registro_falha();
    }
}

static void executar_opcao(int opcao) {
    AcaoMenu acoes[] = { criar_conta, entrar_conta, sair };
    acoes[opcao - 1]();
}

static void exibir_menu_acesso() {
    mostrar_menu_acesso();
    int opcao = obter_opcao(3);
    executar_opcao(opcao);
}

void iniciar_controlador_acesso() {
    while (1) {
        exibir_menu_acesso();
    }
}