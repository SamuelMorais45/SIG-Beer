/*
╔═════════════════════════════════════════════════════════════════╗
║                  M Ó D U L O  P R O D U T O S                   ║
╚═════════════════════════════════════════════════════════════════╝
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produtos.h"

#define MAX_PRODUTOS 1000 
#define ARQUIVO_PRODUTOS "produtos.dat"




struct Produtos lista_produtos[MAX_PRODUTOS];
int total_produtos = 0;


void salvar_newpro(const struct Produtos *new_pro) {
    FILE *fp = fopen(ARQUIVO_PRODUTOS, "ab");  
    if (fp == NULL) {
        perror("Erro ao abrir o arquivo para salvar os dados do produto");
        return;
    }
    fwrite(new_pro, sizeof(struct Produtos), 1, fp);  
    fclose(fp);
}


void carregar_produtos_de_arquivo(void) {
    FILE *arquivo = fopen(ARQUIVO_PRODUTOS, "rb");
    if (!arquivo) {
        return; 
    }

    total_produtos = 0;
    while (fread(&lista_produtos[total_produtos], sizeof(struct Produtos), 1, arquivo) == 1) {
        total_produtos++;
    }

    fclose(arquivo);
}


void salvar_produtos_em_arquivo(void) {
    FILE *arquivo = fopen(ARQUIVO_PRODUTOS, "wb");
    if (!arquivo) {
        perror("Erro ao salvar os produtos no arquivo");
        return;
    }

    fwrite(lista_produtos, sizeof(struct Produtos), total_produtos, arquivo);
    fclose(arquivo);
}


void modulo_produtos(void) {
    carregar_produtos_de_arquivo(); 

    char opcao;
    do {
        opcao = menu_produtos();
        switch (opcao) {
            case '1': cadastrar_produtos(); break;
            case '2': pesquisar_produtos(); break;
            case '3': atualizar_produtos(); break;
            case '4': remover_produtos(); break;
            case '0': break; 
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != '0');

    salvar_produtos_em_arquivo(); 
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
    scanf(" %c", &op);
    getchar();
    return op;
}

void cadastrar_produtos(void) {
    if (total_produtos >= MAX_PRODUTOS) {
        printf("Limite de produtos atingido.\n");
        return;
    }
    struct Produtos new_pro;
    system("clear||cls");
    printf("╔══════════════════════════════-SIG-BEER-══════════════════════════════╗\n");
    printf("║                          CADASTRAR PRODUTO                           ║\n");
    printf("╟──────────────────────────────────────────────────────────────────────╢\n");

    printf("                      -> NOME DA CERVEJA: ");
    fgets(new_pro.nomeprod, sizeof(new_pro.nomeprod), stdin);
    new_pro.nomeprod[strcspn(new_pro.nomeprod, "\n")] = '\0'; 

    printf("                      -> TEOR ALCOÓLICO (Apenas números): ");
    fgets(new_pro.teor, sizeof(new_pro.teor), stdin);
    new_pro.teor[strcspn(new_pro.teor, "\n")] = '\0'; 

    printf("                       ╔═-AMARGOR-═══════════╗\n");
    printf("                       ║  1. Baixo           ║\n");
    printf("                       ║  2. Médio           ║\n");
    printf("                       ║  3. Alto            ║\n");
    printf("                         Escolha uma opção: ");
    scanf(" %c", &new_pro.amargor);
    getchar(); 

    printf("                      -> QUANTIDADE EM ML (Apenas números): ");
    fgets(new_pro.quant, sizeof(new_pro.quant), stdin);
    new_pro.quant[strcspn(new_pro.quant, "\n")] = '\0'; 

    
    new_pro.id = total_produtos + 1; 
    new_pro.status = 0; 

    
    lista_produtos[total_produtos] = new_pro;
    total_produtos++;

    printf("                      Produto cadastrado com sucesso!\n");
    printf("  ──────────────────Pressione <ENTER> para continuar──────────────────  \n");
    getchar();
}


void pesquisar_produtos(void) {
    system("clear||cls");
    int id;

    printf("\n");
    printf("╔══════════════════════════════-SIG-BEER-══════════════════════════════╗\n");
    printf("║                                                                      ║\n");
    printf("║                          PESQUISAR PRODUTO                           ║\n");
    printf("║                                                                      ║\n");
    printf("╟──────────────────────────────────────────────────────────────────────╢\n");
    printf("║                                                                      ║\n");
    printf("                      -> INSIRA O ID DO PRODUTO: ");
    scanf("%d", &id);
    getchar();

    for (int i = 0; i < total_produtos; i++) {
        if (lista_produtos[i].id == id && lista_produtos[i].status == 0) {
            printf("                      Produto encontrado:\n");
            printf("                      Nome: %s\n", lista_produtos[i].nomeprod);
            printf("                      Teor alcoólico: %s%%\n", lista_produtos[i].teor);
            printf("                      Amargor: %c\n", lista_produtos[i].amargor);
            printf("                      Quantidade: %s ml\n", lista_produtos[i].quant);
            getchar();
            return;
        }
    }

    printf("                      Produto não encontrado ou excluído.\n");
    getchar();
    printf("║                                                                      ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════╝\n");
    printf("  ──────────────────Pressione <ENTER> para continuar──────────────────  \n");
    getchar();
}


void atualizar_produtos(void) {
    system("clear||cls");
    int id;

    printf("\n");
    printf("╔══════════════════════════════-SIG-BEER-══════════════════════════════╗\n");
    printf("║                          ATUALIZAR PRODUTO                           ║\n");
    printf("╟──────────────────────────────────────────────────────────────────────╢\n");
    printf("                      -> INSIRA O ID DO PRODUTO: ");
    scanf("%d", &id);
    getchar(); 

    for (int i = 0; i < total_produtos; i++) {
        if (lista_produtos[i].id == id && lista_produtos[i].status == 0) {
            printf("                      Atualize os dados do produto:\n");

            printf("                      -> NOME DA CERVEJA: ");
            fgets(lista_produtos[i].nomeprod, sizeof(lista_produtos[i].nomeprod), stdin);
            lista_produtos[i].nomeprod[strcspn(lista_produtos[i].nomeprod, "\n")] = '\0'; 

            printf("                      -> TEOR ALCOÓLICO (Apenas números): ");
            fgets(lista_produtos[i].teor, sizeof(lista_produtos[i].teor), stdin);
            lista_produtos[i].teor[strcspn(lista_produtos[i].teor, "\n")] = '\0'; 

            printf("                       ╔═-AMARGOR-═══════════╗\n");
            printf("                       ║  1. Baixo           ║\n");
            printf("                       ║  2. Médio           ║\n");
            printf("                       ║  3. Alto            ║\n");
            printf("                         Escolha uma opção: ");
            scanf(" %c", &lista_produtos[i].amargor);
            getchar(); 

            printf("                      -> QUANTIDADE EM ML (Apenas números): ");
            fgets(lista_produtos[i].quant, sizeof(lista_produtos[i].quant), stdin);
            lista_produtos[i].quant[strcspn(lista_produtos[i].quant, "\n")] = '\0'; 

            printf("                      Produto atualizado com sucesso!\n");
            getchar();
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
    int id;
printf("\n");
    printf("╔══════════════════════════════-SIG-BEER-══════════════════════════════╗\n");
    printf("║                           REMOVER PRODUTO                            ║\n");
    printf("╟──────────────────────────────────────────────────────────────────────╢\n");
    printf("                      -> INSIRA O ID DO PRODUTO: ");

    scanf("%d", &id);
    getchar();

    for (int i = 0; i < total_produtos; i++) {
        if (lista_produtos[i].id == id) {
            if (lista_produtos[i].status == 1) {
                printf("                      Produto já está excluído.\n");
            } else {
                lista_produtos[i].status = 1;
                printf("                      Produto removido com sucesso.\n");
            }
            getchar();
            return;
        }
    }

    printf("                      Produto não encontrado.\n");
    getchar();
}
