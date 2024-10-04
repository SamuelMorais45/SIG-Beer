/*
╔══════════════════════════════════════════════════════════════╗
║                  M Ó D U L O  P L A N O S                    ║
╚══════════════════════════════════════════════════════════════╝
*/

#include <stdio.h>
#include <stdlib.h>
#include "planos.h"

char menu_planos(void){
    char op;
    system("clear||cls");
    printf("\n");
    printf("╔══════════════════════════════-SIG-BEER-══════════════════════════════╗\n");
    printf("║                                                                      ║\n");
    printf("║                              MENU PLANOS                             ║\n");
    printf("║                                                                      ║\n");
    printf("╟──────────────────────────────────────────────────────────────────────╢\n");
    printf("║                                                                      ║\n");
    printf("║                       1. CADASTRAR NOVO PLANO                        ║\n");
    printf("║                       2. PESQUISAR DADOS DO PLANO                    ║\n");
    printf("║                       3. ATUALIZAR DADOS DO PLANO                    ║\n");
    printf("║                       4. REMOVER PLANO DO SISTEMA                    ║\n");
    printf("║                       0. VOLTAR                                      ║\n");
    printf("║                                                                      ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════╝\n");
    printf("                         Escolha uma opção: ");
    scanf("%c", &op);
    getchar();
    printf("  ──────────────────Pressione <ENTER> para continuar──────────────────  \n");
    getchar();
    return op;
}

void cadastrar_plano(void){
    system("clear||cls");
    printf("\n");
    printf("╔══════════════════════════════-SIG-BEER-══════════════════════════════╗\n");
    printf("║                                                                      ║\n");
    printf("║                           CADASTRAR PLANO                            ║\n");
    printf("║                                                                      ║\n");
    printf("╟──────────────────────────────────────────────────────────────────────╢\n");
    printf("║                                                                      ║\n");
    printf("║                        -> ID DOS PRODUTOS:                           ║\n");
    printf("║                        -> NOME DO PLANO:                             ║\n");
    printf("║                        -> VALOR DO PLANO:                            ║\n");
    printf("║                        -> PERIODO DE ENTREGA (OPÇÕES):               ║\n");
    printf("║                                                                      ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════╝\n");
    printf("  ──────────────────Pressione <ENTER> para continuar──────────────────  \n");
    getchar();
}

void pesquisar_plano(void){
    system("clear||cls");
    printf("\n");
    printf("╔══════════════════════════════-SIG-BEER-══════════════════════════════╗\n");
    printf("║                                                                      ║\n");
    printf("║                            PESQUISAR PLANO                           ║\n");
    printf("║                                                                      ║\n");
    printf("╟──────────────────────────────────────────────────────────────────────╢\n");
    printf("║                                                                      ║\n");
    printf("║                       -> INSIRA O ID DO PLANO:                       ║\n");
    printf("║                                                                      ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════╝\n");
    printf("  ──────────────────Pressione <ENTER> para continuar──────────────────  \n");
    getchar();
}

void atualizar_plano(void){
    system("clear||cls");
    printf("\n");
    printf("╔══════════════════════════════-SIG-BEER-══════════════════════════════╗\n");
    printf("║                                                                      ║\n");
    printf("║                            ATUALIZAR PLANO                           ║\n");
    printf("║                                                                      ║\n");
    printf("╟──────────────────────────────────────────────────────────────────────╢\n");
    printf("║                                                                      ║\n");
    printf("║                       -> INSIRA O ID DO PLANO:                       ║\n");
    printf("║                                                                      ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════╝\n");
    printf("  ──────────────────Pressione <ENTER> para continuar──────────────────  \n");
    getchar();
}
