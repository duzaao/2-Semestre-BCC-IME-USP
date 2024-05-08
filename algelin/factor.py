
import sys
import GF2
from GF2 import one
from vec import Vec,getitem
from factoring_support import intsqrt, dumb_factor, primes, prod, gcd
from vecutil import list2vec


def int2GF2(i):
    return one if i%2==1 else 0


def make_Vec(primeset,factors):
   return Vec(primeset, {FAC[0]:int2GF2(FAC[1]) for FAC in factors})

def find_candidates(N, primeset):
    roots = []
    rowlist = []
    x = 2
    while (len(roots) <= len(primelist) + 1):
        y = x + intsqrt(N)
        x += 1
        tmp = dumb_factor(y*y-N, primeset)
        if len(tmp) != 0 :
            roots.append(y)
            rowlist.append(make_Vec(primeset,tmp))
    return (roots, rowlist)

def transformation_rows(rowlist_input, col_label_list = None):
    quantidade_zeros = 0
    one = GF2.one 
    rowlist = list(rowlist_input)
    if col_label_list == None: col_label_list = sorted(rowlist[0].D, key=repr)
    m = len(rowlist)
    row_labels = set(range(m))
    M_rowlist = [Vec(row_labels, {i:one}) for i in range(m)]
    new_M_rowlist = []
    rows_left = set(range(m))
    for c in col_label_list:
        rows_with_nonzero = [r for r in rows_left if rowlist[r][c] != 0]
        if rows_with_nonzero != []:
            pivot = rows_with_nonzero[0]
            rows_left.remove(pivot)
            new_M_rowlist.append(M_rowlist[pivot])
            for r in rows_with_nonzero[1:]:
                multiplier = rowlist[r][c]/rowlist[pivot][c]
                rowlist[r] -= multiplier*rowlist[pivot]
                M_rowlist[r] -= multiplier*M_rowlist[pivot]
    for r in rows_left: new_M_rowlist.append(M_rowlist[r])
    return (new_M_rowlist,m-pivot)

            
def find_a_and_b(v,roots,N):
    alist = [ roots[i] for i in v.D if getitem(v,i) == one]
    a = prod(alist)
    c = prod([d**2-N for d in alist])
    b = intsqrt(c)
    assert b**2 == c
    return (a, b)


if len(sys.argv) >= 3:
    N = int(sys.argv[1])
    if(sys.argv[2] != '+'):
        primelist = primes(int(sys.argv[2]))
    else: 
        primelist = primes(10000)

    modo = 1
if len(sys.argv) == 2:
    N = int(sys.argv[1])
    primelist = primes(10000)
    modo = 0

(roots, rowlist) = find_candidates(N, primelist)
(M,zeros) = transformation_rows(rowlist)
linha = len(M)-1
cont = 0
while(linha>=len(M)-zeros):
    v = M[linha] 
    (a,b) = find_a_and_b(v, roots, N)
    if(modo==1):
        print (cont,":    ","a = ", a, "/  b = ", b,"\n")
        cont+= 1

    linha = linha - 1
    if(gcd(N,a-b) != 1 and gcd(N,a-b) != N ):
        print("factor = ", gcd(N, a-b))
        break
    if(gcd(N,a+b) != 1 and gcd(N,a+b) != N ):
        print("factor = ", gcd(N, a+b))
        break



