#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> bucketSort(vector<int> array)
{
    int bucketSize = 10;
    int maxValue = array[0];
    int minValue = array[0];

    for (int value : array)
    {
        if (value > maxValue)
        {
            maxValue = value;
        }
        if (value < minValue)
        {
            minValue = value;
        }
    }

    int bucketCount = floor((maxValue - minValue) / bucketSize) + 1;
    vector<vector<int>> buckets(bucketCount);

    size_t n = array.size();

    for (size_t i = 0; i < n; i++)
    {
        int index = floor((array[i] - minValue) / bucketSize);
        buckets[index].push_back(array[i]);
    }

    array.clear(); // Limpiar el arreglo original

    for (vector<int> bucket : buckets)
    {
        sort(bucket.begin(), bucket.end());
        array.insert(array.end(), bucket.begin(), bucket.end());
    }

    return array;
}