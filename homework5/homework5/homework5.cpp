#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <windows.h>

using namespace std;

int main() {
    SetConsoleOutputCP(65001);
    ifstream inFile("C:\\Users\\serin\\Desktop\\homework5.txt");
    ofstream outFile("C:\\Users\\serin\\Desktop\\sorted_sales.txt");

    //vector<Item> salesData;
    vector<pair<string, double>> salesData;
    vector<pair<string, double>> sorted;

    string itemName;
    int quantity;
    double price;


    if (!inFile.is_open() || !outFile.is_open()) {
        cerr << "Грешка при отваряне на файлове!" << endl;
        return 1;
    }

    while (inFile >> itemName >> quantity >> price) {
        double currentValue = quantity * price;

        // Проверка дали стоката вече съществува във вектора
        bool found = false;
        for (int i = 0; i < salesData.size(); ++i) {
            if (salesData[i].first == itemName) {
                // Ако съществува, добавяме стойността към съществуващата
                salesData[i].second = currentValue;
                found = true;
                break;
            }
        }
        if (!found) {
            // Ако не съществува, добавяме нов запис
            salesData.push_back(make_pair(itemName,currentValue));
        }
    }


    inFile.close();

    // Сортиране на salesData.
    for (int i = 0; i < salesData.size(); i++) {

        int pos = 0;

        while ((pos < sorted.size()) && (salesData[i].second < salesData[pos].second))

            pos++;

        if (pos == sorted.size()) sorted.push_back(make_pair(salesData[i].first,salesData[i].second));

        else sorted.insert(sorted.begin() + pos, salesData[i]);

    }


    // Записване на резултатите във файла
    for (pair<string,double> e : sorted) {
        outFile << e.first << "\t" << e.second << endl;
    }

    outFile.close();

    cout << "Обработката на файла е завършена.";

    return 0;
}