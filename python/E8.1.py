A = 0B1110000
B = 0B0111000
C = 0B0011100
D = 0B0001110
E = 0B0000111
F = 0B0000011

U1 = 0B0010010
U2 = 0B0100010

V = 0B1011011


lista = [A,B,C,D,E,F]
lista2 = [(x^V) for x in lista]

res = [(x,y) for x in lista for y in lista if x!= y and ((x^y) == U1)]
res2 = [(x,y,z) for x,y,z in lista if x!= y and x != z and y != z and ((x^y) == U1)]
res3 = [(x,y,z,a) for x,y,z,a in lista if x!= y and x!=a and x!= z and y!= z and y != a and z != a and ((x^y^z^a) == U1)]
res4 = [(x,y,z,a,b) for x,y,z,a,b in lista if x!= y and ((x^y^z) == U1)]






print(res,res2,res3)