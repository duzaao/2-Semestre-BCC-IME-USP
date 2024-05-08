from math import sqrt
from statistics import mode


A  = [3.0, 3.5, 3.0, 2.5 ,2.5 ,2.5, 2.0, 5.0 ,6.5, 4.0,
7.5, 7.0, 4.5, 3.0, 3.0,0.0 ,2.5 ,3.0 ,2.0, 1.0,
2.0, 3.0, 3.5, 4.0, 5.0, 6.0, 3.5, 4.0, 8.0, 9.0,
3.0, 8.0, 4.0, 9.0, 2.0, 2.5, 3.0, 8.5, 3.5 ,0.0,
2.0, 9.0, 4.0, 1.0, 7.0, 4.5, 3.0, 2.0, 6.5, 3.0]

A = sorted(A)

j = A.copy

max = 0
A = [(x+1) for x in A ]
B = [(x) for x in A if x >= 3 and x < 5]
C = [(x) for x in A if x >= 5 and x < 8]
D = [(x) for x in A if x >= 8 and x <= 10]
A = [(x) for x in A if x >= 1 and x < 3]

#A = [ ((x - 2)**2) for x in A]
#B = [ ((x - 3.47)**2) for x in B]
#C = [ ((x - 6.3)**2) for x in C]
#D = [ ((x - 8.16)**2) for x in D]

#print("med de A é: ")
DMA = ((sum(A))/len(A))
DPA = ( sqrt( sum (A)/len(A) ))
DPB = ( sqrt( sum (B)/len(B) ))
DPC = ( sqrt( sum (C)/len(C) ))
DPD = ( sqrt( sum (D)/len(D) ))

#print(DPA)
#print("med de B é: ")
DMB = ((sum(B))/len(B))
#print(DPB)
#print("med de C é: ")
DMC = ((sum(C))/len(C))
#print(DPC)
#print("med de D é: ")
DMD = ((sum(D))/len(D))
#print(DPD)

print(B[12])