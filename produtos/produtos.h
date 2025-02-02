/*
╔═════════════════════════════════════════════════════════════════╗
║                  M Ó D U L O  P R O D U T O S                   ║
╚═════════════════════════════════════════════════════════════════╝
*/

#ifndef PRODUTOS_H
#define PRODUTOS_H


struct Produtos {
    char nomeprod[22];
    char teor[5];
    char amargor;
    char quant[6];
    int id;
    char status;
};

void modulo_produtos(void);
char menu_produtos(void);
void cadastrar_produtos(void);
void pesquisar_produtos(void);
void atualizar_produtos(void);
void remover_produtos_logico(void);
void remover_todos_produtos(void);
void recuperar_produto(void);
void remover_produtos(void);

// Funções de manipulação de arquivos
void salvar_produtos_em_arquivo(void);
void carregar_produtos_de_arquivo(void);

// Array para armazenar os produtos
#define MAX_PRODUTOS 1000
extern struct Produtos lista_produtos[MAX_PRODUTOS];

// Variável para armazenar o total de produtos registrados
extern int total_produtos;

#endif
