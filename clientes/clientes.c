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

void cadastrar_clientes(void){
    char cpf[16];
    char nome[52];
    char dat_nasc[12];
    char endereco[52];
    char email[52];
    char telefone[20];      
    char telefoneLimpo[12];  
    int teste;
    system("clear||cls");
    printf("\n");
    printf("╔══════════════════════════════-SIG-BEER-══════════════════════════════╗\n");
    printf("║                                                                      ║\n");
    printf("║                          CADASTRAR CLIENTE                           ║\n");
    printf("║                                                                      ║\n");
    printf("╟──────────────────────────────────────────────────────────────────────╢\n");
    printf("║                                                                      ║\n");
    printf("                      -> CPF (formato xxx.xxx.xxx-xx): ");
    scanf("%14s", cpf);
    getchar();
    printf("                      -> NOME COMPLETO: ");
    scanf("%50s", nome);
    getchar();
    printf("                      -> DATA DE NASCIMENTO (dd/mm/aaaa): ");
    do{
    fgets(dat_nasc, sizeof(dat_nasc), stdin);
    dat_nasc[strcspn(dat_nasc, "\n")] = '\0';
    teste = validarData(dat_nasc);
    if (!validarData(dat_nasc)) {
        printf("                      Data inválida. Tente novamente.\n");
    }
    }while (!teste);
    
    printf("                      -> ENDEREÇO: ");
    scanf("%50s", endereco);
    getchar();
    printf("                      -> CELULAR (Apenas números): ");

    do {
        fgets(telefone, sizeof(telefone), stdin);
        telefone[strcspn(telefone, "\n")] = '\0';
        limparNumero(telefoneLimpo, telefone);
        teste = validarTelefone(telefoneLimpo);
        if (!teste) {
            printf("                      Telefone inválido. Tente novamente.\n");
        }
    } while (!teste); 
    printf("                      -> E-MAIL: ");
    do {
        printf("Digite um e-mail: ");
        fgets(email, sizeof(email), stdin);

        // Remover a quebra de linha adicionada pelo fgets
        email[strcspn(email, "\n")] = '\0';

        teste = validarEmail(email);
        if (!teste) {
            printf("E-mail inválido. Tente novamente.\n");
        }
    } while (!teste);
    printf("║                                                                      ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════╝\n");
    printf("  ──────────────────Pressione <ENTER> para continuar──────────────────  \n");
    getchar();
}

void pesquisar_clientes(void){
    char cpf[16];
    system("clear||cls");
    printf("\n");
    printf("╔══════════════════════════════-SIG-BEER-══════════════════════════════╗\n");
    printf("║                                                                      ║\n");
    printf("║                          PESQUISAR CLIENTE                           ║\n");
    printf("║                                                                      ║\n");
    printf("╟──────────────────────────────────────────────────────────────────────╢\n");
    printf("║                                                                      ║\n");
    printf("                    -> CPF (formato xxx.xxx.xxx-xx): ");
    scanf("%14s", cpf);
    getchar();
    printf("║                                                                      ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════╝\n");
    printf("  ──────────────────Pressione <ENTER> para continuar──────────────────  \n");
    getchar();
}

void atualizar_clientes(void){
    char cpf[16];
    system("clear||cls");
    printf("\n");
    printf("╔══════════════════════════════-SIG-BEER-══════════════════════════════╗\n");
    printf("║                                                                      ║\n");
    printf("║                          ATUALIZAR CLIENTE                           ║\n");
    printf("║                                                                      ║\n");
    printf("╟──────────────────────────────────────────────────────────────────────╢\n");
    printf("║                                                                      ║\n");
    printf("                    -> CPF (formato xxx.xxx.xxx-xx): ");
    scanf("%14s", cpf);
    getchar();
    printf("║                                                                      ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════╝\n");
    printf("  ──────────────────Pressione <ENTER> para continuar──────────────────  \n");
    getchar();
}

void remover_clientes(void){
    char cpf[16];
    system("clear||cls");
    printf("\n");
    printf("╔══════════════════════════════-SIG-BEER-══════════════════════════════╗\n");
    printf("║                                                                      ║\n");
    printf("║                           REMOVER CLIENTE                            ║\n");
    printf("║                                                                      ║\n");
    printf("╟──────────────────────────────────────────────────────────────────────╢\n");
    printf("║                                                                      ║\n");
    printf("                    -> CPF (formato xxx.xxx.xxx-xx): ");
    scanf("%14s", cpf);
    getchar();
    printf("║                                                                      ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════╝\n");
    printf("  ──────────────────Pressione <ENTER> para continuar──────────────────  \n");
    getchar();
}
