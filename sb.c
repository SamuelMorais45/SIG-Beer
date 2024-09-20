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

//assinatura das funções
void tela_principal(void);
void tela_sobre(void);
void tela_equipe(void);

//codigo principal
int main (void){
    tela_principal();
    tela_sobre();
    tela_equipe();
    return 0;
}

//funções
void tela_principal(void){
    printf("\n");
    printf("╔══════════════════════════════-SIG-BEER-══════════════════════════════╗\n");
    printf("║                                                                      ║\n");
    printf("║                            MENU PRINCIPAL                            ║\n");
    printf("║                                                                      ║\n");
    printf("╟──────────────────────────────────────────────────────────────────────╢\n");
    printf("║                                                                      ║\n");
    printf("║                         1. MÓDULO CLIENTES                           ║\n");
    printf("║                         2. MÓDULO PANOS                              ║\n");
    printf("║                         3. MÓDULO ASSINATURA                         ║\n");
    printf("║                         0. SAIR                                      ║\n");
    printf("║                                                                      ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════╝\n");
}

void tela_sobre(void){
    printf("\n");
    printf("╔════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                           Sobre o Programa                                 ║\n");
    printf("╟────────────────────────────────────────────────────────────────────────────╢\n");
    printf("║  Este programa tem intuito de ser um sistema de assinatura de cervejas,    ║\n");
    printf("║ onde irá oferecer vários packs de cervejas artesenais de alta qualidade.   ║\n");
    printf("║ Mas sendo ainda um projeto didático para a disciplina de Programação do    ║\n");
    printf("║ curso de Bacharelado de Sistemas de Informação da UFRN.                    ║\n");
    printf("╚════════════════════════════════════════════════════════════════════════════╝\n");
}

void tela_equipe(void){
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
}
