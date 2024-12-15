/*
╔═════════════════════════════════════════════════════════════════╗
║                  M Ó D U L O  P R O D U T O S                   ║
╚═════════════════════════════════════════════════════════════════╝
*/


/*
╔═════════════════════════════════════════════════════════════════╗
║                  M Ó D U L O  P R O D U T O S                   ║
╚═════════════════════════════════════════════════════════════════╝
*/

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

