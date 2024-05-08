No {
	(tipo1) chave
	(tipo2) valor
	No esquerda
	No direita
		
}


conta_nos(raiz)
	if (raiz == null) return 0;	
	return conta_nos(raiz.esquerda) + conta_nos(raiz.direita) + 1;
	
ancestral(x, y)
	if (x == null ou y == null) return 0
	if (x.chave = y.chave) return 1
	return ancestral(x.esquerda, y) ou ancestral(x.direita, y)
	
constroi_preordem(vetor, raiz)
	for i em vetor
		raiz = insere(i, raiz)

int menorQue(raiz, x)
	if (raiz == null) return 1
	if (x > raiz.valor) return 0
	return menorQue(raiz.esquerda, x)
	
int maiorQue(raiz, x)
	if (raiz == null) return 1
	if (x < raiz.valor) returnn 0
	return maiorQur(raiz.direita, x)
	
int ehABB(raiz)
	if (raiz == null) return 0
	if (raiz.esquerda.valor > raiz.valor) return 0
	if (raiz.direita.valor < raiz.valor) return 0
	return ehABB(raiz.esquerda) and ehABB(raiz.direita)