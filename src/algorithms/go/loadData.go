package main

import (
	"encoding/csv"
	"os"
	"strconv"
)

func loadData() map[string][]int {

	data := make(map[string][]int)
	dataArray := [15]string{
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
	}

	// leer los archivos que se encuentran en dataArray y convertir cada uno en un array de enteros, y agregarlo a data
	for _, e := range dataArray {
		data[e] = readCSV("../../data/" + e)
	}

	return data
}

// leer un archivo csv y convertirlo en un array de enteros
func readCSV(filename string) []int {
	// abrir el archivo
	file, err := os.Open(filename)
	if err != nil {
		panic(err)
	}
	defer file.Close()

	// leer el archivo
	reader := csv.NewReader(file)
	reader.Comma = ';'
	reader.FieldsPerRecord = -1

	// convertir el archivo en un array de enteros
	rawCSVdata, err := reader.ReadAll()
	if err != nil {
		panic(err)
	}

	// convertir el array de strings en un array de enteros
	var data []int
	for _, e := range rawCSVdata {
		for _, v := range e {
			value, err := strconv.Atoi(v)
			if err != nil {
				panic(err)
			}
			data = append(data, value)
		}
	}

	return data
}
