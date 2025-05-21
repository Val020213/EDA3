# D. Good Substrings

[Problem link](https://codeforces.com/contest/271/problem/D)

Dada la entrada de S un string, y Z una cadena binaria de tamanno 26 que representa el mappeo del alfabeto(es decir a vale z[0], b vale z[1]...), y un entero k; buscar el número de subcadenas de S que contengan menos de k ceros según su valor en Z.

## Solución

Vamos a generar todas las posibles subcadenas de S que contengan menos de k ceros. Luego usando hashing guardamos sus valores en un set.
Luego la cantidad de elementos en el set nos da con alta probabilidad la cantidad de subcadenas distintas.

Probablemente hubiera sido suficiente con una sola función de hash, pero para probar la idea de clase decidí usar tres funciones de hash distintas.

## Complejidad

O(n^2)
