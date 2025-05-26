# B. Left Terminal Minima

[Problem Link](https://codeforces.com/group/7Dn3ObOpau/contest/493739/problem/B)

Cada caso de prueba esta compuesto por un array de tamanno de entrada n. Y te definen como `terminal minima` del indice R, al indice L tal que el mínimo elemento del subarray a[L .... R] es igual a A[L].
El objetivo es encontrar para cada indice R, su terminal minima L.

## Solución

Como podemos ver si L es la terminal minima de R, entonces todos los elementos de a[L+1 ... R] son mayores o iguales a A[L], en caso contrario quedaría invalidada la secuencia.
La idea es usar el monotonic stack para ir guardando y actualizando las posibles terminales minimas hasta R.

# Complejidad

Cada caso de prueba se resuelve en O(n), por lo que la complejidad total es O(n \* t), donde n es el tamaño del array y t el número de casos de prueba.
