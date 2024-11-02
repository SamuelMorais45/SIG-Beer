/*
╔═════════════════════════════════════════════════════════════════╗
║                  M Ó D U L O  P R O D U T O S                   ║
╚═════════════════════════════════════════════════════════════════╝
*/

#include <stdio.h>
#include <stdlib.h>
#include "produtos.h"

void modulo_produtos(void) {
    char opcao;
    do {
        opcao = menu_produtos();
        switch (opcao) {
            case '1': cadastrar_produtos();
            break;
            case '2': pesquisar_produtos();
            break;
            case '3': atualizar_produtos();
            break;
            case '4': remover_produtos();
            break;
        }
    } while (opcao != '0');
}

char menu_produtos(void){
    char op;
    system("clear||cls");
    printf("\n");
    printf("╔══════════════════════════════-SIG-BEER-══════════════════════════════╗\n");
    printf("║                                                                      ║\n");
    printf("║                            MENU PRODUTOS                             ║\n");
    printf("║                                                                      ║\n");
    printf("╟──────────────────────────────────────────────────────────────────────╢\n");
    printf("║                                                                      ║\n");
    printf("║                     1. CADASTRAR NOVO PRODUTO                        ║\n");
    printf("║                     2. PESQUISAR DADOS DO PRODUTO                    ║\n");
    printf("║                     3. ATUALIZAR DADOS DO PRODUTO                    ║\n");
    printf("║                     4. REMOVER PRODUTO DO SISTEMA                    ║\n");
    printf("║                     0. VOLTAR                                        ║\n");
    printf("║                                                                      ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════╝\n");
    printf("                         Escolha uma opção: ");
    scanf("%c", &op);
    getchar();
    return op;
}

void cadastrar_produtos(void) {
    system("clear||cls");
    char nomeprod[22];
    char teor[5];
    char amargor;
    char quant[6];

    printf("\n");
    printf("╔══════════════════════════════-SIG-BEER-══════════════════════════════╗\n");
    printf("║                                                                      ║\n");
    printf("║                          CADASTRAR PRODUTO                           ║\n");
    printf("║                                                                      ║\n");
    printf("╟──────────────────────────────────────────────────────────────────────╢\n");
    printf("║                                                                      ║\n");

    // Nome da cerveja
    printf("                      -> NOME DA CERVEJA: ");
    scanf("%20s", nomeprod);
    getchar();

    // Teor alcoólico
    printf("                      -> TEOR ALCOÓLICO (Apenas números): ");
    scanf("%4s", teor);
    getchar();
    
    // Verifica se o teor alcoólico é um número
    for (int i = 0; i < strlen(teor); i++) {
        if (!isdigit(teor[i])) {
            printf("Por favor, insira apenas números para o teor alcoólico.\n");
            return;
        }
    }

    // Opções de amargor
    printf("                       ╔═-AMARGOR-═══════════╗\n");
    printf("                       ║  1. Baixo           ║\n");
    printf("                       ║  2. Médio           ║\n");
    printf("                       ║  3. Alto            ║\n");
    printf("                         Escolha uma opção: ");
    scanf(" %c", &amargor);
    getchar();

    // Verifica se a escolha de amargor é válida
    if (amargor < '1' || amargor > '3') {
        printf("Opção de amargor inválida. Por favor, escolha 1, 2 ou 3.\n");
        return;
    }

    // Quantidade em ml
    printf("                      -> QUANTIDADE EM ML (Apenas números): ");
    scanf("%5s", quant);
    getchar();
    
    // Verifica se a quantidade é um número
    for (int i = 0; i < strlen(quant); i++) {
        if (!isdigit(quant[i])) {
            printf("Por favor, insira apenas números para a quantidade.\n");
            return;
        }
    }

    printf("║                                                                      ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════╝\n");

    // Confirmação do cadastro
    printf("Produto cadastrado com sucesso:\n");
    printf("Nome: %s\n", nomeprod);
    printf("Teor Alcoólico: %s%%\n", teor);
    printf("Amargor: %c\n", amargor);
    printf("Quantidade: %s ml\n", quant);
    
    printf("  ──────────────────Pressione <ENTER> para continuar──────────────────  \n");
    getchar();
}


void pesquisar_produtos(void){
    system("clear||cls");
    char id[12];
    printf("\n");
    printf("╔══════════════════════════════-SIG-BEER-══════════════════════════════╗\n");
    printf("║                                                                      ║\n");
    printf("║                          PESQUISAR PRODUTO                           ║\n");
    printf("║                                                                      ║\n");
    printf("╟──────────────────────────────────────────────────────────────────────╢\n");
    printf("║                                                                      ║\n");
    printf("                      -> INSIRA O ID DO PRODUTO:");
    scanf("%10s", id);
    getchar();
    printf("║                                                                      ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════╝\n");
    printf("  ──────────────────Pressione <ENTER> para continuar──────────────────  \n");
    getchar();
}


void atualizar_produtos(void){
    system("clear||cls");
    char id[12];
    printf("\n");
    printf("╔══════════════════════════════-SIG-BEER-══════════════════════════════╗\n");
    printf("║                                                                      ║\n");
    printf("║                          ATUALIZAR PRODUTO                           ║\n");
    printf("║                                                                      ║\n");
    printf("╟──────────────────────────────────────────────────────────────────────╢\n");
    printf("║                                                                      ║\n");
    printf("                      -> INSIRA O ID DO PRODUTO:");
    scanf("%10s", id);
    getchar();
    printf("║                                                                      ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════╝\n");
    printf("  ──────────────────Pressione <ENTER> para continuar──────────────────  \n");
    getchar();
}

void remover_produtos(void){
    system("clear||cls");
    char id[12];
    printf("\n");
    printf("╔══════════════════════════════-SIG-BEER-══════════════════════════════╗\n");
    printf("║                                                                      ║\n");
    printf("║                           REMOVER PRODUTO                            ║\n");
    printf("║                                                                      ║\n");
    printf("╟──────────────────────────────────────────────────────────────────────╢\n");
    printf("║                                                                      ║\n");
    printf("                      -> INSIRA O ID DO PRODUTO:");
    scanf("%10s", id);
    getchar();
    printf("║                                                                      ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════╝\n");
    printf("  ──────────────────Pressione <ENTER> para continuar──────────────────  \n");
    getchar();
}

