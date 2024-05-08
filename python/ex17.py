#------------------------------------------------------------------------------
# # MAT0122 ÁLGEBRA LINEAR I
# Aluno: Eduardo Figueredo Pacheco
# Numero USP: 13672832
# Tarefa: E17
# Data: 15/09
# 
# 
# DECLARO QUE SOU O ÚNICO AUTOR E RESPONSÁVEL POR ESTE PROGRAMA.  TODAS AS 
# PARTES DO PROGRAMA, EXCETO AS QUE SÃO BASEADAS EM MATERIAL FORNECIDO  
# PELO PROFESSOR OU COPIADAS DO LIVRO OU DO MATERIAL DIDÁTICO DE MAT0122, 
# FORAM DESENVOLVIDAS POR MIM.  DECLARO TAMBÉM QUE SOU RESPONSÁVEL POR TODAS 
# AS CÓPIAS DESTE PROGRAMA E QUE NÃO DISTRIBUÍ NEM FACILITEI A DISTRIBUIÇÃO
# DE CÓPIAS DESTA PROGRAMA.
#------------------------------------------------------------------------------

from re import L
from vec import Vec
from GF2 import one



def button_vectors(n: int):
    D = {(i, j) for i in range(n) for j in range(n)}
    vecdict = {(i,j): Vec(D, dict([((x, j), one) for x in range(max(i-1, 0), min(i+2, n))]+[((i, y), one) for y in range(max(j-1, 0), min(j+2, n))])) for (i,j) in D}
    return [vecdict[i,j] for i in range(n) for j in range(n)]


def bin2list(x, t):
    l = [int(d) for d in str(bin(x)) [2:]]
    while(len(l) != t):
        l = [0] + l
    return l

def GF2_span (D,L):
    resposta = set()
    tamanho = len(L)
    lamb = (2**tamanho) - 1
    if (tamanho==0): #com a lista vazia de vetores de entrada, a função deve devolver o vetor nulo de GF(2).
        return {set()} # caso o vetor for nulo, retorna set()


    for i in range(lamb + 1):
        c = bin2list(lamb, tamanho)
        
        u = sum([c[j]*L[j] for j in range(tamanho)])
        resposta.add(u)
        lamb = lamb - 1

    return resposta


def tf(n):

    lista = GF2_span({(i,j) for i in range(n) for j in range(n)},button_vectors(n))
    print([lista])
    if (len(lista) == 2**(n**2)):
        return 1
    else:
        return 0

print(tf(2))
print(tf(3))
print(tf(4))