#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> readCSV(string filename)
{
    vector<int> data;
    ifstream file(filename);
    string line;

    while (getline(file, line))
    {
        stringstream ss(line);
        string field;

        while (getline(ss, field, ';'))
        {
            data.push_back(stoi(field));
        }
    }

    return data;
}

map<string, vector<int>> loadData()
{
    map<string, vector<int>> data;
    vector<string> dataArray = {
        "numeros_aleatorios_100.csv",
        "numeros_aleatorios_1000.csv",
        "numeros_aleatorios_2000.csv",
        "numeros_aleatorios_3000.csv",
        "numeros_aleatorios_4000.csv",
        "numeros_aleatorios_5000.csv",
        "numeros_aleatorios_6000.csv",
        "numeros_aleatorios_7000.csv",
        "numeros_aleatorios_8000.csv",
        "numeros_aleatorios_9000.csv",
        "numeros_aleatorios_10000.csv",
        "numeros_aleatorios_20000.csv",
        "numeros_aleatorios_30000.csv",
        "numeros_aleatorios_40000.csv",
        "numeros_aleatorios_50000.csv"};

    for (auto e : dataArray)
    {
        data[e] = readCSV("../../../data/" + e);
    }

    return data;
}
