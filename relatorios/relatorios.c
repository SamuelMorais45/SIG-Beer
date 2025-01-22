/*
╔═════════════════════════════════════════════════════════════════╗
║                M Ó D U L O  R E L A T Ó R I O S                 ║
╚═════════════════════════════════════════════════════════════════╝
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "relatorios.h"
#include "../produtos/produtos.h"
#include "../packs/packs.h"
#include "../assinaturas/assinaturas.h"
#include "../clientes/clientes.h"

#define MAX PRODUTOS 1000
#define ARQUIVO_ASSINA "assinaturas.dat"
#define ARQUIVO_PACKS "packs.dat"


void modulo_relatorios(void) {
    char opcao;
    do {
        opcao = menu_relatorios();
        switch (opcao) {
            case '1': produtos_amargor();
            break;
            case '2': packs_produto();
            break;
            case '3': assinaturas_cliente();
            break;
            case '4': assinaturas_pack();
            break;
            case '5': relatorios_simples();
            break;
            case '6': relatorio_compras_cliente();
        }
    } while (opcao != '0');
}

char menu_relatorios(void){
    char op;
    system("clear||cls");
    printf("\n");
    printf("╔══════════════════════════════-SIG-BEER-══════════════════════════════╗\n");
    printf("║                                                                      ║\n");
    printf("║                     MENU RELATÓRIOS COM FILTROS                      ║\n");
    printf("║                                                                      ║\n");
    printf("╟──────────────────────────────────────────────────────────────────────╢\n");
    printf("║                                                                      ║\n");
    printf("║                     1. PRODUTOS POR AMARGOR                          ║\n");
    printf("║                     2. PACKS POR PRODUTO                             ║\n");
    printf("║                     3. ASSINATURAS POR CLIENTE                       ║\n");
    printf("║                     4. ASSINATURAS POR PACK                          ║\n");
    printf("║                     5. RELATÓRIOS SIMPLES                            ║\n");
    printf("║                     0. RELATÓRIO COMPRA POR CLIENTE                  ║\n");
    printf("║                     0. VOLTAR                                        ║\n");
    printf("║                                                                      ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════╝\n");
    printf("                         Escolha uma opção: ");
    scanf("%c", &op);
    getchar();
    return op;
}

void produtos_amargor(void) {
    system("clear||cls");
    char amargor;
    printf("\n");
    printf("╔══════════════════════════════-SIG-BEER-══════════════════════════════╗\n");
    printf("║                                                                      ║\n");
    printf("║                         PRODUTOS POR AMARGOR                         ║\n");
    printf("║                                                                      ║\n");
    printf("╟──────────────────────────────────────────────────────────────────────╢\n");
    printf("║                                                                      ║\n");
    printf("                        ╔═-AMARGOR-═══════════╗\n");
    printf("                        ║  1. Baixo           ║\n");
    printf("                        ║  2. Médio           ║\n");
    printf("                        ║  3. Alto            ║\n");
    printf("                          Escolha uma opção: ");
    scanf(" %c", &amargor);  
    getchar();
    printf("\n                      ╚═════════════════════╝\n");
    printf("║                                                                      ║\n");

    printf("Produtos com amargor '%c':\n", amargor);
    int found = 0;
    for (int i = 0; i < total_produtos; i++) {
        if (lista_produtos[i].status == 0 && lista_produtos[i].amargor == amargor) {
            printf("ID: %d\n", lista_produtos[i].id);
            printf("Nome: %s\n", lista_produtos[i].nomeprod);
            printf("Teor alcoólico: %s%%\n", lista_produtos[i].teor);
            printf("Amargor: %c\n", lista_produtos[i].amargor);
            printf("Quantidade: %s ml\n", lista_produtos[i].quant);
            printf("\n");
            found = 1;
        }
    }

    if (!found) {
        printf("Nenhum produto encontrado com o amargor '%c'.\n", amargor);
    }

    printf("  ──────────────────Pressione <ENTER> para continuar──────────────────  \n");
    getchar();
}


void packs_produto(void){
    system("clear||cls");
    char id[12];
    struct pack np;
    int encontrado = 0;

    printf("\n");
    printf("╔══════════════════════════════-SIG-BEER-══════════════════════════════╗\n");
    printf("║                                                                      ║\n");
    printf("║                          PACKS POR PRODUTO                           ║\n");
    printf("║                                                                      ║\n");
    printf("╟──────────────────────────────────────────────────────────────────────╢\n");

    printf("                      -> INSIRA O ID DO PRODUTO: ");
    scanf("%10s", id);
    getchar();

    FILE *fp = fopen("packs.dat", "rb");
    if (fp == NULL) {
        printf("Nenhum dado encontrado.\n");
    } else {
        while (fread(&np, sizeof(struct pack), 1, fp)) {
            if (np.status == '0' && strstr(np.idprods, id) != NULL) {  
                printf("ID do Pack: %d | Nome: %s | Produtos: %s\n", np.idpack, np.nomepack, np.idprods);
                encontrado = 1;
            }
        }
        fclose(fp);

        if (!encontrado) {
            printf("Nenhum pack encontrado para o produto com ID %s.\n", id);
        }
    }

    printf("╚══════════════════════════════════════════════════════════════════════╝\n");
    printf("  ──────────────────Pressione <ENTER> para continuar──────────────────  \n");
    getchar();
}

void assinaturas_cliente(void){
    FILE *file;  
    struct assinatura temp;
    system("clear||cls");
    printf("\n");
    printf("╔══════════════════════════════-SIG-BEER-══════════════════════════════╗\n");
    printf("║                                                                      ║\n");
    printf("║                        ASSINATURAS POR CLIENTE                       ║\n");
    printf("║                                                                      ║\n");
    printf("╟──────────────────────────────────────────────────────────────────────╢\n");
    printf("║                                                                      ║\n");
    
    file = fopen(ARQUIVO_ASSINA, "rb");
    if (!file) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    printf("ID Assinatura | CPF Cliente        | ID Pacote    | Status\n");
    printf("--------------------------------------------------------------\n");

    while (fread(&temp, sizeof(temp), 1, file)) {
        printf("%-15d | %-18s | %-12s | %s\n", 
            temp.idassinatura, temp.cpf, temp.idpack, temp.status == 0 ? "Ativo" : "Inativo");
    }

    fclose(file);

    printf("║                                                                      ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════╝\n");
    printf("  ──────────────────Pressione <ENTER> para continuar──────────────────  \n");
    getchar();
}

void assinaturas_pack(void) {
    FILE *file_assinaturas; 
    FILE *file_packs;        
    struct assinatura temp_assinatura;
    struct pack temp_pack;
    int encontrou;
    system("clear||cls");
    printf("\n");
    printf("╔══════════════════════════════-SIG-BEER-══════════════════════════════╗\n");
    printf("║                                                                      ║\n");
    printf("║                         ASSINATURAS POR PACK                         ║\n");
    printf("║                                                                      ║\n");
    printf("╟──────────────────────────────────────────────────────────────────────╢\n");
    printf("║                                                                      ║\n");
    file_assinaturas = fopen(ARQUIVO_ASSINA, "rb");
    if (!file_assinaturas) {
        perror("Erro ao abrir o arquivo de assinaturas");
        return;
    }

    file_packs = fopen(ARQUIVO_PACKS, "rb");
    if (!file_packs) {
        perror("Erro ao abrir o arquivo de pacotes");
        fclose(file_assinaturas);
        return;
    }

    // Loop para percorrer todos os pacotes
    while (fread(&temp_pack, sizeof(temp_pack), 1, file_packs)) {
        printf("Pacote: %s\n", temp_pack.idprods);  // Exibe o nome do pacote
        printf("Assinaturas:\n");
        printf("ID Assinatura | CPF Cliente        | Status\n");
        printf("------------------------------------------------\n");

        // Loop para percorrer todas as assinaturas
        encontrou = 0;  // Para verificar se encontramos assinaturas para esse pacote
        fseek(file_assinaturas, 0, SEEK_SET);  // Reseta o ponteiro para o começo do arquivo de assinaturas
        while (fread(&temp_assinatura, sizeof(temp_assinatura), 1, file_assinaturas)) {
            if (atoi(temp_assinatura.idpack) == temp_pack.idpack) {
                printf("%-15d | %-18s | %s\n", 
                       temp_assinatura.idassinatura, temp_assinatura.cpf, 
                       temp_assinatura.status == 0 ? "Ativo" : "Inativo");
                encontrou = 1;
            }
        }

        if (!encontrou) {
            printf("Nenhuma assinatura encontrada para este pacote.\n");
        }

        printf("------------------------------------------------\n");
    }

    fclose(file_assinaturas);
    fclose(file_packs);

    printf("║                                                                      ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════╝\n");
    printf("  ──────────────────Pressione <ENTER> para continuar──────────────────  \n");
    getchar();
}


void relatorios_simples(void) {
    char opcao;
    do {
        system("clear||cls");
        printf("\n");
        printf("╔══════════════════════════════-SIG-BEER-══════════════════════════════╗\n");
        printf("║                                                                      ║\n");
        printf("║                          RELATÓRIOS SIMPLES                          ║\n");
        printf("║                                                                      ║\n");
        printf("╟──────────────────────────────────────────────────────────────────────╢\n");
        printf("║                                                                      ║\n");
        printf("║                     1. PRODUTOS                                      ║\n");
        printf("║                     2. PACKS                                         ║\n");
        printf("║                     3. ASSINATURAS                                   ║\n");
        printf("║                     4. CLIENTES                                      ║\n");
        printf("║                     0. VOLTAR                                        ║\n");
        printf("║                                                                      ║\n");
        printf("╚══════════════════════════════════════════════════════════════════════╝\n");
        printf("                         Escolha uma opção: ");
        scanf("%c", &opcao);
        getchar();

        switch (opcao) {
            case '1': listar_produtos(); 
            break;
            case '2': listar_packs(); 
            break;
            case '3': listar_assinaturas(); 
            break;
            case '4': listar_clientes(); 
            break;
        }
    } while (opcao != '0');
}

void listar_produtos(void) {
    system("clear||cls");
    printf("\n");
    printf("╔══════════════════════════════-SIG-BEER-══════════════════════════════╗\n");
    printf("║                                                                      ║\n");
    printf("║                          LISTA DE PRODUTOS                           ║\n");
    printf("║                                                                      ║\n");
    printf("╟──────────────────────────────────────────────────────────────────────╢\n");
    for (int i = 0; i < total_produtos; i++) {
        if (lista_produtos[i].status == 0) {
            printf("ID: %d\n", lista_produtos[i].id);
            printf("Nome: %s\n", lista_produtos[i].nomeprod);
            printf("Teor alcoólico: %s%%\n", lista_produtos[i].teor);
            printf("Amargor: %c\n", lista_produtos[i].amargor);
            printf("Quantidade: %s ml\n", lista_produtos[i].quant);
            printf("─────────────────────────────────────────────────────\n");
        }
    }
    printf("Pressione <ENTER> para voltar.\n");
    getchar();
}

void listar_packs(void) {
    system("clear||cls");
    printf("\n");
    printf("╔══════════════════════════════-SIG-BEER-══════════════════════════════╗\n");
    printf("║                                                                      ║\n");
    printf("║                             LISTA DE PACKS                           ║\n");
    printf("║                                                                      ║\n");
    printf("╟──────────────────────────────────────────────────────────────────────╢\n");
    FILE *fp = fopen(ARQUIVO_PACKS, "rb");
    if (!fp) {
        printf("Erro ao abrir o arquivo de packs.\n");
        printf("Pressione <ENTER> para voltar.\n");
        getchar();
        return;
    }

    struct pack temp_pack;
    while (fread(&temp_pack, sizeof(struct pack), 1, fp)) {
        if (temp_pack.status == '0') {
            printf("ID Pack: %d\n", temp_pack.idpack);
            printf("Nome: %s\n", temp_pack.nomepack);
            printf("Produtos: %s\n", temp_pack.idprods);
            printf("─────────────────────────────────────────────────────\n");
        }
    }

    fclose(fp);
    printf("Pressione <ENTER> para voltar.\n");
    getchar();
}


void listar_assinaturas(void) {
    system("clear||cls");
    printf("\n");
    printf("╔══════════════════════════════-SIG-BEER-══════════════════════════════╗\n");
    printf("║                                                                      ║\n");
    printf("║                        LISTA DE ASSINATURAS                          ║\n");
    printf("║                                                                      ║\n");
    printf("╟──────────────────────────────────────────────────────────────────────╢\n");

    FILE *file = fopen(ARQUIVO_ASSINA, "rb");
    if (!file) {
        printf("Erro ao abrir o arquivo de assinaturas.\n");
        printf("Pressione <ENTER> para voltar.\n");
        getchar();
        return;
    }

    struct assinatura temp_assinatura;
    while (fread(&temp_assinatura, sizeof(temp_assinatura), 1, file)) {
        printf("ID Assinatura: %d\n", temp_assinatura.idassinatura);
        printf("CPF Cliente: %s\n", temp_assinatura.cpf);
        printf("ID Pack: %s\n", temp_assinatura.idpack);
        printf("Status: %s\n", temp_assinatura.status == 0 ? "Ativo" : "Inativo");
        printf("─────────────────────────────────────────────────────\n");
    }

    fclose(file);
    printf("Pressione <ENTER> para voltar.\n");
    getchar();
}

void listar_clientes(void) {
    system("clear||cls");
    printf("\n");
    printf("╔══════════════════════════════-SIG-BEER-══════════════════════════════╗\n");
    printf("║                                                                      ║\n");
    printf("║                           LISTA DE CLIENTES                          ║\n");
    printf("║                                                                      ║\n");
    printf("╟──────────────────────────────────────────────────────────────────────╢\n");

    FILE *file = fopen("clientes.dat", "rb"); // Supondo que os dados de clientes estejam em "clientes.dat"
    if (!file) {
        printf("Erro ao abrir o arquivo de clientes.\n");
        printf("Pressione <ENTER> para voltar.\n");
        getchar();
        return;
    }

    struct Cliente temp_cliente;
    while (fread(&temp_cliente, sizeof(temp_cliente), 1, file)) {
        printf("Email Cliente: %s\n", temp_cliente.email);
        printf("Nome: %s\n", temp_cliente.nome);
        printf("CPF: %s\n", temp_cliente.cpf);
        printf("─────────────────────────────────────────────────────\n");
    }

    fclose(file);
    printf("Pressione <ENTER> para voltar.\n");
    getchar();
}

void relatorio_compras_cliente(void) {
    FILE *file_clientes, *file_assinaturas, *file_packs, *file_produtos;
    struct Cliente temp_cliente;
    struct assinatura temp_assinatura;
    struct pack temp_pack;
    struct Produtos temp_produto;
    char cpf_busca[15];
    int encontrou_cliente = 0;

    system("clear||cls");
    printf("\n");
    printf("╔══════════════════════════════-SIG-BEER-══════════════════════════════╗\n");
    printf("║                                                                      ║\n");
    printf("║                   RELATÓRIO DE COMPRAS POR CLIENTE                   ║\n");
    printf("║                                                                      ║\n");
    printf("╟──────────────────────────────────────────────────────────────────────╢\n");

    printf("Informe o CPF do cliente: ");
    scanf("%14s", cpf_busca);
    getchar();

    // Abrir arquivo de clientes
    file_clientes = fopen("clientes.dat", "rb");
    if (!file_clientes) {
        perror("Erro ao abrir o arquivo de clientes");
        return;
    }

    // Buscar cliente pelo CPF
    while (fread(&temp_cliente, sizeof(temp_cliente), 1, file_clientes)) {
        if (strcmp(temp_cliente.cpf, cpf_busca) == 0) {
            printf("\nCliente: %s (CPF: %s)\n", temp_cliente.nome, temp_cliente.cpf);
            encontrou_cliente = 1;
            break;
        }
    }
    fclose(file_clientes);

    if (!encontrou_cliente) {
        printf("Nenhum cliente encontrado com o CPF %s.\n", cpf_busca);
        printf("╚══════════════════════════════════════════════════════════════════════╝\n");
        printf("  ──────────────────Pressione <ENTER> para continuar──────────────────  \n");
        getchar();
        return;
    }

    // Abrir arquivo de assinaturas
    file_assinaturas = fopen("assinaturas.dat", "rb");
    if (!file_assinaturas) {
        perror("Erro ao abrir o arquivo de assinaturas");
        return;
    }

    file_packs = fopen("packs.dat", "rb");
    if (!file_packs) {
        perror("Erro ao abrir o arquivo de pacotes");
        fclose(file_assinaturas);
        return;
    }

    file_produtos = fopen("produtos.dat", "rb");
    if (!file_produtos) {
        perror("Erro ao abrir o arquivo de produtos");
        fclose(file_assinaturas);
        fclose(file_packs);
        return;
    }

    printf("\nCompras realizadas:\n");
    printf("--------------------------------------------------------------\n");

    // Buscar assinaturas do cliente
    while (fread(&temp_assinatura, sizeof(temp_assinatura), 1, file_assinaturas)) {
        if (strcmp(temp_assinatura.cpf, cpf_busca) == 0) {
            // Buscar informações do pack correspondente
            fseek(file_packs, 0, SEEK_SET);  // Resetar para o início do arquivo
            while (fread(&temp_pack, sizeof(temp_pack), 1, file_packs)) {
                if (temp_pack.idpack == atoi(temp_assinatura.idpack)) {
                    printf("Pacote: %s\n", temp_pack.nomepack);
                    printf("Produtos incluídos:\n");

                    // Buscar produtos do pack
                    char *id_produto = strtok(temp_pack.idprods, ";");
                    while (id_produto != NULL) {
                        fseek(file_produtos, 0, SEEK_SET);
                        while (fread(&temp_produto, sizeof(temp_produto), 1, file_produtos)) {
                            if (temp_produto.id == atoi(id_produto)) {
                                printf("- %s\n", temp_produto.nomeprod);
                            }
                        }
                        id_produto = strtok(NULL, ";");
                    }
                    printf("\n");
                }
            }
        }
    }

    fclose(file_assinaturas);
    fclose(file_packs);
    fclose(file_produtos);

    printf("╚══════════════════════════════════════════════════════════════════════╝\n");
    printf("  ──────────────────Pressione <ENTER> para continuar──────────────────  \n");
    getchar();
}
