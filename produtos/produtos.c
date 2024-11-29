/*
╔═════════════════════════════════════════════════════════════════╗
║                  M Ó D U L O  P R O D U T O S                   ║
╚═════════════════════════════════════════════════════════════════╝
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produtos.h"

#define MAX_PRODUTOS 100 //feito pelo gpt

// Lista de produtos e contador global
struct Produtos lista_produtos[MAX_PRODUTOS];
int total_produtos = 0;

void salvar_produtos_em_arquivo(void) {
    FILE *arquivo = fopen("produtos.dat", "wb");
    if (!arquivo) {
        printf("Erro ao salvar produtos no arquivo.\n");
        return;
    }
    fwrite(&total_produtos, sizeof(int), 1, arquivo);
    fwrite(lista_produtos, sizeof(struct Produtos), total_produtos, arquivo);
    fclose(arquivo);
}

void carregar_produtos_de_arquivo(void) {
    FILE *arquivo = fopen("produtos.dat", "rb");
    if (!arquivo) {
        // Arquivo inexistente ou vazio
        total_produtos = 0;
        return;
    }
    fread(&total_produtos, sizeof(int), 1, arquivo);
    fread(lista_produtos, sizeof(struct Produtos), total_produtos, arquivo);
    fclose(arquivo);
}

void modulo_produtos(void) {
    carregar_produtos_de_arquivo();  // Carrega os dados salvos no início
    char opcao;
    do {
        opcao = menu_produtos();
        switch (opcao) {
            case '1': cadastrar_produtos(); break;
            case '2': pesquisar_produtos(); break;
            case '3': atualizar_produtos(); break;
            case '4': remover_produtos(); break;
        }
    } while (opcao != '0');
    salvar_produtos_em_arquivo();  // Salva os dados no final
}

char menu_produtos(void) {
    char op;
    system("clear||cls");
    printf("\n");
    printf("╔══════════════════════════════-SIG-BEER-══════════════════════════════╗\n");
    printf("║                                                                      ║\n");
    printf("║                            MENU PRODUTOS                             ║\n");
    printf("║                                                                      ║\n");
    printf("╟──────────────────────────────────────────────────────────────────────╢\n");
    printf("║                                                                      ║\n");
    printf("║                     1. CADASTRAR NOVO PRODUTO                        ║\n");
    printf("║                     2. PESQUISAR DADOS DO PRODUTO                    ║\n");
    printf("║                     3. ATUALIZAR DADOS DO PRODUTO                    ║\n");
    printf("║                     4. REMOVER PRODUTO DO SISTEMA                    ║\n");
    printf("║                     0. VOLTAR                                        ║\n");
    printf("║                                                                      ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════╝\n");
    printf("                         Escolha uma opção: ");
    scanf("%c", &op);
    getchar();
    return op;
}

void cadastrar_produtos(void) {
    if (total_produtos >= MAX_PRODUTOS) {
        printf("Limite máximo de produtos atingido.\n");
        return;
    }

    struct Produtos new_pro;

    system("clear||cls");
    printf("\n");
    printf("╔══════════════════════════════-SIG-BEER-══════════════════════════════╗\n");
    printf("║                          CADASTRAR PRODUTO                           ║\n");
    printf("╟──────────────────────────────────────────────────────────────────────╢\n");

    // Nome da cerveja
    printf("                      -> NOME DA CERVEJA: ");
    scanf("%20s", new_pro.nomeprod);
    getchar();

    // Teor alcoólico
    printf("                      -> TEOR ALCOÓLICO (Apenas números): ");
    scanf("%4s", new_pro.teor);
    getchar();

    // Amargor
    printf("                       ╔═-AMARGOR-═══════════╗\n");
    printf("                       ║  1. Baixo           ║\n");
    printf("                       ║  2. Médio           ║\n");
    printf("                       ║  3. Alto            ║\n");
    printf("                         Escolha uma opção: ");
    scanf(" %c", &new_pro.amargor);
    getchar();

    // Quantidade
    printf("                      -> QUANTIDADE EM ML (Apenas números): ");
    scanf("%5s", new_pro.quant);
    getchar();

    // ID do produto
    printf("                      -> ID DO PRODUTO: ");
    scanf("%11s", new_pro.id);
    getchar();

    // Adiciona à lista
    lista_produtos[total_produtos] = new_pro;
    total_produtos++;

    printf("Produto cadastrado com sucesso!\n");
    printf("  ──────────────────Pressione <ENTER> para continuar──────────────────  \n");
    getchar();
}

void pesquisar_produtos(void) {
    char id[12];
    printf("Digite o ID do produto: ");
    scanf("%11s", id);
    getchar();

    for (int i = 0; i < total_produtos; i++) {
        if (strcmp(lista_produtos[i].id, id) == 0) {
            printf("Produto encontrado:\n");
            printf("Nome: %s\n", lista_produtos[i].nomeprod);
            printf("Teor Alcoólico: %s%%\n", lista_produtos[i].teor);
            printf("Amargor: %c\n", lista_produtos[i].amargor);
            printf("Quantidade: %s ml\n", lista_produtos[i].quant);
            return;
        }
    }
    printf("Produto não encontrado.\n");
}


void pesquisar_produtos(void) {
    system("clear||cls");
    char id[12];
    struct Produtos new_pro;

    printf("\n");
    printf("╔══════════════════════════════-SIG-BEER-══════════════════════════════╗\n");
    printf("║                                                                      ║\n");
    printf("║                          PESQUISAR PRODUTO                           ║\n");
    printf("║                                                                      ║\n");
    printf("╟──────────────────────────────────────────────────────────────────────╢\n");
    printf("║                                                                      ║\n");
    printf("                      -> INSIRA O ID DO PRODUTO: ");
    scanf("%11s", id);
    getchar();
    printf("║                                                                      ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════╝\n");

    for (int i = 0; i < total_produtos; i++) {
        if (strcmp(lista_produtos[i].id, id) == 0) {
            printf("Produto encontrado:\n");
            printf("Nome: %s\n", lista_produtos[i].nomeprod);
            printf("Teor Alcoólico: %s%%\n", lista_produtos[i].teor);
            printf("Amargor: %c\n", lista_produtos[i].amargor);
            printf("Quantidade: %s ml\n", lista_produtos[i].quant);
            printf("  ──────────────────Pressione <ENTER> para continuar──────────────────  \n");
            getchar();
            return;
        }
    }

    printf("Produto não encontrado.\n");
    printf("  ──────────────────Pressione <ENTER> para continuar──────────────────  \n");
    getchar();
}

void atualizar_produtos(void) {
    system("clear||cls");
    char id[12];
    struct Produtos new_pro;

    printf("\n");
    printf("╔══════════════════════════════-SIG-BEER-══════════════════════════════╗\n");
    printf("║                                                                      ║\n");
    printf("║                          ATUALIZAR PRODUTO                           ║\n");
    printf("║                                                                      ║\n");
    printf("╟──────────────────────────────────────────────────────────────────────╢\n");
    printf("║                                                                      ║\n");
    printf("                      -> INSIRA O ID DO PRODUTO: ");
    scanf("%11s", id);
    getchar();
    printf("║                                                                      ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════╝\n");

    for (int i = 0; i < total_produtos; i++) {
        if (strcmp(lista_produtos[i].id, id) == 0) {
            printf("Atualizando produto...\n");
            cadastrar_produtos(); // Simula atualização
            lista_produtos[i] = lista_produtos[total_produtos - 1];
            total_produtos--;
            printf("  ──────────────────Pressione <ENTER> para continuar──────────────────  \n");
            getchar();
            return;
        }
    }

    printf("Produto não encontrado.\n");
    printf("  ──────────────────Pressione <ENTER> para continuar──────────────────  \n");
    getchar();
}

void remover_produtos(void) {
    system("clear||cls");
    char id[12];
    struct Produtos new_pro;

    printf("\n");
    printf("╔══════════════════════════════-SIG-BEER-══════════════════════════════╗\n");
    printf("║                                                                      ║\n");
    printf("║                           REMOVER PRODUTO                            ║\n");
    printf("║                                                                      ║\n");
    printf("╟──────────────────────────────────────────────────────────────────────╢\n");
    printf("║                                                                      ║\n");
    printf("                      -> INSIRA O ID DO PRODUTO: ");
    scanf("%11s", id);
    getchar();
    printf("║                                                                      ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════╝\n");

    for (int i = 0; i < total_produtos; i++) {
        if (strcmp(lista_produtos[i].id, id) == 0) {
            for (int j = i; j < total_produtos - 1; j++) {
                lista_produtos[j] = lista_produtos[j + 1];
            }
            total_produtos--;
            printf("Produto removido com sucesso!\n");
            printf("  ──────────────────Pressione <ENTER> para continuar──────────────────  \n");
            getchar();
            return;
        }
    }

    printf("Produto não encontrado.\n");
    printf("  ──────────────────Pressione <ENTER> para continuar──────────────────  \n");
    getchar();
}
