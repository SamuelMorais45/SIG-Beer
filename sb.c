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
void tela_sobre(void);

//codigo principal

int main (void){
    tela_sobre();
    return 0;
}
//funções
    //tela sobre
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