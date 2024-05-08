

typedef struct cel {
  int chave;
  struct cel * esq;
  struct cel * dir; 
} no;


#define NULL 0

no* BUSCA(no* raiz, int x){

    if(raiz == NULL || raiz->chave==x)
    return raiz;
    if(x<raiz->chave) return BUSCA(raiz->esq,x);
    return BUSCA(raiz->dir,x);


}


no* insere(no* raiz, int x){

    if (raiz == NULL){
        raiz = malloc(sizeof(no));
        raiz->chave = x;
        raiz->dir = NULL;
        raiz->esq = NULL;
    }
    if(x<raiz->chave) raiz->esq  = insere(raiz->esq,x);
    else if(x>raiz->chave) raiz->dir = insere(raiz->dir,x);
    return raiz;

}


no* retira(no* raiz, int x){

    no* y;

    if(raiz == NULL) return NULL;
    if(x<raiz->chave) raiz->esq = retira(raiz->esq,x);
    if(x>raiz->chave) raiz->dir = retira(raiz->dir,x);

    else{

        if(raiz->esq == NULL){
            y = raiz->dir;
            free(raiz);
            raiz= y;
        }
        else if(raiz->dir == NULL){
            y = raiz->esq;
            free(raiz);
            raiz = y;
        }
        else {
            y = minimo(raiz->dir);
            raiz->chave = y->chave;
            raiz->dir = retira(raiz->dir,y->chave);
        }
    }
}