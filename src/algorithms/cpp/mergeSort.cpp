#include <iostream>
#include <vector>

std::vector<int> merge(std::vector<int> &left, std::vector<int> &right)
{
    std::vector<int> merged;
    size_t i = 0, j = 0;

    while (i < left.size() && j < right.size())
    {
        if (left[i] <= right[j])
        {
            merged.push_back(left[i]);
            i++;
        }
        else
        {
            merged.push_back(right[j]);
            j++;
        }
    }

    while (i < left.size())
    {
        merged.push_back(left[i]);
        i++;
    }

    while (j < right.size())
    {
        merged.push_back(right[j]);
        j++;
    }

    return merged;
}

std::vector<int> mergeSort(std::vector<int> &arr)
{
    if (arr.size() <= 1)
    {
        return arr;
    }

    int mid = arr.size() / 2;
    std::vector<int> left(arr.begin(), arr.begin() + mid);
    std::vector<int> right(arr.begin() + mid, arr.end());

    left = mergeSort(left);
    right = mergeSort(right);

    return merge(left, right);
}