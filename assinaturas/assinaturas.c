/*
╔═════════════════════════════════════════════════════════════════╗
║              M Ó D U L O  A S S I N A T U R A S                 ║
╚═════════════════════════════════════════════════════════════════╝
*/

#include <stdio.h>
#include <stdlib.h>
#include "assinaturas.h"

void modulo_assinaturas(void) {
    char opcao;
    do {
        opcao = menu_assinaturas();
        switch (opcao) {
            case '1': cadastrar_assinaturas();
            break;
            case '2': pesquisar_assinaturas();
            break;
            case '3': cancelar_assinaturas();
            break;
        }
    } while (opcao != '0');
}


char menu_assinaturas(void){
    char op;
    system("clear||cls");
    printf("\n");
    printf("╔══════════════════════════════-SIG-BEER-══════════════════════════════╗\n");
    printf("║                                                                      ║\n");
    printf("║                           MENU ASSINATURAS                           ║\n");
    printf("║                                                                      ║\n");
    printf("╟──────────────────────────────────────────────────────────────────────╢\n");
    printf("║                                                                      ║\n");
    printf("║                     1. CADASTRAR NOVA ASSINATURA                     ║\n");
    printf("║                     2. PESQUISAR DADOS DE UMA ASSINATURA             ║\n");
    printf("║                     3. CANCELAR UMA ASSINATURA                       ║\n");
    printf("║                     0. VOLTAR                                        ║\n");
    printf("║                                                                      ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════╝\n");
    printf("                         Escolha uma opção: ");
    scanf("%c", &op);
    getchar();
    return op;
}

void cadastrar_assinaturas(void){
    char cpf[16];
    system("clear||cls");
    printf("\n");
    printf("╔══════════════════════════════-SIG-BEER-══════════════════════════════╗\n");
    printf("║                                                                      ║\n");
    printf("║                         CADASTRAR ASSINATURA                         ║\n");
    printf("║                                                                      ║\n");
    printf("╟──────────────────────────────────────────────────────────────────────╢\n");
    printf("║                                                                      ║\n");
    printf("                   -> CPF EXISTENTE(formato xxx.xxx.xxx-xx):");
    scanf("%14s", cpf);
    getchar();
    printf("║                                                                      ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════╝\n");
    printf("  ──────────────────Pressione <ENTER> para continuar──────────────────  \n");
    getchar();
}

void pesquisar_assinaturas(void){
    struct assinatura nAss;
    system("clear||cls");
    printf("\n");
    printf("╔══════════════════════════════-SIG-BEER-══════════════════════════════╗\n");
    printf("║                                                                      ║\n");
    printf("║                         PESQUISAR ASSINATURA                         ║\n");
    printf("║                                                                      ║\n");
    printf("╟──────────────────────────────────────────────────────────────────────╢\n");
    printf("║                                                                      ║\n");
    printf("                   -> INSIRA O ID :");
    scanf("%10s", nAss.idassinatura);
    getchar();
    printf("║                                                                      ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════╝\n");
    printf("  ──────────────────Pressione <ENTER> para continuar──────────────────  \n");
    getchar();
}

void cancelar_assinaturas(void){
    system("clear||cls");
    struct assinatura nAss;
    printf("\n");
    printf("╔══════════════════════════════-SIG-BEER-══════════════════════════════╗\n");
    printf("║                                                                      ║\n");
    printf("║                         CANCELAR ASSINATURA                          ║\n");
    printf("║                                                                      ║\n");
    printf("╟──────────────────────────────────────────────────────────────────────╢\n");
    printf("║                                                                      ║\n");
    printf("                   -> INSIRA O ID DA ASSINATURA:");
    scanf("%10s", nAss.idassinatura);
    getchar();
    printf("║                                                                      ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════╝\n");
    printf("  ──────────────────Pressione <ENTER> para continuar──────────────────  \n");
    getchar();
}