package main

import (
	"encoding/json"
	"fmt"
	"os"
	"time"
)

type sortAlgorithm func([]int) []int

var algorithms = []struct {
	name     string
	function sortAlgorithm
}{
	{"bubbleSort", bubbleSort},
	{"insertionSort", insertionSort},
	{"mergeSort", mergeSort},
	{"quickSort", quickSort},
	{"bucketSort", bucketSort},
	{"countingSort", countingSort},
}

func main() {
	data := loadData()

	fmt.Println("Starting...")

	maxLengthName := 0
	for _, e := range algorithms {
		if len(e.name) > maxLengthName {
			maxLengthName = len(e.name)
		}
	}

	record := make(map[string]map[string]float64)

	for key, value := range data {
		record[key] = make(map[string]float64)
		fmt.Printf("Starting %s\n", key)
		for _, e := range algorithms {
			// crea una copia de arr en la variable llamada arrCopy
			arrCopy := make([]int, len(value))
			copy(arrCopy[:], value[:])

			start := time.Now()
			// e.function(value)
			e.function(arrCopy)
			end := time.Now()
			seconds := end.Sub(start).Seconds()
			record[key][e.name] = seconds
			// fmt.Printf("Finished %s in %f seconds\n", e.name, seconds)
			fmt.Printf("%-*s\t%f\n", maxLengthName, e.name, seconds)
		}
	}

	file, err := os.Create("record.json")
	if err != nil {
		panic(err)
	}
	defer file.Close()

	encoder := json.NewEncoder(file)
	encoder.SetIndent("", "    ")
	encoder.Encode(record)

	fmt.Println("finish!")
}
