/*
╔═════════════════════════════════════════════════════════════════╗
║              M Ó D U L O  A S S I N A T U R A                   ║
╚═════════════════════════════════════════════════════════════════╝
*/

#include <stdio.h>
#include <stdlib.h>
#include "assinaturas.h"




char menu_assinatura(void){
    char op;
    system("clear||cls");
    printf("\n");
    printf("╔══════════════════════════════-SIG-BEER-══════════════════════════════╗\n");
    printf("║                                                                      ║\n");
    printf("║                            MENU ASSINATURA                           ║\n");
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
    printf("  ──────────────────Pressione <ENTER> para continuar──────────────────  \n");
    getchar();
    return op;
}

void cadastrar_assinatura(void){
    char cpf[16];
    system("clear||cls");
    printf("\n");
    printf("╔══════════════════════════════-SIG-BEER-══════════════════════════════╗\n");
    printf("║                                                                      ║\n");
    printf("║                          CADASTRAR ASSINATURA                        ║\n");
    printf("║                                                                      ║\n");
    printf("╟──────────────────────────────────────────────────────────────────────╢\n");
    printf("║                                                                      ║\n");
    printf("                   -> CPF EXISTENTE(formato xxx.xxx.xxx-xx):");
    scanf("%14s", cpf);
    printf("║                                                                      ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════╝\n");
    printf(" ──────────────────Pressione <ENTER> para continuar────────────────── \n");
    getchar();
}

void pesquisar_assinatura(void){
    char idassinatura[12];
    system("clear||cls");
    printf("\n");
    printf("╔══════════════════════════════-SIG-BEER-══════════════════════════════╗\n");
    printf("║                                                                      ║\n");
    printf("║                          PESQUISAR ASSINATURA                        ║\n");
    printf("║                                                                      ║\n");
    printf("╟──────────────────────────────────────────────────────────────────────╢\n");
    printf("║                                                                      ║\n");
    printf("                   -> INSIRA O ID :");
    scanf("%10s", idassinatura);
    printf("║                                                                      ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════╝\n");
    printf(" ──────────────────Pressione <ENTER> para continuar────────────────── \n");
    getchar();
}