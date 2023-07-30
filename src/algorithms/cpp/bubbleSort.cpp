#include <vector>

std::vector<int> bubbleSort(std::vector<int> arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            // if the element is greater than the next element, swap them
            if (arr[j] > arr[j + 1])
            {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
    return arr;
}