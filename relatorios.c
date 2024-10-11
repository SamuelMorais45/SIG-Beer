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
