/*
╔═════════════════════════════════════════════════════════════════╗
║              M Ó D U L O  A S S I N A T U R A S                 ║
╚═════════════════════════════════════════════════════════════════╝
*/

#include <stdio.h>
#include <stdlib.h>
#include "assinaturas.h"

void modulo_assinaturas(void) {
    char opcao;
    do {
        opcao = menu_assinaturas();
        switch (opcao) {
            case '1': cadastrar_assinaturas();
            break;
            case '2': pesquisar_assinaturas();
            break;
            case '3': cancelar_assinaturas();
            break;
        }
    } while (opcao != '0');
}

#define ARQUIVO_ASSINA "assinatura.dat" //feito pelo gpt


void salvar_assinatura(struct assinatura *assinatura) {
    FILE *fp = fopen(ARQUIVO_ASSINA, "ab");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo para salvar os dados do cliente.\n");
        return;
    }
    fwrite(assinatura, sizeof(struct assinatura), 1, fp);
    fclose(fp);
}


void carregar_assinatura(void) {
    FILE *fp = fopen(ARQUIVO_ASSINA, "rb");
    if (fp == NULL) {
        printf("Nenhum cliente cadastrado.\n");
        return;
    }

    struct assinatura assinatura;
    printf("\nClientes cadastrados:\n");
    while (fread(&assinatura, sizeof(struct assinatura), 1, fp)) {
        if (assinatura.status == 1) {
            printf("ID da Assinatura: %d\n", assinatura.idassinatura);
            printf("CPF do Cliente: %s\n", assinatura.cpf);
            printf("ID do Pack: %s\n\n", assinatura.idpack);
        }
    }
    fclose(fp);
}


void atualizar_arquivo_assinatura(struct assinatura *assinaturas, int qtd_assinaturas) {
    FILE *fp = fopen(ARQUIVO_ASSINA, "wb");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo para atualizar os dados dos clientes.\n");
        return;
    }
    fwrite(assinaturas, sizeof(struct assinatura), qtd_assinaturas, fp);
    fclose(fp);
}

void remover_ass_por_id(const char *id) {
    FILE *fp = fopen("assinatura.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");
    struct assinatura nAss;
    int encontrado = 0;

    if (fp == NULL || temp == NULL) {
        printf("Erro ao acessar os arquivos.\n");
        if (fp) fclose(fp);
        if (temp) fclose(temp);
        return;
    }

    while (fread(&nAss, sizeof(struct assinatura), 1, fp)) {
        if (nAss.idassinatura == atoi(id)) {  
            nAss.status = 1; 
            encontrado = 1;
        }
        fwrite(&nAss, sizeof(struct assinatura), 1, temp);
    }

    fclose(fp);
    fclose(temp);

    if (encontrado) {
        remove("assinatura.dat");
        rename("temp.dat", "assinatura.dat");
        printf("Assinatura removida com sucesso.\n");
    } else {
        remove("temp.dat");
        printf("Assinatura com ID %s não encontrada.\n", id);
    }
}


char menu_assinaturas(void){
    char op;
    system("clear||cls");
    printf("\n");
    printf("╔══════════════════════════════-SIG-BEER-══════════════════════════════╗\n");
    printf("║                                                                      ║\n");
    printf("║                           MENU ASSINATURAS                           ║\n");
    printf("║                                                                      ║\n");
    printf("╟──────────────────────────────────────────────────────────────────────╢\n");
    printf("║                                                                      ║\n");
    printf("║                     1. CADASTRAR NOVA ASSINATURA                     ║\n");
    printf("║                     2. LISTAR ASSINATURAS                            ║\n");
    printf("║                     3. CANCELAR UMA ASSINATURA                       ║\n");
    printf("║                     0. VOLTAR                                        ║\n");
    printf("║                                                                      ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════╝\n");
    printf("                         Escolha uma opção: ");
    scanf("%c", &op);
    getchar();
    return op;
}

void cadastrar_assinaturas(void){
    FILE *file;
    struct assinatura nova_assinatura;  
    int teste, count = 0;
    system("clear||cls");
    printf("\n");
    printf("╔══════════════════════════════-SIG-BEER-══════════════════════════════╗\n");
    printf("║                                                                      ║\n");
    printf("║                         CADASTRAR ASSINATURA                         ║\n");
    printf("║                                                                      ║\n");
    printf("╟──────────────────────────────────────────────────────────────────────╢\n");
    printf("║                                                                      ║\n");
    do {
        printf("                      -> CPF (formato xxx.xxx.xxx-xx): ");
        fgets(nova_assinatura.cpf, sizeof(nova_assinatura.cpf), stdin);
        nova_assinatura.cpf[strcspn(nova_assinatura.cpf, "\n")] = '\0';
        teste = validarCPF(nova_assinatura.cpf);
        if (!teste) {
            printf("CPF inválido! Tente novamente.\n");
        }
    } while (!teste);

    file = fopen(ARQUIVO_ASSINA, "ab+");
    if (!file) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    struct assinatura temp;
    while (fread(&temp, sizeof(temp), 1, file)) {
        count++;
    }
    fclose(file);

    nova_assinatura.idassinatura = count + 1; 
    nova_assinatura.status = 0; 

    
    printf("                      -> ID do Pacote: ");
    fgets(nova_assinatura.idpack, sizeof(nova_assinatura.idpack), stdin);
    nova_assinatura.idpack[strcspn(nova_assinatura.idpack, "\n")] = '\0';

    salvar_assinatura(&nova_assinatura);
    
    getchar();  
    printf("║                                                                      ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════╝\n");
    printf("  ──────────────────Pressione <ENTER> para continuar──────────────────  \n");
    getchar();
}

void pesquisar_assinaturas(void) {
    struct assinatura nAss;
    FILE *fp;

    system("clear||cls");
    printf("\n");
    printf("╔══════════════════════════════-SIG-BEER-══════════════════════════════╗\n");
    printf("║                                                                      ║\n");
    printf("║                         LISTAR ASSINATURAS                          ║\n");
    printf("║                                                                      ║\n");
    printf("╟──────────────────────────────────────────────────────────────────────╢\n");
    printf("║                                                                      ║\n");

    fp = fopen(ARQUIVO_ASSINA, "rb");
    if (fp == NULL) {
        printf("                   -> Nenhuma assinatura encontrada.\n");
        printf("Pressione <ENTER> para voltar ao menu...\n");
        getchar();
        return;
    }


    int encontrou = 0;
    while (fread(&nAss, sizeof(struct assinatura), 1, fp)) {
        if(nAss.status == 0){
        encontrou = 1;
        printf("                   -> ID da Assinatura: %d\n", nAss.idassinatura);
        printf("                   -> CPF: %s\n", nAss.cpf);
        printf("                   -> ID do Pacote: %s\n", nAss.idpack);
        printf("                   -> Status: %s\n", nAss.status == 0 ? "Ativo" : "Inativo");
        printf("║                                                                      ║\n");
    }
    }
    if (!encontrou) {
        printf("                   -> Nenhuma assinatura registrada.\n");
    }

    fclose(fp);

    printf("║                                                                      ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════╝\n");
    printf("  ──────────────────Pressione <ENTER> para continuar──────────────────  \n");
    getchar();
}



void cancelar_assinaturas(void) {
    char id[12];
    system("clear||cls");
    printf("\n");
    printf("╔══════════════════════════════-SIG-BEER-══════════════════════════════╗\n");
    printf("║                                                                      ║\n");
    printf("║                         CANCELAR ASSINATURA                          ║\n");
    printf("║                                                                      ║\n");
    printf("╟──────────────────────────────────────────────────────────────────────╢\n");
    printf("║                                                                      ║\n");
    printf("                   -> INSIRA O ID DA ASSINATURA: ");
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = '\0';
    remover_ass_por_id(id);
    printf("║                                                                      ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════╝\n");
    printf("  ──────────────────Pressione <ENTER> para continuar──────────────────  \n");
    getchar();
}