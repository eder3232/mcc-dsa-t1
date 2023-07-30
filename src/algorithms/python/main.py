import csv
import time
import json

from bubbleSort import bubbleSort
from insertionSort import insertionSort
from mergeSort import mergeSort
from quickSort import quickSort
from bucketSort import bucketSort
from countingSort import countingSort


dataArray = [
    "numeros_aleatorios_100.csv",
    "numeros_aleatorios_1000.csv",
    "numeros_aleatorios_2000.csv",
    "numeros_aleatorios_3000.csv",
    "numeros_aleatorios_4000.csv",
    "numeros_aleatorios_5000.csv",
    "numeros_aleatorios_6000.csv",
    "numeros_aleatorios_7000.csv",
    "numeros_aleatorios_8000.csv",
    "numeros_aleatorios_9000.csv",
    "numeros_aleatorios_10000.csv",
    "numeros_aleatorios_20000.csv",
    "numeros_aleatorios_30000.csv",
    "numeros_aleatorios_40000.csv",
    "numeros_aleatorios_50000.csv",
]

algorithms = [
    {"name": "bubbleSort", "function": bubbleSort},
    {"name": "insertionSort", "function": insertionSort},
    {"name": "mergeSort", "function": mergeSort},
    {"name": "quickSort", "function": quickSort},
    {"name": "bucketSort", "function": bucketSort},
    {"name": "countingSort", "function": countingSort},
]


def main():
    data = {}
    for file in dataArray:
        data[file] = []
        with open(f"../../data/{file}", newline="") as File:
            reader = csv.reader(File)
            for row in reader:
                data[file].append(int(row[0]))

    maxLengthName = max(len(e["name"]) for e in algorithms)

    record = {}

    for key, value in data.items():
        record[key] = {}
        print(f"Starting {key}")
        for e in algorithms:
            start = time.perf_counter()
            e["function"](value.copy())
            end = time.perf_counter()
            seconds = end - start
            record[key][e["name"]] = seconds
            print(
                f"Finished {e['name'].ljust(maxLengthName)} in {round(seconds,6)} seconds"
            )

    with open("record.json", "w") as file:
        json.dump(record, file)

    print("finish!")


main()
