/*
╔══════════════════════════════════════════════════════════════╗
║                   M Ó D U L O  P A C K S                     ║
╚══════════════════════════════════════════════════════════════╝
*/

struct pack {
    char idprods[22];
    char nomepack[42];
    int idpack;
    char status;
};

void modulo_packs(void);
char menu_packs(void);
void cadastrar_packs(void);
void pesquisar_packs(void);
void remover_packs(void);
void carregar_packs(void);
void salvar_pack(struct pack *novo_pack);
