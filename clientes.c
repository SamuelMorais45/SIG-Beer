/*
╔═════════════════════════════════════════════════════════════════╗
║                  M Ó D U L O  C L I E N T E S                   ║
╚═════════════════════════════════════════════════════════════════╝
*/

#include <stdio.h>
#include <stdlib.h>
#include "clientes.h"

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
