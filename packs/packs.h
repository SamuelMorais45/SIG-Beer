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

void remover_pack_por_id(const char *id);
void carregar_packs(void);
void salvar_pack(struct pack *novo_pack);
int gerar_id_pack(void);
void modulo_packs(void);
char menu_packs(void);
void cadastrar_packs(void);
void pesquisar_packs(void);
void remover_packs(void);
