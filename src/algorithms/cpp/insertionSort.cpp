#include <vector>
std::vector<int> insertionSort(std::vector<int> arr)
{
    for (int i = 1; i < static_cast<int>(arr.size()); i++)
    {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            std::swap(arr[j - 1], arr[j]);
            j--;
        }
    }
    return arr;
}