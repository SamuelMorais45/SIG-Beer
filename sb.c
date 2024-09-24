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
void tela_cadastrar_cliente(void);
void tela_pesquisar_cliente(void);
void tela_atualizar_cliente(void);
void tela_apagar_cliente(void);
void tela_sobre(void);
void tela_equipe(void);

//codigo principal
int main (void){
    tela_principal();
    tela_menu_clientes();
    tela_cadastrar_cliente();
    tela_pesquisar_cliente();
    tela_atualizar_cliente();
    tela_apagar_cliente();
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
    printf("║                         2. MÓDULO PLANOS                             ║\n");
    printf("║                         3. MÓDULO ASSINATURAS                        ║\n");
    printf("║                         4. MÓDULO RELATÓRIOS                         ║\n");
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
    printf("║                     4. REMOVER CLIENTE DO SISTEMA                    ║\n");
    printf("║                     0. VOLTAR                                        ║\n");
    printf("║                                                                      ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════╝\n");
    printf("  ──────────────────Pressione <ENTER> para continuar──────────────────  \n");
    getchar();
}

void tela_cadastrar_cliente(void){
    system("clear||cls");
    printf("\n");
    printf("╔══════════════════════════════-SIG-BEER-══════════════════════════════╗\n");
    printf("║                                                                      ║\n");
    printf("║                          CADASTRAR CLIENTE                           ║\n");
    printf("║                                                                      ║\n");
    printf("╟──────────────────────────────────────────────────────────────────────╢\n");
    printf("║                                                                      ║\n");
    printf("║                      -> CPF (Apenas números):                        ║\n");
    printf("║                      -> NOME COMPLETO:                               ║\n");
    printf("║                      -> DATA DE NASCIMENTO (dd/mm/aaaa):             ║\n");
    printf("║                      -> ENDEREÇO:                                    ║\n");
    printf("║                      -> CELULAR (Apenas números):                    ║\n");
    printf("║                      -> E-MAIL:                                      ║\n");
    printf("║                                                                      ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════╝\n");
    printf("  ──────────────────Pressione <ENTER> para continuar──────────────────  \n");
    getchar();
}

void tela_pesquisar_cliente(void){
    system("clear||cls");
    printf("\n");
    printf("╔══════════════════════════════-SIG-BEER-══════════════════════════════╗\n");
    printf("║                                                                      ║\n");
    printf("║                          PESQUISAR CLIENTE                           ║\n");
    printf("║                                                                      ║\n");
    printf("╟──────────────────────────────────────────────────────────────────────╢\n");
    printf("║                                                                      ║\n");
    printf("║                  -> INSIRA O CPF (Apenas números):                   ║\n");
    printf("║                                                                      ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════╝\n");
    printf("  ──────────────────Pressione <ENTER> para continuar──────────────────  \n");
    getchar();
}

void tela_atualizar_cliente(void){
    system("clear||cls");
    printf("\n");
    printf("╔══════════════════════════════-SIG-BEER-══════════════════════════════╗\n");
    printf("║                                                                      ║\n");
    printf("║                          ATUALIZAR CLIENTE                           ║\n");
    printf("║                                                                      ║\n");
    printf("╟──────────────────────────────────────────────────────────────────────╢\n");
    printf("║                                                                      ║\n");
    printf("║                  -> INSIRA O CPF (Apenas números):                   ║\n");
    printf("║                                                                      ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════╝\n");
    printf("  ──────────────────Pressione <ENTER> para continuar──────────────────  \n");
    getchar();
}

void tela_apagar_cliente(void){
    system("clear||cls");
    printf("\n");
    printf("╔══════════════════════════════-SIG-BEER-══════════════════════════════╗\n");
    printf("║                                                                      ║\n");
    printf("║                           APAGAR CLIENTE                             ║\n");
    printf("║                                                                      ║\n");
    printf("╟──────────────────────────────────────────────────────────────────────╢\n");
    printf("║                                                                      ║\n");
    printf("║                  -> INSIRA O CPF (Apenas números):                   ║\n");
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
