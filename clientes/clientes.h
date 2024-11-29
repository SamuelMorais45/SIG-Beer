/*
╔═════════════════════════════════════════════════════════════════╗
║                  M Ó D U L O  C L I E N T E S                   ║
╚═════════════════════════════════════════════════════════════════╝
*/

// Estrutura do cliente
struct Cliente {
    char cpf[16];
    char nome[100];
    char dat_nasc[11];
    char endereco[200];
    char telefone[15];
    char email[100];
};

// Declaração das funções do módulo clientes
void modulo_clientes(void);
char menu_clientes(void);
void cadastrar_clientes(void);
void pesquisar_clientes(void);
void atualizar_clientes(void);
void remover_clientes(void);

// Funções auxiliares para manipulação de arquivos (feito pelo gpt)
void salvar_cliente(struct Cliente *cliente);
void carregar_clientes(void);
void atualizar_arquivo(struct Cliente *clientes, int qtd_clientes);

