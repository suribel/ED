Author: Antonio Manuel Rodríguez Martos.

Se ha implementado sólo un módulo para el diccionario(SET), y se ha resuelto el problema de las cifras.

Para realizar este problema he utilizado un algoritmo recursivo que fuera recorriendo el vector de números y fuera haciendo operaciones con los dos primeros números del vector, si tras
esta operación se encuentra la solución pues corta, sino sigue si llega al final y no encuentra nada vuelve al paso anterior y prueba ha hacer la operación determinada con el siguiente número...
Es algo así como un backtracking. En Cada operación guardo los valores en un vector parcial por nivel, es decir el nivel sería algo así como por cuantos números nos queden en el vector de números.
También guardaremos en el vector de solucion de datos finales las operaciones parciales(el número que más se acerca al solución) o directa.
Al guardarse todas las operaciones que se han hecho, puede dar la casualidad de que se muestren operaciones que no son relevantes, es decir,
que sus números no se utilizan realmente para la solución final, pero ya que fue un paso previo (un nivel superior si pensamos en nodos) pues se guarda.
Por tanto deberemos hacer una limpieza del vector para quitarlas(al final del main).


Para el módulo de Diccionario(SET), lo he implementado siguiendo la base del guión, además creando dentro dos clases más, iterator y const_iterator.
Letra tiene tres valores privados: caracter, apariciones y puntuación, y como públicos los get y set asociados y los operators ==, <<, >>, además he implementado el operator < y = necesarios más adelante cuando construyamos un set de letra, para el orden que deben tener.
Conjunto de Letras tiene un valor privado conjunto, que es un set de Letra, donde almacenaremos las Letras que obtendremos de un fichero, también he implementado un iterator y un const iterator. También tendremos una función para obtener la puntuación de un string determinada por sus caracteres.
Bolsa de letras tiene un valor privado bolsa, es un vector de char ya que que al poder repetirse el mismo char y tener que acceder a posiciones aleatorias era lo más cómodo para implementar. Con una función llamada llenar meteremos en bolsa los caracteres que nos digan a través de un objeto Conjunto de Letras. También tendremos otra función que nos saque un número de letras de la bolsa.
Cantidad de letras, hemos utilizado un vector en el cual almacenamos Letras de los caracteres provistos en un archivo dado, a partir de ahí haremos las operaciones determinadas para contar cada caracter de cada palabra del diccionario y sumando para cada letra uno en apariciones.
Letras cargara todos los ficheros, validará y mostrará todos lo referente al juego.

El programa cifras se ejecuta con el ejecutable tal cual.
./cifras

El programa letras habrá que ejecutar el ejecutable con ciertos parámetros, pej:
./Letras ../datos/diccionario1000.txt ../datos/letrillas.txt 8 P

El programa cantidad de letras habrá que ejecutar el ejecutable con ciertos parámetros, pej:
./Cantidad_Letras ../datos/diccionario1000.txt ../datos/Spanish.txt ../datos/salida.txt
