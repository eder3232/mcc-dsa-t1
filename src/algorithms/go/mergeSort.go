package main

func mergeSort(arr []int) []int {
	if len(arr) > 1 {
		mid := int(len(arr) / 2)
		// left := arr[:mid]
		left := make([]int, len(arr[:mid]))
		copy(left, arr[:mid])
		// right := arr[mid:]
		right := make([]int, len(arr[mid:]))
		copy(right, arr[mid:])

		mergeSort(left)
		mergeSort(right)

		i, j, k := 0, 0, 0

		for i < len(left) && j < len(right) {
			if left[i] <= right[j] {
				arr[k] = left[i]
				i++
			} else {
				arr[k] = right[j]
				j++
			}
			k++
		}

		for i < len(left) {
			arr[k] = left[i]
			i++
			k++
		}

		for j < len(right) {
			arr[k] = right[j]
			j++
			k++
		}
	}
	return arr
}
