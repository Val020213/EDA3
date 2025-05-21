# Pashmak and Parmida's problem

[Problem link](https://codeforces.com/problemset/problem/459/D)

Se define f(li, ls, k) como todos los números iguales a k en el intervalo de [li, ls].
La entrada es el array A, y la salida es el número de pares i,j con i < j tal que f(1, i , ai) > f( j , n, aj).

## Solución

Lo que vamos a hacer es modelar el problema en dos array, el primero para los posibles subarray de i(Prefijos) y el segundo para los posibles subarray de j(Sufijos).

De forma formal tendriamos los siguiente:

Array de Prefijos en la posición i: { # de veces que aparece a[i] en el intervalo [1, i]
}

Array de Sufijos en la posición j: { # de veces que aparece a[j] en el intervalo [j, n]
}

Luego transcribiendo la definición de f, a nuestros arrays, queda que si f(1, i , ai) > f( j , n, aj) entonces Prefijos[i] > Sufijos[j], donde i < j.

Y el problema se reduce a contar cuantos elementos mayores que Prefijos[i] hay en el subarray de Sufijos[i+1, n].`
Aqui usamos la idea de contar inversiones con Fenwick Tree.

## Complejidad

2 X O(n) + O(n log n) = O(n log n) 
