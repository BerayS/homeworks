#include <iostream>
#include <vector>
#include <fstream>


#pragma execution_character_set( "utf-8" );

using namespace std;

class Item {
    public:
        string ime;
        Item(string name = "null", double price = 0) {
            ime = name;
            cena = price;
        }

        void printData() {
            cout << "Produkt: " << ime << endl << "Cena: " << cena << endl;
        }
        
        void setCena(int k) {

            cena = k;

        }

        int getCena() {

            return cena;

        }
    private:
        double cena;
};



int main()
{     
    Item itemBox;
    vector<Item> items;
    ofstream outputFile("C:\\Users\\serin\\Desktop\\homework6.txt");
    

    while (true)
    {
        string ime;
        double cena;
      
        cout << "Ime: ";
        cin >> ime;
        if (ime == "0") break;
        
        cout << "Cena: ";
        cin >> cena;

        itemBox.ime = ime;
        itemBox.setCena(cena);

        items.push_back(itemBox);
    }

    // Displaying the vector using itterator
    for (auto it = items.begin(); it != items.end(); ++it) it->printData(); // Using the member function
    
    // Checking if file is opened, throw error if not
    if (!outputFile.is_open()) cout << "Error opening the file";
 
    // Write out the data to an output file "homework6.txt"
    for (int i = 0; i < items.size(); i++) outputFile << items[i].ime << '\t' << items[i].getCena() << "\n";
   
    // Close the file
    outputFile.close();

}
