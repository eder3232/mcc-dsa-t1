# Tarea #1 - Maestría en Ciencias de la computación

En este repositorio se llevará a cabo la tarea número 1 de la maestría en ciencias de la computación.

## Datos

Para poder testear los algoritmos de ordenamiento se necesitan una serie de datos, para este proposito se uso un algoritmo en python (ubicado en "src/utils/numberGenerator.py") para generar numeros aleatorios, y estos datos se guardaron en la carpeta "src/data", cada una incluye numeros aleatorios en formato .csv, con 100, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 20000, 30000, 40000 y 50000 valores respectivamente.

## Algoritmos

Los algoritmos se encuentran en la carpeta "algorithms", escritos en diferentes lenguaje, cada uno en su propia carpeta.

Se eligieron estratégicamente algoritmos de ordenamiento para hacer un análisis de rendimiento.

| algoritmo | Big(O) |
| --------   | ------|
| Bubbleort | O(n^2) |
| InsertionSort | O(n^2) |
| MergeSort | O(n log(n)) |
| QuickSort | O(n log(n)) |
| BucketSort | O(n+k) |
| CountingSort | O(n+k) |

Se eligió algoritmos con diferente Big(O) para tener un buen valor de comparación, y dos de cada uno.

### Python

En la carpeta "src/algorithms/python" se tienen los algoritmos a ser usados cada uno en su propia carpeta.

La función main es la que se encarga de leer los datos de los archivos .csv y usar los algoritmos ordenadores sobre cada serie de datos, para finalmente escribir estos resultados en un archivo "record.json".

Para usarla dirigirse a la carpeta "src/algorithms/python" y usar el comando:

```python
py main.py
```

### Go

En la carpeta "src/algorithms/go" se tienen los algoritmos a ser usados cada uno en su propia carpeta.

Para usarla dirigirse a la carpeta "src/algorithms/go" y usar el comando:

```python
go run .
```

### C++

En la carpeta "src/algorithms/cpp" se tienen los algoritmos a ser usados cada uno en su propia carpeta.

Para ejecutar usar la extensión de VSC: "C/C++ Compile Run", mediante el shortcut "F6".

### Resultados

Cada método main (Python, Go, C++), se encarga de leer los datos en formato CSV, importar los algoritmos de ordenamiento, ejecutar cada algoritmo de ordenamiento sobre cada serie de datos, para finalmente imprimir los resultados en un archivo JSON.

Para tener datos confiable se ejecuto 5 veces cada método main, y se guardo el registro de 5 calculos en 5 archivos JSON, con la denominación record1.json, record2.json ... record5.json.

## Análisis de datos

Para analizar los datos hace uso de jupyter notebooks que se encuentra en la ruta "src/analysis/main.ipynb".

Para comenzar el análisis se copio los resultados de los algoritmos ejecutados en cada lenguajes de programación a la carpeta "src/analysis/results".

Se calculo los promedios de cada serie de datos, cuyo procedimiento esta en el jupyter notebook "main.ipynb" y se guardaron los resultados en la carpeta "src/analysis/average".