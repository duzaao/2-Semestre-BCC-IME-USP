typedef char item;
#define ERRO '\n'

typedef struct{

    int *v;
    int max;
    int topo;
} pilha;

void empilha (pilha *p, item x);
item desempilha (pilha *p);
item topoPilha (pilha *p);
int pilhaVazia (pilha *p);
void resize (pilha *p);
pilha cria ();
void destroi (pilha *p);