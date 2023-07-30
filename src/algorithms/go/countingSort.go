package main

func countingSort(arr []int) []int {
	// Find the maximum value in arr
	maxValue := arr[0]
	for _, num := range arr {
		if num > maxValue {
			maxValue = num
		}
	}

	// Create a list of 0's at indices 0...maxValue
	counts := make([]int, maxValue+1)

	// Populate counts
	for _, num := range arr {
		counts[num]++
	}

	// Populate the final sorted list
	sortedList := []int{}

	// For each item in counts
	for i := 0; i < len(counts); i++ {
		// For the number of times the item occurs
		for j := 0; j < counts[i]; j++ {
			// Add it to the sorted list
			sortedList = append(sortedList, i)
		}
	}

	return sortedList
}
