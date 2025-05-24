# L. Subway Lines

[Problem link](https://codeforces.com/contest/271/problem/D)

Dado un árbol T y cuatro nodos A, B, C, D , el objetivo es encontrar la longitud del camino en común(si existiera) que tienen los caminos AB y CD.
Es decir la intercepción entre los nodos de AB y CD. 

## Solución

Si AB y CD tienen un camino en común por ejemplo W = w0, w1 .... wn, entonces AB se puede definir sin perdida de generalidad
como AB = A, a1 ...an,w0 ... wn, b0 ...B. y CB = C, c1 ...cn, w0 .... wn, d0. ... D. Luego la W = AB intercepcion CD, luego |2W|= |AB| + |CD| - |{A, a1 ... an, cn, cn-1 .... C}| - { D, dn-1 ... d0, b0 , b1 ... B } , gráficamente se ve mejor es basicamente quitar los caminos exteriores y quedarnos con W que esta en AB y CD. Para las distancias de los caminos en el arbol usamos LCA.


## Complejidad
Construir el LCA  + Responder las query
