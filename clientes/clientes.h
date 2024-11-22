/*
╔═════════════════════════════════════════════════════════════════╗
║                  M Ó D U L O  C L I E N T E S                   ║
╚═════════════════════════════════════════════════════════════════╝
*/

// Estrutura para armazenar informações do cliente
struct Cliente {
    char cpf[16];
    char nome[52];
    char dat_nasc[12];
    char endereco[52];
    char email[52];
    char telefone[20];
    char telefoneLimpo[12]; 
};

// Funções do módulo clientes
void modulo_clientes(void);
char menu_clientes(void);
void cadastrar_clientes(void);
void pesquisar_clientes(void);
void atualizar_clientes(void);
void remover_clientes(void);
