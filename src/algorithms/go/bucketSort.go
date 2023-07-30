package main

import (
	"math"
)

func bucketSort(array []int) []int {
	bucketSize := 10
	maxValue := array[0]
	minValue := array[0]

	for _, value := range array {
		if value > maxValue {
			maxValue = value
		}
		if value < minValue {
			minValue = value
		}
	}

	bucketCount := int(math.Floor(float64(maxValue-minValue)/float64(bucketSize))) + 1
	buckets := make([][]int, bucketCount)

	for i := 0; i < len(array); i++ {
		index := int(math.Floor(float64(array[i]-minValue) / float64(bucketSize)))
		buckets[index] = append(buckets[index], array[i])
	}

	array = array[:0] // Limpiar el arreglo original

	for _, bucket := range buckets {
		insertionSort(bucket)
		array = append(array, bucket...)
	}

	return array
}
