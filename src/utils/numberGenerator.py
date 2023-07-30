import os
import csv
import random

def generar_numeros_aleatorios(cantidad, minimo, maximo):
    return [random.randint(minimo, maximo) for _ in range(cantidad)]

def escribir_csv(nombre_archivo, lista_numeros):
    with open(nombre_archivo, 'w', newline='') as archivo_csv:
        writer = csv.writer(archivo_csv)
        for numero in lista_numeros:
            writer.writerow([numero])

if __name__ == "__main__":
    cantidad_numeros = 50000
    minimo = 0
    maximo = cantidad_numeros*10

    lista_numeros = generar_numeros_aleatorios(cantidad_numeros, minimo, maximo)

    carpeta_data="../data"
    nombre_archivo=f"numeros_aleatorios_{cantidad_numeros}.csv"

    ruta_completa_archivo = os.path.join(carpeta_data, nombre_archivo)
    escribir_csv(ruta_completa_archivo, lista_numeros)

    print(f"Se han generado y escrito {cantidad_numeros} números aleatorios en el archivo '{nombre_archivo}'.")