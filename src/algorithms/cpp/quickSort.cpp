#include <iostream>
#include <vector>

std::vector<int> quickSort(std::vector<int> &arr)
{
    if (arr.size() <= 1)
    {
        return arr;
    }

    int pivot = arr[arr.size() / 2];
    std::vector<int> left, middle, right;

    for (int x : arr)
    {
        if (x < pivot)
        {
            left.push_back(x);
        }
        else if (x == pivot)
        {
            middle.push_back(x);
        }
        else
        {
            right.push_back(x);
        }
    }

    left = quickSort(left);
    right = quickSort(right);

    std::vector<int> sortedArr;
    sortedArr.reserve(left.size() + middle.size() + right.size());
    sortedArr.insert(sortedArr.end(), left.begin(), left.end());
    sortedArr.insert(sortedArr.end(), middle.begin(), middle.end());
    sortedArr.insert(sortedArr.end(), right.begin(), right.end());

    return sortedArr;
}