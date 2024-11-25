#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;


int main()
{
  
    // Zad 1
    //
    //fstream file; 
    //string fileName = "C:\\Users\\beray\\Desktop\\homeworkex1.txt";

    //file.open(fileName); 

    //vector<string> v1; 
    //string x; 
    // 
    //if (!file.is_open()) { 
    //    cout << "Error while reading file"; 
    //}
    //while (file >> x) { 
    //    v1.push_back(x); 
    //}
    // 
    //sort(v1.begin(), v1.end()); 

    //for (string el : v1) { 
    //    cout << el << endl; 
    //}
    // 
    //file.close(); 

    // Zad 2

    vector<int> numbers;
    int num;

    cout << "Enter numbers (0 for end): ";
    while (true) {
        cin >> num;
        if (num == 0) break;
        numbers.push_back(num);
    }

    if (numbers.empty()) {
        cout << "No numbers entered" << endl;
        return 0;
    }

    vector<int> max_sequence;
    vector<int> current_sequence = { numbers[0] };

    for (size_t i = 1; i < numbers.size(); ++i) {
        if (numbers[i] == numbers[i - 1]) {
            current_sequence.push_back(numbers[i]);
        }
        else {
            if (current_sequence.size() >= max_sequence.size()) {
                max_sequence = current_sequence;
            }
            current_sequence = { numbers[i] };
        }
    }

    if (current_sequence.size() >= max_sequence.size()) {
        max_sequence = current_sequence;
    }

    cout << "Longest sequence is: ";
    for (int val : max_sequence) {
        cout << val << " ";
    }
    cout << endl;
     

}