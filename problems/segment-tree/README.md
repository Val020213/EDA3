# C. Circular RMQ

[Problem Link](https://codeforces.com/contest/52/problem/C)

El problema consiste en encontrar el mínimo en rango en un array circular. Tiene dos queries:

- `l r`: para encontrar el mínimo en el rango `[l, r]`.
- `l r inc`: para incrementar todos los elementos en el rango `[l, r]` en `inc`.

## Solución

Como el array es circular dividimos las queries si l > r en dos queries:

- `l n`: para encontrar el mínimo en el rango `[l, n]`.
- `1 r`: para encontrar el mínimo en el rango `[1, r]`.

De igual manera con los incrementos.

Como es update en rango usamos Lazy Propagation para manejar los incrementos cuando nos hagan falta.
