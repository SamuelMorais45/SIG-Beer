/*
╔═════════════════════════════════════════════════════════════════╗
║                  M Ó D U L O  A S S I N A T U R A               ║
╚═════════════════════════════════════════════════════════════════╝
*/

struct assinatura {
    int idassinatura;
    char cpf[16];
    char idpack[12];
    int status;
};
void modulo_assinaturas(void);
char menu_assinaturas(void);
void cadastrar_assinaturas(void);
void pesquisar_assinaturas(void);
void cancelar_assinaturas(void);
void salvar_assinatura(struct assinatura *cliente);
void carregar_assinatura(void);
void atualizar_arquivo_assinatura(struct assinatura *assinaturas, int qtd_assinaturas);