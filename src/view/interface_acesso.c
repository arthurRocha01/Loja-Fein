#include "view/interface_acesso.h"

void mostrar_menu_acesso() {
    limpar_terminal();
    imprimir_cabecalho("  BEM-VINDO À FEIN STORE  ");
    
    printf("%s--------------------------------------------%s\n", LINHA_BORDA, RESET);
    printf("%s        Escolha uma das opções:        %s\n", BOLD, RESET);
    printf("%s--------------------------------------------%s\n", LINHA_BORDA, RESET);
    
    printf("\n%s[1]%s Criar Conta\n", GREEN, RESET);
    printf("%s[2]%s Entrar na Conta\n", GREEN, RESET);
    printf("%s[3]%s Sair\n", RED, RESET);
    
    printf("\n%s--------------------------------------------%s\n", LINHA_BORDA, RESET);
    printf("\n%sDigite sua escolha: %s", CYAN, RESET);
}

void mostrar_boas_vindas_usuario(const char* nome_usuario) {
    limpar_terminal();
    imprimir_cabecalho("  BEM-VINDO(A) À FEIN STORE  ");
    printf("%sOlá, %s%s%s!%s\n", BOLD, CYAN, nome_usuario, RESET, RESET);
    printf("%sEstamos felizes em tê-lo(a) conosco.%s\n\n", GREEN, RESET);

    printf("%sDicas para começar:%s\n", BOLD, RESET);
    printf("- Explore nosso catálogo completo de produtos.\n");
    printf("- Adicione itens ao carrinho e finalize sua compra de forma segura.\n");
    printf("- Aproveite promoções exclusivas disponíveis para você.\n\n");

    printf("%sSe precisar de ajuda, entre em contato com nossa equipe de suporte.%s\n", CYAN, RESET);
    congelar_tela(3);
}

void mostrar_falha_login() {
    limpar_terminal();
    imprimir_cabecalho("  FALHA NO LOGIN  ");
    printf("%sNão foi possível acessar sua conta.%s\n\n", RED, RESET);
    printf("%sPossíveis motivos:%s\n", BOLD, RESET);
    printf("- Usuário ou senha incorretos.\n");
    printf("- Conta não registrada na FEIN Store.\n");
    printf("- Problemas de conexão ou sistema.\n\n");

    printf("%sO que você pode fazer:%s\n", GREEN, RESET);
    printf("- Verifique se suas credenciais estão corretas.\n");
    printf("- Caso tenha esquecido a senha, solicite uma recuperação.\n");
    printf("- Entre em contato com nosso suporte se precisar de ajuda.\n\n");
    congelar_tela(3);
}

void mostrar_registro_sucesso(const char* nome_usuario) {
    limpar_terminal();
    imprimir_cabecalho("  REGISTRO BEM-SUCEDIDO  ");
    printf("%sParabéns, %s%s%s!%s\n", BOLD, CYAN, nome_usuario, RESET, RESET);
    printf("%sSua conta foi criada com sucesso na FEIN Store.%s\n\n", GREEN, RESET);

    printf("%sAgora você pode:%s\n", BOLD, RESET);
    printf("- Acessar sua conta usando o login e senha cadastrados.\n");
    printf("- Explorar e aproveitar nossas ofertas exclusivas.\n\n");
    congelar_tela(3);
}

void mostrar_registro_falha() {
    limpar_terminal();
    imprimir_cabecalho("  FALHA NO REGISTRO  ");
    printf("%sNão foi possível concluir o registro.%s\n\n", RED, RESET);
    printf("%sPossíveis motivos:%s\n", BOLD, RESET);
    printf("- O nome de usuário já está em uso.\n");
    printf("- Senha não atende aos requisitos de segurança.\n");
    printf("- Erro de conexão ou falha no sistema.\n\n");

    printf("%sO que você pode fazer:%s\n", GREEN, RESET);
    printf("- Escolha outro nome de usuário.\n");
    printf("- Garanta que sua senha contém pelo menos 8 caracteres.\n");
    printf("- Tente novamente ou entre em contato com o suporte.\n\n");
    congelar_tela(3);
}


