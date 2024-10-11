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
    printf("  ──────────────────Pressione <ENTER> para continuar──────────────────  \n");
    getchar();
    return op;
}

void cadastrar_produtos(void){
    system("clear||cls");
    char nomeprod[22];
    char teor[5];
    char amargor;
    char quant[6];
    printf("\n");
    printf("╔══════════════════════════════-SIG-BEER-══════════════════════════════╗\n");
    printf("║                                                                      ║\n");
    printf("║                          CADASTRAR PRODUTOS                          ║\n");
    printf("║                                                                      ║\n");
    printf("╟──────────────────────────────────────────────────────────────────────╢\n");
    printf("║                                                                      ║\n");
    printf("                      -> NOME DA CERVEJA:");
    scanf("%20s", nomeprod);
    getchar();
    printf("                      -> TEOR ALCOÓLICO(Apenas números):");
    scanf("%3s", teor);
    getchar();
    printf("                       ╔═-AMARGOR-═══════════╗\n");
    printf("                       ║  1. Baixo           ║\n");
    printf("                       ║  2. Médio           ║\n");
    printf("                       ║  3. Alto            ║\n");
    printf("                         Ecolha uma opção: ");
    scanf("%s", &amargor);
    getchar();
    printf("\n                       ╚═════════════════════╝\n");
    printf("                      -> QUANTIDADE EM ML(Apenas números):");
    scanf("%4s", quant);
    getchar();
    printf("║                                                                      ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════╝\n");
    printf("  ──────────────────Pressione <ENTER> para continuar──────────────────  \n");
    getchar();
}


void pesquisar_produtos(void){
    system("clear||cls");
    char id[12];
    printf("\n");
    printf("╔══════════════════════════════-SIG-BEER-══════════════════════════════╗\n");
    printf("║                                                                      ║\n");
    printf("║                          PESQUISAR PRODUTOS                          ║\n");
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
    printf("║                          ATUALIZAR PRODUTOS                          ║\n");
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
    printf("║                           REMOVER PRODUTOS                           ║\n");
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

