#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <chrono>
#include <algorithm>

#include "json.hpp"
#include "bubbleSort.cpp"
#include "bucketSort.cpp"
#include "countingSort.cpp"
#include "insertionSort.cpp"
#include "mergeSort.cpp"
#include "quickSort.cpp"
#include "loadData.cpp"

using namespace std;

template <typename Func>
double measureTime(Func func, std::vector<int> &vec)
{
    auto start = std::chrono::high_resolution_clock::now();
    func(vec);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    return duration.count();
}

int main()
{

    std::map<string, vector<int>> data = loadData();

    nlohmann::json results;

    for (const auto &entry : data)
    {
        const std::string &algorithmName = entry.first;
        const std::vector<int> &vec = entry.second;

        std::vector<int> vecCopy = vec; // Hacemos una copia para que cada algoritmo trabaje con el mismo vector desordenado.

        double bubbleSortTime = measureTime(bubbleSort, vecCopy);
        vecCopy = vec; // Restauramos el vector desordenado.
        double bucketSortTime = measureTime(bucketSort, vecCopy);
        vecCopy = vec; // Restauramos el vector desordenado.
        double countingSortTime = measureTime(countingSort, vecCopy);
        double insertionSortTime = measureTime(insertionSort, vecCopy);
        double mergeSortTime = measureTime(mergeSort, vecCopy);
        double quickSortTime = measureTime(quickSort, vecCopy);

        nlohmann::json algorithmResult;
        algorithmResult["bubbleSort"] = bubbleSortTime;
        algorithmResult["bucketSort"] = bucketSortTime;
        algorithmResult["countingSort"] = countingSortTime;
        algorithmResult["insertionSort"] = insertionSortTime;
        algorithmResult["mergeSort"] = mergeSortTime;
        algorithmResult["quickSort"] = quickSortTime;

        results[algorithmName] = algorithmResult;
    }

    // Guardamos los resultados en un archivo JSON.
    std::ofstream file("record.json");
    if (file.is_open())
    {
        file << results.dump(4); // El parámetro 4 es la cantidad de espacios para formatear el JSON.
        file.close();
        std::cout << "Resultados guardados en 'resultados.json'." << std::endl;
    }
    else
    {
        std::cout << "Error al abrir el archivo para guardar los resultados." << std::endl;
    }

    return 0;
}
