#include <iostream>
#include <vector>

std::vector<int> countingSort(std::vector<int> arr)
{
    // Find the maximum value in arr
    int maxValue = arr[0];
    for (int num : arr)
    {
        if (num > maxValue)
        {
            maxValue = num;
        }
    }

    // Create a list of 0's at indices 0...maxValue
    std::vector<int> counts(maxValue + 1, 0);

    // Populate counts
    for (int num : arr)
    {
        counts[num]++;
    }

    // Populate the final sorted list
    std::vector<int> sortedList;

    // For each item in counts

    size_t n = counts.size();
    for (size_t i = 0; i < n; i++)
    {
        // For the number of times the item occurs
        for (int j = 0; j < counts[i]; j++)
        {
            // Add it to the sorted list
            sortedList.push_back(i);
        }
    }

    return sortedList;
}