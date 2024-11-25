#include "model/modelo_funcoes_uteis.h"

int pegar_inteiro() {
    int entrada;
    while (1) {
        if (scanf("%d", &entrada) == 1) return entrada;
        while (getchar() != '\n');
    }
}

float pegar_float() {
    float entrada;
    while (1) {
        if (scanf("%f", &entrada) == 1) return entrada;
        while (getchar() != '\n');
    }
}

char *pegar_string() {
    char *string = malloc(100);
    while (1) {
        if (scanf("%99s", string) == 1) return string;
        while (getchar()!= '\n');
    }
}