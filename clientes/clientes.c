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

#define ARQUIVO_CLIENTES "clientes.dat" //feito pelo gpt

void salvar_cliente(struct Cliente *cliente) {
    FILE *fp = fopen(ARQUIVO_CLIENTES, "ab");  
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo para salvar os dados do cliente.\n");
        return;
    }
    fwrite(cliente, sizeof(struct Cliente), 1, fp);  
    fclose(fp);
}

void carregar_clientes(void) {
    FILE *fp = fopen(ARQUIVO_CLIENTES, "rb");  
    if (fp == NULL) {
        printf("Nenhum cliente cadastrado.\n");
        return;
    }

    struct Cliente cliente;
    printf("\nClientes cadastrados:\n");
    while (fread(&cliente, sizeof(struct Cliente), 1, fp)) {  
        if (cliente.status == 1) {  
            printf("CPF: %s\nNome: %s\nData de Nascimento: %s\nEndereço: %s\nTelefone: %s\nE-mail: %s\n\n",
                   cliente.cpf, cliente.nome, cliente.dat_nasc, cliente.endereco, cliente.telefone, cliente.email);
        }
    }
    fclose(fp);
}


void atualizar_arquivo(struct Cliente *clientes, int qtd_clientes) {
    FILE *fp = fopen(ARQUIVO_CLIENTES, "ab"); 
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo para atualizar os dados dos clientes.\n");
        return;
    }
    fwrite(clientes, sizeof(struct Cliente), qtd_clientes, fp);  
    fclose(fp);
}

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
    struct Cliente novo_cliente;  
    int teste;

    system("clear||cls");
    printf("\n");
    printf("╔══════════════════════════════-SIG-BEER-══════════════════════════════╗\n");
    printf("║                                                                      ║\n");
    printf("║                          CADASTRAR CLIENTE                           ║\n");
    printf("║                                                                      ║\n");
    printf("╟──────────────────────────────────────────────────────────────────────╢\n");

    do {
        printf("                      -> CPF (formato xxx.xxx.xxx-xx): ");
        fgets(novo_cliente.cpf, sizeof(novo_cliente.cpf), stdin);
        novo_cliente.cpf[strcspn(novo_cliente.cpf, "\n")] = '\0';
        teste = validarCPF(novo_cliente.cpf);
    } while (!teste);

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
    while (getchar() != '\n'); 
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
    novo_cliente.status = '0';
    salvar_cliente(&novo_cliente);  

    printf("Cliente cadastrado com sucesso!\n");
    printf("  ──────────────────Pressione <ENTER> para continuar──────────────────  \n");
    getchar();
}

void pesquisar_clientes(void) {
    char cpf_busca[16];
    struct Cliente cliente;
    int encontrado = 0;

    system("clear||cls");
    printf("\n╔══════════════════════════════-SIG-BEER-══════════════════════════════╗\n");
    printf("║                          PESQUISAR CLIENTE                           ║\n");
    printf("╟──────────────────────────────────────────────────────────────────────╢\n");
    printf("                    -> CPF (formato xxx.xxx.xxx-xx): ");
    fgets(cpf_busca, sizeof(cpf_busca), stdin);
    cpf_busca[strcspn(cpf_busca, "\n")] = '\0';

    FILE *fp = fopen(ARQUIVO_CLIENTES, "rb");// adptado do gpt
    if (fp == NULL) {
        printf("Nenhum cliente cadastrado.\n");
        return;
    }

    while (fread(&cliente, sizeof(struct Cliente), 1, fp)) {
        if(cliente.status == '0'){
            if (strcmp(cliente.cpf, cpf_busca) == 0) {
                printf("Cliente encontrado:\n");
                printf("                    CPF: %s\n                    Nome: %s\n                    Data de Nascimento: %s\n                    Endereço: %s\n                    Telefone: %s\n                    E-mail: %s\n",
                    cliente.cpf, cliente.nome, cliente.dat_nasc, cliente.endereco, cliente.telefone, cliente.email);
                encontrado = 1;
                break;
            }
        }
    }
    if (!encontrado) {
        printf("                    Cliente com CPF %s não encontrado.\n", cpf_busca);
    }

    fclose(fp);
    printf("  ──────────────────Pressione <ENTER> para continuar──────────────────  \n");
    getchar();
}



void atualizar_clientes(void) {
    struct Cliente novo_cliente;
    int teste, encontrado = 0;
    FILE *fp, *fp_temp;
    struct Cliente cliente;

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
        getchar(); 

        teste = validarCPF(novo_cliente.cpf);
        if (!teste) {
            printf("                      CPF inválido. Tente novamente.\n");
        }
    } while (!teste);

    
    fp = fopen("clientes.dat", "rb");
    fp_temp = fopen("temp.dat", "wb");
    if (!fp || !fp_temp) {
        printf("                    Erro ao acessar o arquivo!\n");
        return;
    }

    while (fread(&cliente, sizeof(struct Cliente), 1, fp) == 1) {
        if (strcmp(cliente.cpf, novo_cliente.cpf) == 0) {
            encontrado = 1;

            printf("                      -> NOVO NOME: ");
            fgets(novo_cliente.nome, sizeof(novo_cliente.nome), stdin);
            novo_cliente.nome[strcspn(novo_cliente.nome, "\n")] = '\0';
            getchar();

            printf("                      -> NOVA DATA DE NASCIMENTO: ");
            fgets(novo_cliente.dat_nasc, sizeof(novo_cliente.dat_nasc), stdin);
            novo_cliente.dat_nasc[strcspn(novo_cliente.dat_nasc, "\n")] = '\0';
            getchar();

            printf("                      -> NOVO ENDEREÇO: ");
            fgets(novo_cliente.endereco, sizeof(novo_cliente.endereco), stdin);
            novo_cliente.endereco[strcspn(novo_cliente.endereco, "\n")] = '\0';
            getchar();

            printf("                      -> NOVO TELEFONE: ");
            fgets(novo_cliente.telefone, sizeof(novo_cliente.telefone), stdin);
            novo_cliente.telefone[strcspn(novo_cliente.telefone, "\n")] = '\0';
            getchar();

            printf("                      -> NOVO E-MAIL: ");
            fgets(novo_cliente.email, sizeof(novo_cliente.email), stdin);
            novo_cliente.email[strcspn(novo_cliente.email, "\n")] = '\0';
            getchar();

 
            fwrite(&novo_cliente, sizeof(struct Cliente), 1, fp_temp);
        } else {
            fwrite(&cliente, sizeof(struct Cliente), 1, fp_temp);
        }
    }

    fclose(fp);
    fclose(fp_temp);

    remove("clientes.dat");
    rename("temp.dat", "clientes.dat");

    if (encontrado) {
        printf("                      Cliente atualizado com sucesso!\n");
    } else {
        printf("                      Cliente não encontrado.\n");
    }

    printf("║                                                                      ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════╝\n");
    printf("  ──────────────────Pressione <ENTER> para continuar──────────────────  \n");
    getchar();
}




void remover_clientes(void) { // adpatado do gpt
    char cpf_busca[16];
    struct Cliente cliente;
    int encontrado = 0;
    FILE *fp, *fp_temp;

    system("clear||cls");
    printf("\n╔══════════════════════════════-SIG-BEER-══════════════════════════════╗\n");
    printf("║                          REMOVER CLIENTE                            ║\n");
    printf("╟──────────────────────────────────────────────────────────────────────╢\n");
    printf("                    -> CPF (formato xxx.xxx.xxx-xx): ");
    fgets(cpf_busca, sizeof(cpf_busca), stdin);
    cpf_busca[strcspn(cpf_busca, "\n")] = '\0';

    fp = fopen(ARQUIVO_CLIENTES, "rb");
    fp_temp = fopen("temp.dat", "wb");  
    if (fp == NULL || fp_temp == NULL) {
        printf("                    Erro ao abrir o arquivo de clientes.\n");
        return;
    }

    while (fread(&cliente, sizeof(struct Cliente), 1, fp)) {
        if (strcmp(cliente.cpf, cpf_busca) == 0) {
            encontrado = 1;
            cliente.status = 1;
            printf("                    Cliente marcado como removido.\n");
        }
        
        fwrite(&cliente, sizeof(struct Cliente), 1, fp_temp);
    }

    fclose(fp);
    fclose(fp_temp);

    
    remove(ARQUIVO_CLIENTES);
    rename("temp.dat", ARQUIVO_CLIENTES);

    if (!encontrado) {
        printf("                    Cliente não encontrado.\n");
    }

    printf("  ──────────────────Pressione <ENTER> para continuar──────────────────  \n");
    getchar();
}