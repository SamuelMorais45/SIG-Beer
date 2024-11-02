/*
╔══════════════════════════════════════════════════════════════╗
║                   M Ó D U L O  P A C K S                     ║
╚══════════════════════════════════════════════════════════════╝
*/

#include <stdio.h>
#include <stdlib.h>
#include "packs.h"
#include "../validacoes/validacoes.h"

void modulo_packs(void) {
    char opcao;
    do {
        opcao = menu_packs();
        switch (opcao) {
            case '1': cadastrar_packs();
            break;
            case '2': pesquisar_packs();
            break;
            case '3': remover_packs();
            break;
        }
    } while (opcao != '0');
}

char menu_packs(void){
    char op;
    system("clear||cls");
    printf("\n");
    printf("╔══════════════════════════════-SIG-BEER-══════════════════════════════╗\n");
    printf("║                                                                      ║\n");
    printf("║                              MENU PACKS                              ║\n");
    printf("║                                                                      ║\n");
    printf("╟──────────────────────────────────────────────────────────────────────╢\n");
    printf("║                                                                      ║\n");
    printf("║                       1. CADASTRAR NOVO PACK                         ║\n");
    printf("║                       2. PESQUISAR DADOS DO PACK                     ║\n");
    printf("║                       3. REMOVER PACK DO SISTEMA                     ║\n");
    printf("║                       0. VOLTAR                                      ║\n");
    printf("║                                                                      ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════╝\n");
    printf("                         Escolha uma opção: ");
    scanf("%c", &op);
    getchar();
    return op;
}

void cadastrar_packs(void) {
    char idprods[22];
    char nomepack[42];
    int teste;

    system("clear||cls");
    printf("\n");
    printf("╔══════════════════════════════-SIG-BEER-══════════════════════════════╗\n");
    printf("║                                                                      ║\n");
    printf("║                           CADASTRAR PACK                             ║\n");
    printf("║                                                                      ║\n");
    printf("╟──────────────────────────────────────────────────────────────────────╢\n");
    printf("║                                                                      ║\n");

    // Validação do ID dos produtos
    do {
        printf("                        -> ID DOS 4 PRODUTOS: ");
        scanf("%20s", idprods);
        teste = verifica_numeros(idprods);
        if (!teste) {
            printf("                        ID inválido. Insira apenas números.\n");
        }
    } while (!teste);  // Repete enquanto a entrada for inválida

    // Validação do nome do pack
    do {
        printf("                        -> NOME DO PACK: ");
        scanf("%41s", nomepack);  // Limita a leitura a 41 caracteres para evitar overflow
        if (strlen(nomepack) == 0) {  // Verifica se o nome está vazio
            printf("                        Nome inválido. Não pode ser vazio.\n");
        }
    } while (strlen(nomepack) == 0);  // Repete enquanto o nome estiver vazio

    printf("║                                                                      ║\n");
    printf("                   Pack cadastrado com sucesso!\n");
    printf("╚══════════════════════════════════════════════════════════════════════╝\n");
    printf("  ──────────────────Pressione <ENTER> para continuar──────────────────  \n");
    getchar(); // Limpa o buffer após a leitura do nome
    getchar(); // Espera o usuário pressionar ENTER
}



void pesquisar_packs(void) {
    char idpack[12];
    int valido;

    system("clear||cls");
    printf("\n");
    printf("╔══════════════════════════════-SIG-BEER-══════════════════════════════╗\n");
    printf("║                                                                      ║\n");
    printf("║                            PESQUISAR PACK                            ║\n");
    printf("║                                                                      ║\n");
    printf("╟──────────────────────────────────────────────────────────────────────╢\n");
    printf("║                                                                      ║\n");

    // Loop para garantir que o ID inserido é válido
    do {
        printf("                       -> INSIRA O ID DO PACK: ");
        scanf("%10s", idpack);
        getchar(); // Limpa o buffer
        valido = verifica_numeros(idpack); // Função para validar se idpack contém apenas números
        if (!valido) {
            printf("                        ID inválido. Insira apenas números.\n");
        }
    } while (!valido); // Repete enquanto o ID não for válido

    printf("║                                                                      ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════╝\n");
    printf("  ──────────────────Pressione <ENTER> para continuar──────────────────  \n");
    getchar(); // Espera o usuário pressionar ENTER
}

void remover_packs(void) {
    char idpack[12];
    int valido;

    system("clear||cls");
    printf("\n");
    printf("╔══════════════════════════════-SIG-BEER-══════════════════════════════╗\n");
    printf("║                                                                      ║\n");
    printf("║                             REMOVER PACK                             ║\n");
    printf("║                                                                      ║\n");
    printf("╟──────────────────────────────────────────────────────────────────────╢\n");
    printf("║                                                                      ║\n");

    // Loop para garantir que o ID inserido é válido
    do {
        printf("                       -> INSIRA O ID DO PACK: ");
        scanf("%10s", idpack);
        getchar(); // Limpa o buffer
        valido = verifica_numeros(idpack); // Verifica se o idpack contém apenas números
        if (!valido) {
            printf("                        ID inválido. Insira apenas números.\n");
        }
    } while (!valido); // Repete enquanto o ID não for válido

    // Aqui você pode chamar a função para remover o pack usando o idpack
    // Exemplo: remover_pack_por_id(idpack);

    printf("║                                                                      ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════╝\n");
    printf("  ──────────────────Pressione <ENTER> para continuar──────────────────  \n");
    getchar(); // Espera o usuário pressionar ENTER
}