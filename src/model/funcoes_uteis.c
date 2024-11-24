#include "model/funcoes_uteis.h"

int pegar_inteiro() {
    int entrada;
    while (1) {
        if (scanf("%d", &entrada) == 1) return entrada;
        while (getchar() != '\n');
    }
}

static char *pegar_string() {
    char *string = malloc(100);
    while (1) {
        if (scanf("%99s", string) == 1) return string;
        while (getchar()!= '\n');
    }
}

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