/*
╔═════════════════════════════════════════════════════════════════╗
║                M Ó D U L O  R E L A T Ó R I O S                 ║
╚═════════════════════════════════════════════════════════════════╝
*/

#include <stdio.h>
#include <stdlib.h>
#include "relatorios.h"

void modulo_relatorios(void) {
    char opcao;
    do {
        opcao = menu_relatorios();
        switch (opcao) {
            case '1': produtos_amargor();
            break;
            case '2': packs_produto();
            break;
            case '3': assinaturas_cliente();
            break;
            case '4': assinaturas_pack();
            break;
        }
    } while (opcao != '0');
}

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
    printf("║                     4. ASSINATURAS POR PACK                          ║\n");
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

void packs_produto(void){
    system("clear||cls");
    char id[12];
    printf("\n");
    printf("╔══════════════════════════════-SIG-BEER-══════════════════════════════╗\n");
    printf("║                                                                      ║\n");
    printf("║                          PACKS POR PRODUTO                           ║\n");
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

void assinaturas_cliente(void){
    char cpf[16];
    system("clear||cls");
    printf("\n");
    printf("╔══════════════════════════════-SIG-BEER-══════════════════════════════╗\n");
    printf("║                                                                      ║\n");
    printf("║                        ASSINATURAS POR CLIENTE                       ║\n");
    printf("║                                                                      ║\n");
    printf("╟──────────────────────────────────────────────────────────────────────╢\n");
    printf("║                                                                      ║\n");
    printf("                    -> CPF (formato xxx.xxx.xxx-xx): ");
    scanf("%14s", cpf);
    getchar();
    printf("║                                                                      ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════╝\n");
    printf("  ──────────────────Pressione <ENTER> para continuar──────────────────  \n");
    getchar();
}

void assinaturas_pack(void){
    char idpack[12];
    system("clear||cls");
    printf("\n");
    printf("╔══════════════════════════════-SIG-BEER-══════════════════════════════╗\n");
    printf("║                                                                      ║\n");
    printf("║                         ASSINATURAS POR PACK                         ║\n");
    printf("║                                                                      ║\n");
    printf("╟──────────────────────────────────────────────────────────────────────╢\n");
    printf("║                                                                      ║\n");
    printf("                       -> INSIRA O ID DO PACK: ");
    scanf("%10s", idpack);
    getchar();
    printf("║                                                                      ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════╝\n");
    printf("  ──────────────────Pressione <ENTER> para continuar──────────────────  \n");
    getchar();
}

