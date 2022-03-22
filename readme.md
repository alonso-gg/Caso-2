## ITCR Campus Central Cartago
## Ingeniería en computación \- Análisis de algoritmos 
### I Semestre 2022
### Caso 2
### Alonso Garita Granados 

## Forma de realizar el análisis  
Sabemos que la notación O nos indica la tasa de crecimiento del tiempo de ejecución del algoritmo. Nos interesa comprobar que el tiempo real de ejecución tiene el comportamiento que indica la notación O. Para esto analizaremos el ratio entre la notación y el tiempo real.  
Supongamos que tenemos dos funciones _f_\(n\) y _g_\(n\), si el valor de _f_\(n\)/_f_\(n-1\) es igual o similar a _g_\(n\)/_g_\(n-1\), y ocurre lo mismo para n+1, n+2, n+3...; entonces podemos concluir que _f_\(n\) y _g_\(n\) tienen el mismo comportamiento.  
Siguiendo esa idea, compararemos el comportamiento de la notación O contra el del tiempo real y así podremos demostrar si el algoritmo crece tal y como lo indica la notación O. 

## Quick sort, caso O\(n^2\)  
El quick sort es cuadrático cuando el arreglo está en orden inverso y elegimos un pivote en un extremo \(el primer o el último elemento\). Esto porque en cada iteración TODOS los elementos se acomodan hacia la derecha o a la izquierda del pivote, y por lo tanto el otro lado de la partición queda vacío.  
Para esto, vamos a comparar para n=1000 con O\(1²\), para n=2000 con O\(2²\)... Esto para ahorrar ceros. Hay que prestar atención a la diferencia absoluta entre ratios, pues entre menor sea, más se asemeja el tiempo real a la tasa que indica la notación O. 

n | Tiempo \(ms\) | O\(n²\) | Ratio de tiempo | Ratio de O | Diferencia
 ------- | ------------ | ------------ | ------------ | ------------ | ------------ 
1000 | 6 | 1 | \- | \- | \-
2000 | 22 | 4 | 3,66667 | 4,00000 | 0,33333
3000 | 48 | 9 | 2,18182 | 2,25000 | 0,06818
4000 | 87 | 16 | 1,81250 | 1,77778 | 0,03472
5000 | 134 | 25 | 1,54023 | 1,56250 | 0,02227
6000 | 186 | 36 | 1,38806 | 1,44000 | 0,05194
7000 | 256 | 49 | 1,37634 | 1,36111 | 0,01523
8000 | 336 | 64 | 1,31250 | 1,30612 | 0,00638
9000 | 437 | 81 | 1,30060 | 1,26563 | 0,03497
10000 | 526 | 100 | 1,20366 | 1,23457 | 0,03091

Salvo por la primera diferencia, todas son menores a 0.1, y es una diferencia aceptable para concluir que en este caso el quick sort es cuadrático. 

## Quick sort, caso O\(n logn\)  
El quicksort es logarítmico cuando las particiones son balanceadas en todas las iteraciones, es decir, quedan más o menos la misma cantidad de elementos a la izquierda Y a la derecha. Para este caso, usaremos el pivote aleatorio para aumentar las probabilidades de elegir un pivote que permita una partición balanceada, pero al haber un factor aleatorio no hay garantía de que en todas las iteraciones se cumpla esto. 

n | Tiempo \(ns\) | O\(n logn\) | Ratio de tiempo | Ratio de O | Diferencia
 ------- | ------------ | ------------ | ------------ | ------------ | ------------ 
1000 | 195800 | 33,2192809 | \- | \- | \-
2000 | 442800 | 86,4385619 | 2,26149 | 2,60206 | 0,34057
3000 | 684600 | 147,206717 | 1,54607 | 1,70302 | 0,15695
4000 | 932600 | 212,877123 | 1,36226 | 1,44611 | 0,08385
5000 | 1263000 | 282,192809 | 1,35428 | 1,32561 | 0,02866
6000 | 1447400 | 354,413435 | 1,14600 | 1,25593 | 0,10992
7000 | 1897400 | 429,049811 | 1,31090 | 1,21059 | 0,10031
8000 | 2067700 | 505,754247 | 1,08975 | 1,17878 | 0,08902
9000 | 2343400 | 584,266778 | 1,13334 | 1,15524 | 0,02190
10000 | 2664900 | 664,385619 | 1,13719 | 1,13713 | 0,00007

Como podemos ver, cuando usamos un pivote aleatorio el tiempo crece de manera logarítmica lineal, pues salvo por la primera diferencia todas son menores a 0.2. Este comportamiento es mucho mejor que el cuadrático. 

## Quick sort, Pivote fijo vs Pivote aleatorio  
A pesar de que la generación de números aleatorios no es tan aleatoria y es cara en tiempo de ejecución, pues se debe generar un número en cada iteración, se logra un comportamiento más eficiente del algoritmo.
Por lo general desconocemos la naturaleza de los datos a ordenar, así que si elegimos un pivote fijo eventualmente las particiones se van a desbalancear hacia algún lado, y una vez que ocurra es probable que siga ocurriendo en las siguientes iteraciones.  
Elegir un pivote aleatorio permite romper muchas veces esta situación, así obtemenos particiones más o menos balanceadas en cada iteración. Y si se empieza a desbalancear, la aleatoriedad evita que se mantenga desbalanceado. 

## Insert sort, caso O\(n^2\)  
Como el insert sort es secuencial es probable que tenga que acceder varias veces a los mismos campos. Si el arreglo está en orden inverso, siempre se comporta de forma cuadrática; en la primera iteración debe acceder a _n_ campos, en la segunda accede a _n_-1, en la tercera accede a _n_-2... y así hasta que el _n_-ésimo campo se accede un total de _n_ veces. 

n | Tiempo \(ms\) | O\(n²\) | Ratio de tiempo | Ratio de O | Diferencia
 ------- | ------------ | ------------ | ------------ | ------------ | ------------ 
1000 | 4 | 1 | \- | \- | \-
2000 | 17 | 4 | 4,25000 | 4,00000 | 0,25000
3000 | 39 | 9 | 2,29412 | 2,25000 | 0,04412
4000 | 67 | 16 | 1,71795 | 1,77778 | 0,05983
5000 | 107 | 25 | 1,59701 | 1,56250 | 0,03451
6000 | 148 | 36 | 1,38318 | 1,44000 | 0,05682
7000 | 201 | 49 | 1,35811 | 1,36111 | 0,00300
8000 | 270 | 64 | 1,34328 | 1,30612 | 0,03716
9000 | 333 | 81 | 1,23333 | 1,26563 | 0,03229
10000 | 409 | 100 | 1,22823 | 1,23457 | 0,00634

Similar a cuando analizamos el quick sort cuadrático, todas las diferencias salvo la primera son menores a 0.1. Por lo tanto, podemos afirmar que en este experimento el quick sort es cuadrático. 

## Insert sort, caso O(n)  
La única forma de que el insert sort sea lineal es que cada campo sea accedido una sola vez, y esto ocurre cuando el arreglo ya está totalmente ordenado. 

n | Tiempo \(ns\) | O\(n\) | Ratio de tiempo | Ratio de O | Diferencia
 ------- | ------------ | ------------ | ------------ | ------------ | ------------ 
1000 | 10600 | 1 | \- | \- | \-
2000 | 22200 | 2 | 2,09434 | 2,00000 | 0,09434
3000 | 37500 | 3 | 1,68919 | 1,50000 | 0,18919
4000 | 43000 | 4 | 1,14667 | 1,33333 | 0,18667
5000 | 81100 | 5 | 1,88605 | 1,25000 | 0,63605
6000 | 64300 | 6 | 0,79285 | 1,20000 | 0,40715
7000 | 74400 | 7 | 1,15708 | 1,16667 | 0,00959
8000 | 101200 | 8 | 1,36022 | 1,14286 | 0,21736
9000 | 106300 | 9 | 1,05040 | 1,12500 | 0,07460
10000 | 131200 | 10 | 1,23424 | 1,11111 | 0,12313

En este experimento las diferencias entre los ratios son ligeramente mayores, pero podemos considerar una toleracia de diferenias menores a 0.2. Aún así, tres diferencias se pasan de la tolerancia, aunque una lo hace por muy poco. Realmente podemos decir con total seguridad que aquí el insert sort se comporta de manera lineal. 

## Free text, O(n-m) y O(nm)
Para este caso se implementó el algoritmo de Rabin Karp que calcula una función hash para el patrón buscado y para todos los substrings en el texto del mismo largo. En este algoritmo intervienen dos variables: _n_ que es el largo del texto completo y _m_ que es el largo del patrón. El tamaño de _m_ influye en la cantidad de veces que se itera el algoritmo, así que si es muy pequeño puede que la diferencia no se note.  
Sin embargo, si _m_ es mayor a 36 el target key del patrón buscado sobrepasa el valor máximo para los enteros sin signo y hace que el algoritmo se comporte como un algoritmo de fuerza bruta. Una solución a esto es usar _long long_ para los valores hash.  
Podríamos considerar este como el peor caso del algoritmo y en este caso se comporta como O(nm), mientras que el mejor sería O(n-m) cuando el target key cabe en el rango de los enteros sin signo. 

### Free text O(n-m)  

n | m | Tiempo \(ns\) | O\(n-m\) | Ratio de tiempo | Ratio de O | Diferencia
 ------- | ------- | ------------ | ------------ | ------------ | ------------ | ------------ 
4006260 | 1 | 176 | 4006259 | \- | \- | \-
4006260 | 2 | 187 | 4006258 | 1,06250 | 1,00000 | 0,06250
4006260 | 4 | 195 | 4006256 | 1,04278 | 1,00000 | 0,04278
4006260 | 6 | 191 | 4006254 | 0,97949 | 1,00000 | 0,02051
4006260 | 8 | 184 | 4006252 | 0,96335 | 1,00000 | 0,03665
4006260	| 10 | 198 | 4006250 | 1,07609 | 1,00000 | 0,07609
4006260 | 12 | 199 | 4006248 | 1,00505 | 1,00000 | 0,00505
4006260 | 14 | 204 | 4006246 | 1,02513 | 1,00000 | 0,02513
4006260 | 16 | 192 | 4006244 | 0,94118 | 1,00000 | 0,05882
4006260	| 18 | 198 | 4006242 | 1,03125 | 1,00000 | 0,03125 

### Free text O(nm)  

n | m | Tiempo \(s\) | O\(nm\) | Ratio de tiempo | Ratio de O | Diferencia
 ----------- | --------- | ------------ | ----------------------- | ------------ | ------------ | ------------ 
12018780 | 10000 | 8 | 120187800000 | \- | \- | \-
12018780 | 20000 | 21 | 240375600000 | 2,62500 | 2,00000 | 0,62500
12018780 | 30000 | 28 | 360563400000 | 1,33333 | 1,50000 | 0,16667
12018780 | 40000 | 35 | 480751200000 | 1,25000 | 1,33333 | 0,08333
12018780 | 50000 | 43 | 600939000000 | 1,22857 | 1,25000 | 0,02143
12018780 | 60000 | 50 | 721126800000 | 1,16279 | 1,20000 | 0,03721
12018780 | 70000 | 57 | 841314600000 | 1,14000 | 1,16667 | 0,02667
12018780 | 80000 | 64 | 961502400000 | 1,12281 | 1,14286 | 0,02005
12018780 | 90000 | 77 | 1081690200000 | 1,20313 | 1,12500 | 0,07813
12018780 | 100000 | 85 | 1201878000000 | 1,10390 | 1,11111 | 0,00722 

Ambos tienen un comportamiento lineal, pero los algoritmos que usan indexación pueden conseguir mejores tiempos. De hecho, estos experimentos demuestran una deficiencia de este algoritmo, y es que eventualmente funciona como un algoritmo de fuerza bruta, por más que se logre elevar el rango máximo para almacenar el target key. 

#### Enlace  

Se adjunta un enlace a un archivo con 3 mediciones para cada caso de los algoritmos de sorting y 4 para el de free text. [Enlace al archivo Caso 2 \- Mediciones.](https://docs.google.com/spreadsheets/d/1QwCcYfX75Wu_mclQkyDiwEak083vO4ktt7mL2ZliiKg/edit?usp=sharing).

