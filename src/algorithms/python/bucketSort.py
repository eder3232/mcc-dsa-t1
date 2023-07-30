import math


def bucketSort(array):
    bucketSize = 10
    maxValue = max(array)
    minValue = min(array)
    bucketCount = math.floor((maxValue - minValue) / bucketSize) + 1
    buckets = [[] for _ in range(bucketCount)]
    for i in range(len(array)):
        buckets[math.floor((array[i] - minValue) / bucketSize)].append(array[i])
    array.clear()
    for bucket in buckets:
        insertionSort(bucket)
        array.extend(bucket)
    return array


# write insertion sort algorithm
def insertionSort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        # compare key with each element on the left of it until an element smaller than it is found
        # for descending order, change key<array[j] to key>array[j].
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        # place key at after the element just smaller than it.
        arr[j + 1] = key
    return arr
