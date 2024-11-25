#include "controller/controlador_funcoes_uteis.h"

int obter_opcao(int num_opcoes) {
    int opcao;
    while (1) {
        opcao = pegar_inteiro();
        if (opcao > 0 && opcao <= num_opcoes) {
            return opcao;
        }
        mostrar_mensagem("\nOpção inválida. Tentenovamente.\nEscolha a opção desejada: ");
    }
}

char *obter_entrada(const char *mensagem) {
    char *entrada;
    while (1) {
        mostrar_mensagem(mensagem);
        entrada = pegar_string();
        if (entrada) return entrada;
        mostrar_mensagem("\nOpção inválida. Tentenovamente.\nEscolha a opção desejada: ");
    }
}

float obter_entrada_float(const char *mensagem) {
    float entrada;
    while (1) {
    mostrar_mensagem(mensagem);
    entrada = pegar_float();
    if (entrada) return entrada;
    mostrar_mensagem("\nOpção inválida. Tentenovamente.\nEscolha a opção desejada: ");

    }
}