def countingSort(arr):
    # find the maximum value in arr
    max_value = max(arr)
    # create a list of 0's at indices 0...max_value
    counts = [0] * (max_value + 1)
    # populate counts
    for num in arr:
        counts[num] += 1
    # populate the final sorted list
    sorted_list = []
    # for each item in counts
    for i in range(len(counts)):
        # for the number of times the item occurs
        for j in range(counts[i]):
            # add it to the sorted list
            sorted_list.append(i)
    return sorted_list
