/*
╔═════════════════════════════════════════════════════════════════╗
║           UNIVERSIDADE FEDERAL DO RIO GRANDE DO NORTE           ║
║           Centro de Ensino Superior do Seridó (Ceres)           ║
║               Disciplina DCT1106 -- Programação                 ║
║           Projeto: Sistema de Assinatura de Cervejas            ║
║         Desenvolvido por @oguiaraujo e @SamuelMorais45          ║
╚═════════════════════════════════════════════════════════════════╝
*/

#include <stdio.h>
#include <stdlib.h>

//assinatura das funções
void tela_principal(void);
void tela_menu_clientes(void);
void tela_sobre(void);
void tela_equipe(void);

//codigo principal
int main (void){
    tela_principal();
    tela_menu_clientes();
    tela_sobre();
    tela_equipe();
    return 0;
}

//funções
void tela_principal(void){
    system("clear||cls");
    printf("\n");
    printf("╔══════════════════════════════-SIG-BEER-══════════════════════════════╗\n");
    printf("║                                                                      ║\n");
    printf("║                            MENU PRINCIPAL                            ║\n");
    printf("║                                                                      ║\n");
    printf("╟──────────────────────────────────────────────────────────────────────╢\n");
    printf("║                                                                      ║\n");
    printf("║                         1. MÓDULO CLIENTES                           ║\n");
    printf("║                         2. MÓDULO PANOS                              ║\n");
    printf("║                         3. MÓDULO ASSINATURAS                        ║\n");
    printf("║                         3. MÓDULO RELATÓRIOS                         ║\n");
    printf("║                         0. SAIR                                      ║\n");
    printf("║                                                                      ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════╝\n");
    printf("  ──────────────────Pressione <ENTER> para continuar──────────────────  \n");
    getchar();
}

void tela_menu_clientes(void){
    system("clear||cls");
    printf("\n");
    printf("╔══════════════════════════════-SIG-BEER-══════════════════════════════╗\n");
    printf("║                                                                      ║\n");
    printf("║                            MENU CLIENTES                             ║\n");
    printf("║                                                                      ║\n");
    printf("╟──────────────────────────────────────────────────────────────────────╢\n");
    printf("║                                                                      ║\n");
    printf("║                     1. CADASTRAR NOVO CLIENTE                        ║\n");
    printf("║                     2. PESQUISAR DADOS DO CLIENTE                    ║\n");
    printf("║                     3. ATUALIZAR DADOS DO CLIENTE                    ║\n");
    printf("║                     3. EXCLUIR CLIENTE DO SISTEMA                    ║\n");
    printf("║                     0. VOLTAR                                        ║\n");
    printf("║                                                                      ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════╝\n");
    printf("  ──────────────────Pressione <ENTER> para continuar──────────────────  \n");
    getchar();
}

void tela_sobre(void){
    system("clear||cls");
    printf("\n");
    printf("╔══════════════════════════════-SIG-BEER-══════════════════════════════╗\n");
    printf("║                                                                      ║\n");
    printf("║                           SOBRE O PROGRAMA                           ║\n");
    printf("║                                                                      ║\n");
    printf("╟──────────────────────────────────────────────────────────────────────╢\n");
    printf("║                                                                      ║\n");
    printf("║  Este programa tem como objetivo ser um sistema de assinatura de     ║\n");
    printf("║  cervejas, oferecendo uma variedade de packs de cervejas artesanais  ║\n");
    printf("║  de alta qualidade. Além disso, trata-se de um projeto didático      ║\n");
    printf("║  desenvolvido para a disciplina de Programação do curso de           ║\n");
    printf("║  Bacharelado em Sistemas de Informação da UFRN.                      ║\n");
    printf("║                                                                      ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════╝\n");
    printf("  ──────────────────Pressione <ENTER> para continuar──────────────────  \n");
    getchar();
}

void tela_equipe(void){
    system("clear||cls");
    printf("\n");
    printf("╔══════════════════════════════-SIG-BEER-══════════════════════════════╗\n");
    printf("║                                                                      ║\n");
    printf("║                       EQUIPE DE DESENVOLVIMENTO                      ║\n");
    printf("║                                                                      ║\n");
    printf("╟──────────────────────────────────────────────────────────────────────╢\n");
    printf("║                                                                      ║\n");
    printf("║                   José Guilherme Silva de Araújo                     ║\n");
    printf("║                   Email: guilherme531araujo@gmail.com                ║\n");
    printf("║                   Redes Sociais: @oguiaraujo_o                       ║\n");
    printf("║                   Git: https://github.com/oguiaraujo                 ║\n");
    printf("║                                                                      ║\n");
    printf("╟──────────────────────────────────────────────────────────────────────╢\n");
    printf("║                                                                      ║\n");
    printf("║                   Samuel Morais de Araújo                            ║\n");
    printf("║                   Email: morais123samuel@gmail.com                   ║\n");
    printf("║                   Git: https://github.com/SamuelMorais45             ║\n");
    printf("║                                                                      ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════╝\n");
    printf("  ───────────────────Pressione <ENTER> para encerrar──────────────────  \n");
    getchar();
}