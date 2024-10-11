/*
╔═════════════════════════════════════════════════════════════════╗
║                M Ó D U L O  R E L A T Ó R I O S                 ║
╚═════════════════════════════════════════════════════════════════╝
*/

#include <stdio.h>
#include <stdlib.h>
#include "relatorios.h"

char menu_relatorios(void){
    char op;
    system("clear||cls");
    printf("\n");
    printf("╔══════════════════════════════-SIG-BEER-══════════════════════════════╗\n");
    printf("║                                                                      ║\n");
    printf("║                           MENU RELATÓRIOS                            ║\n");
    printf("║                                                                      ║\n");
    printf("╟──────────────────────────────────────────────────────────────────────╢\n");
    printf("║                                                                      ║\n");
    printf("║                     1. PRODUTOS POR AMARGOR                          ║\n");
    printf("║                     2. PACKS POR PRODUTO                             ║\n");
    printf("║                     3. ASSINATURAS POR CLIENTE                       ║\n");
    printf("║                     4. ASSINATURA POR PACKS                          ║\n");
    printf("║                     5. SOMA ASSINATURAS POR CLIENTE                  ║\n");
    printf("║                     0. VOLTAR                                        ║\n");
    printf("║                                                                      ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════╝\n");
    printf("                         Escolha uma opção: ");
    scanf("%c", &op);
    getchar();
    return op;
}

void produtos_amargor(void){
    system("clear||cls");
    char amargor;
    printf("\n");
    printf("╔══════════════════════════════-SIG-BEER-══════════════════════════════╗\n");
    printf("║                                                                      ║\n");
    printf("║                         PRODUTOS POR AMARGOR                         ║\n");
    printf("║                                                                      ║\n");
    printf("╟──────────────────────────────────────────────────────────────────────╢\n");
    printf("║                                                                      ║\n");
    printf("                        ╔═-AMARGOR-═══════════╗\n");
    printf("                        ║  1. Baixo           ║\n");
    printf("                        ║  2. Médio           ║\n");
    printf("                        ║  3. Alto            ║\n");
    printf("                          Ecolha uma opção: ");
    scanf("%s", &amargor);
    getchar();
    printf("\n                        ╚═════════════════════╝\n");
    printf("║                                                                      ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════╝\n");
    printf("  ──────────────────Pressione <ENTER> para continuar──────────────────  \n");
    getchar();
}
