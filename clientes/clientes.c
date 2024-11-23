/*
╔═════════════════════════════════════════════════════════════════╗
║                  M Ó D U L O  C L I E N T E S                   ║
╚═════════════════════════════════════════════════════════════════╝
*/

#include <stdio.h>
#include <stdlib.h>
#include "clientes.h"
#include <string.h>
#include "../validacoes/validacoes.h"




void modulo_clientes(void) {
    char opcao;
    do {
        opcao = menu_clientes();
        switch (opcao) {
            case '1': cadastrar_clientes();
            break;
            case '2': pesquisar_clientes();
            break;
            case '3': atualizar_clientes();
            break;
            case '4': remover_clientes();
            break;
        }
    } while (opcao != '0');
}


char menu_clientes(void){
    char op;
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
    printf("                         Escolha uma opção: ");
    scanf("%c", &op);
    getchar();
    return op;
}

void cadastrar_clientes(void) {
    struct Cliente novo_cliente;  // Variável do tipo Cliente
    int teste;

    system("clear||cls");
    printf("\n");
    printf("╔══════════════════════════════-SIG-BEER-══════════════════════════════╗\n");
    printf("║                                                                      ║\n");
    printf("║                          CADASTRAR CLIENTE                           ║\n");
    printf("║                                                                      ║\n");
    printf("╟──────────────────────────────────────────────────────────────────────╢\n");

    do{
    printf("                      -> CPF (formato xxx.xxx.xxx-xx): ");
    fgets(novo_cliente.cpf, sizeof(novo_cliente.cpf), stdin);
    novo_cliente.cpf[strcspn(novo_cliente.cpf, "\n")] = '\0';
    teste = validarCPF(novo_cliente.cpf);
    }while(!teste);

    printf("                      -> NOME COMPLETO: ");
    fgets(novo_cliente.nome, sizeof(novo_cliente.nome), stdin);
    novo_cliente.nome[strcspn(novo_cliente.nome, "\n")] = '\0';

    printf("                      -> DATA DE NASCIMENTO (dd/mm/aaaa): ");
    do {
        fgets(novo_cliente.dat_nasc, sizeof(novo_cliente.dat_nasc), stdin);
        novo_cliente.dat_nasc[strcspn(novo_cliente.dat_nasc, "\n")] = '\0';
        teste = validarData(novo_cliente.dat_nasc);
        if (!teste) {
            printf("                      Data inválida. Tente novamente.\n");
        }
    } while (!teste);

    printf("                      -> ENDEREÇO: ");
    fgets(novo_cliente.endereco, sizeof(novo_cliente.endereco), stdin);
    novo_cliente.endereco[strcspn(novo_cliente.endereco, "\n")] = '\0';

    printf("                      -> CELULAR (Apenas números): ");
    do {
        fgets(novo_cliente.telefone, sizeof(novo_cliente.telefone), stdin);
        novo_cliente.telefone[strcspn(novo_cliente.telefone, "\n")] = '\0';
        teste = validarTelefone(novo_cliente.telefone);
        if (!teste) {
            printf("                      Telefone inválido. Tente novamente.\n");
        }
    } while (!teste);

    printf("                      -> E-MAIL: ");
    do {
        fgets(novo_cliente.email, sizeof(novo_cliente.email), stdin);
        novo_cliente.email[strcspn(novo_cliente.email, "\n")] = '\0';
        teste = validarEmail(novo_cliente.email);
        if (!teste) {
            printf("                      E-mail inválido. Tente novamente.\n");
        }
    } while (!teste);

    printf("║                                                                      ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════╝\n");
    printf("  ──────────────────Pressione <ENTER> para continuar──────────────────  \n");
    getchar();
}


void pesquisar_clientes(void) {
    struct Cliente novo_cliente;
    int teste;

    system("clear||cls");
    printf("\n");
    printf("╔══════════════════════════════-SIG-BEER-══════════════════════════════╗\n");
    printf("║                                                                      ║\n");
    printf("║                          PESQUISAR CLIENTE                           ║\n");
    printf("║                                                                      ║\n");
    printf("╟──────────────────────────────────────────────────────────────────────╢\n");

    do {
        printf("                    -> CPF (formato xxx.xxx.xxx-xx): ");
        scanf("%14s", novo_cliente.cpf);
        getchar();  // Limpa o buffer para evitar problemas com entrada

        teste = validarCPF(novo_cliente.cpf);
        if (!teste) {
            printf("                      CPF inválido. Tente novamente.\n");
        }
    } while (!teste);  // Repete enquanto o CPF não for válido

    printf("║                                                                      ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════╝\n");
    printf("  ──────────────────Pressione <ENTER> para continuar──────────────────  \n");
    getchar();
}


void atualizar_clientes(void) {
    struct Cliente novo_cliente;
    int teste;

    system("clear||cls");
    printf("\n");
    printf("╔══════════════════════════════-SIG-BEER-══════════════════════════════╗\n");
    printf("║                                                                      ║\n");
    printf("║                          ATUALIZAR CLIENTE                           ║\n");
    printf("║                                                                      ║\n");
    printf("╟──────────────────────────────────────────────────────────────────────╢\n");

    do {
        printf("                    -> CPF (formato xxx.xxx.xxx-xx): ");
        scanf("%14s", novo_cliente.cpf);
        getchar();  // Limpa o buffer de entrada para evitar problemas

        teste = validarCPF(novo_cliente.cpf);  // Valida o CPF informado
        if (!teste) {
            printf("                      CPF inválido. Tente novamente.\n");
        }
    } while (!teste);  // Repete a solicitação enquanto o CPF não for válido

    printf("║                                                                      ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════╝\n");
    printf("  ──────────────────Pressione <ENTER> para continuar──────────────────  \n");
    getchar();
}


void remover_clientes(void) {
    struct Cliente novo_cliente;
    int teste;

    system("clear||cls");
    printf("\n");
    printf("╔══════════════════════════════-SIG-BEER-══════════════════════════════╗\n");
    printf("║                                                                      ║\n");
    printf("║                           REMOVER CLIENTE                            ║\n");
    printf("║                                                                      ║\n");
    printf("╟──────────────────────────────────────────────────────────────────────╢\n");

    do {
        printf("                    -> CPF (formato xxx.xxx.xxx-xx): ");
        scanf("%14s", novo_cliente.cpf);
        getchar();  // Limpa o buffer de entrada para evitar problemas de leitura

        teste = validarCPF(novo_cliente.cpf);  // Chama a função para validar o CPF
        if (!teste) {
            printf("                      CPF inválido. Tente novamente.\n");
        }
    } while (!teste);  // Repete enquanto o CPF não for válido

    printf("║                                                                      ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════╝\n");
    printf("  ──────────────────Pressione <ENTER> para continuar──────────────────  \n");
    getchar();
}
