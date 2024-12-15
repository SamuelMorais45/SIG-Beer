/*
╔══════════════════════════════════════════════════════════════╗
║                   M Ó D U L O  P A C K S                     ║
╚══════════════════════════════════════════════════════════════╝
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "packs.h"
#include "../validacoes/validacoes.h"

#define ARQUIVO_PACKS "packs.dat" // adptado do chat gpt


void carregar_packs(void) {
    FILE *fp = fopen(ARQUIVO_PACKS, "rb");
    if (fp == NULL) {
        printf("Nenhum dado encontrado. Um novo arquivo será criado.\n");
        return;
    }

    struct pack np;
    printf("Carregando packs do arquivo...\n");
    while (fread(&np, sizeof(struct pack), 1, fp)) {
        if (np.status == '0') {  
            printf("ID Pack: %d | Nome: %s | Produtos: %s\n", np.idpack, np.nomepack, np.idprods);
        }
    }
    fclose(fp);
}


void salvar_pack(struct pack *novo_pack) {
    FILE *fp = fopen(ARQUIVO_PACKS, "ab");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo para salvar os dados.\n");
        return;
    }
    fwrite(novo_pack, sizeof(struct pack), 1, fp);
    fclose(fp);
}


int gerar_id_pack(void) {
    FILE *fp = fopen(ARQUIVO_PACKS, "rb");
    if (fp == NULL) {
        return 1; 
    }

    struct pack np;
    int maior_id = 0;

    while (fread(&np, sizeof(struct pack), 1, fp)) {
        if (np.status == '0' && np.idpack > maior_id) {
            maior_id = np.idpack;  
        }
    }

    fclose(fp);
    return maior_id + 1; 
}


void remover_pack_por_id(const char *id) {
    FILE *fp = fopen(ARQUIVO_PACKS, "rb");
    FILE *temp = fopen("temp.dat", "wb");
    struct pack np;
    int encontrado = 0;

    if (fp == NULL || temp == NULL) {
        printf("Erro ao acessar os arquivos.\n");
        return;
    }

    while (fread(&np, sizeof(struct pack), 1, fp)) {
        if (np.idpack == atoi(id)) {  
            np.status = '1'; 
            fwrite(&np, sizeof(struct pack), 1, temp);
            encontrado = 1;
        } else {
            fwrite(&np, sizeof(struct pack), 1, temp);
        }
    }

    fclose(fp);
    fclose(temp);
    remove(ARQUIVO_PACKS);
    rename("temp.dat", ARQUIVO_PACKS);

    if (encontrado) {
        printf("Pack removido com sucesso.\n");
    } else {
        printf("Pack com ID %s não encontrado.\n", id);
    }
}


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
    struct pack np;
    int teste;
    system("clear||cls");
    printf("\n");
    printf("╔══════════════════════════════-SIG-BEER-══════════════════════════════╗\n");
    printf("║                                                                      ║\n");
    printf("║                           CADASTRAR PACK                             ║\n");
    printf("║                                                                      ║\n");
    printf("╟──────────────────────────────────────────────────────────────────────╢\n");

    do {
        printf("                        -> ID DOS 4 PRODUTOS: ");
        scanf("%20s", np.idprods);
        teste = verifica_numeros(np.idprods);
        if (!teste) {
            printf("                        ID inválido. Insira apenas números.\n");
        }
    } while (!teste);

    getchar();  

    do {
        
        printf("                        -> NOME DO PACK: ");
        fgets(np.nomepack, sizeof(np.nomepack), stdin); 

        
        np.nomepack[strcspn(np.nomepack, "\n")] = '\0'; 

        if (strlen(np.nomepack) == 0) {
            printf("                        Nome inválido. Não pode ser vazio.\n");
        }
    } while (strlen(np.nomepack) == 0);

    np.idpack = gerar_id_pack();  
    np.status = '0';  

    salvar_pack(&np);

    printf("║                                                                      ║\n");
    printf("                   Pack cadastrado com sucesso!\n");
    printf("╚══════════════════════════════════════════════════════════════════════╝\n");
    printf("  ──────────────────Pressione <ENTER> para continuar──────────────────  \n");
    
    getchar();
}



void pesquisar_packs(void) {
    struct pack np;
    char id_busca[12];
    int valido, encontrado = 0;

    system("clear||cls");
    printf("\n");
    printf("╔══════════════════════════════-SIG-BEER-══════════════════════════════╗\n");
    printf("║                                                                      ║\n");
    printf("║                            PESQUISAR PACK                            ║\n");
    printf("║                                                                      ║\n");
    printf("╟──────────────────────────────────────────────────────────────────────╢\n");
    printf("║                                                                      ║\n");

    do {
        printf("                       -> INSIRA O ID DO PACK: ");
        scanf("%11s", id_busca);
        getchar(); 
        valido = verifica_numeros(id_busca); 
        if (!valido) {
            printf("                        ID inválido. Insira apenas números.\n");
        }
    } while (!valido); 

    FILE *fp = fopen(ARQUIVO_PACKS, "rb");
    if (fp == NULL) {
        printf("                        Nenhum dado encontrado.\n");
    } else {
        while (fread(&np, sizeof(struct pack), 1, fp)) {
            if (np.status == '0' && np.idpack == atoi(id_busca)) {  
                encontrado = 1;
                printf("                        Pack encontrado!\n");
                printf("                        -> ID: %d\n", np.idpack);
                printf("                        -> Nome: %s\n", np.nomepack);
                printf("                        -> Produtos: %s\n", np.idprods);
                break;
            }
        }
        fclose(fp);

        if (!encontrado) {
            printf("                        Pack com ID %s não encontrado ou inativo.\n", id_busca);
        }
    }

    printf("║                                                                      ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════╝\n");
    printf("  ──────────────────Pressione <ENTER> para continuar──────────────────  \n");
    getchar(); 
}


void remover_packs(void) {
    char id[12];
    int valido;

    system("clear||cls");
    printf("\n");
    printf("╔══════════════════════════════-SIG-BEER-══════════════════════════════╗\n");
    printf("║                                                                      ║\n");
    printf("║                             REMOVER PACK                             ║\n");
    printf("║                                                                      ║\n");
    printf("╟──────────────────────────────────────────────────────────────────────╢\n");

    do {
        printf("                       -> INSIRA O ID DO PACK: ");
        scanf("%11s", id);
        getchar();
        valido = verifica_numeros(id);
        if (!valido) {
            printf("                        ID inválido. Insira apenas números.\n");
        }
    } while (!valido);

    remover_pack_por_id(id);

    printf("║                                                                      ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════╝\n");
    getchar();
}

