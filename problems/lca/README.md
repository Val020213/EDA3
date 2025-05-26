# L. Subway Lines

[Problem link](https://codeforces.com/gym/101908/problem/L)

Dado un árbol $T$ y cuatro nodos A, B, C, D, el objetivo es encontrar la longitud del camino en común (si existe) entre los caminos $A \rightarrow B$ y $C \rightarrow D$.

## Solución

Sea $P_{AB}$ el camino entre A y B, y $P_{CD}$ el camino entre $C$ y $D$.
Si $W = w_0, w_1, \ldots, w_n$ es el camino en común $P_{AB}$ y $P_{CD}$ tienen, entonces $P_{AB}$ se puede definir sin pérdida de generalidad como $P_{AB} = A, a_1, \ldots, a_n, w_0, \ldots, w_n, b_0, \ldots, B$ y $P_{CD} = C, c_1, \ldots, c_n, w_0, \ldots, w_n, d_0, \ldots, D$.

Como $W = P_{AB} \cap P_{CD}$ entonces:

$|2W| = |P_{AB}| + |P_{CD}| - |{A, a_1, \ldots, a_n, c_n, c_{n-1}, \ldots, C}| - |{D, d_{n-1}, \ldots, d_0, b_0, b_1, \ldots, B}|$.

Como los caminos en el árbol son únicos estos serian los caminos de $A$ a $C$ y de $D$ a $B$.

Gráficamente se ve mejor, es básicamente quitar los caminos exteriores y quedarnos con $W$ que está en $P_{AB}$ y $P_{CD}$.

Para las distancias de los caminos en el árbol usamos LCA que nos permite calcular la distancia en O(log n).

## Complejidad

Construir el LCA + Responder las query.

$O(n \log n + q \log n)$, donde $n$ es el número de nodos y $q$ el número de queries.
