#define ERRO '\0'

typedef struct{
  int ultima_palavra;
  int *nao_usadas;
  int *possiveis;
  int coord_lin;
  int coord_col;
  int modo;
  char *space; 

} estado;

typedef estado *item;
#define ERRO '\0'
typedef struct {
  item * v; 
  int topo; 
  int max; 
} pilha;

void empilha (pilha * p, item x); 
item desempilha (pilha * p); 
item topoPilha (pilha * p); 
int pilhaVazia (pilha * p); 
void resize (pilha * p);
pilha * cria(); 
void destroi(pilha * p); 


