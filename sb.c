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
#include "clientes/clientes.h"
#include "produtos/produtos.h"
#include "packs/packs.h"
#include "assinaturas/assinaturas.h"
#include "relatorios/relatorios.h"

//assinatura das funções
char menu_principal(void);
void tela_sobre(void);
void tela_equipe(void);

//codigo principal
int main (void) {
    char opcao;
    do {
        opcao = menu_principal();
        switch (opcao) {
            case '1': modulo_clientes();
            break;
            case '2': modulo_produtos();
            break;
            case '3': modulo_packs();
            break;
            case '4': modulo_assinaturas();
            break;
            case '5': modulo_relatorios();
            break;
        }
    } while (opcao != '0');
    return 0;
}

//funções
char menu_principal(void){
    char op;
    system("clear||cls");
    printf("\n");
    printf("╔══════════════════════════════-SIG-BEER-══════════════════════════════╗\n");
    printf("║                                                                      ║\n");
    printf("║                            MENU PRINCIPAL                            ║\n");
    printf("║                                                                      ║\n");
    printf("╟──────────────────────────────────────────────────────────────────────╢\n");
    printf("║                                                                      ║\n");
    printf("║                         1. MÓDULO CLIENTES                           ║\n");
    printf("║                         2. MÓDULO PRODUTOS                           ║\n");
    printf("║                         3. MÓDULO PACKS                              ║\n");
    printf("║                         4. MÓDULO ASSINATURAS                        ║\n");
    printf("║                         5. MÓDULO RELATÓRIOS                         ║\n");
    printf("║                         0. SAIR                                      ║\n");
    printf("║                                                                      ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════╝\n");
    printf("                         Escolha uma opção: ");
    scanf("%c", &op);
    getchar();
    return op;
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
    printf("╟──────────────────────────────────────────────────────────────────────╢\n");
    printf("║                                                                      ║\n");
    printf("║                   Nathan Lopes                                       ║\n");
    printf("║                   Email: natelopes18@gmail.com                       ║\n");
    printf("║                   Git: https://github.com/coderlupus                 ║\n");
    printf("║                                                                      ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════╝\n");
    printf("╟──────────────────────────────────────────────────────────────────────╢\n");
    printf("║                                                                      ║\n");
    printf("║                   Tomé Arcanjo                                       ║\n");
    printf("║                   Email: tomearcanjo12@gmail.com                     ║\n");
    printf("║                   Git: https://github.com/Tome-arcanjo               ║\n");
    printf("║                                                                      ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════╝\n");
    printf("  ───────────────────Pressione <ENTER> para encerrar──────────────────  \n");
    getchar();
    }

