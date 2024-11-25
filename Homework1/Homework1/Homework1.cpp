#include <string>
#include <iostream>
using namespace std;

	// Domashna rabota 1

int main()
{

	// Zad 1

	string a = "";
	getline(cin, a);

	int kliomba = a.find_first_of("@"); // Finds the first appear of any of these symbols - 1 as in e in "Hello"
	int dot = a.find_last_of(".");

	string s1 = a.substr(0, kliomba);
	string s2 = a.substr(kliomba + 1, a.length());
	string s3 = a.substr(dot + 1, a.length());



	cout << "Потребител:" << s1 << endl;
	cout << "Сървър: " << s2 << endl;

	if (s3 == "bg") cout << "Националност: Български" << endl; else cout << "Националност: Други" << endl;



	// Zad 2

	string b = "";
	getline(cin, b);
	string bCopy = b;
	
	if (b == "") {
		cout << "Няма въведена информация." << endl;
	}
	else {

		int semicolonInd = b.find_first_of(":");

		bCopy.erase(0, semicolonInd + 3);

		int slash = bCopy.find_first_of("/");
		int lastSlash = bCopy.find_last_of("/");

		string protocol = b.substr(0, semicolonInd);
		string host = bCopy.substr(0, slash);
		bCopy.erase(0, slash);
		string path = bCopy.substr(0, lastSlash);
		string file = path.substr(path.find_last_of("/") + 1, path.length());

		cout << "Протокол: " << protocol << endl;
		cout << "Хост: " << host << endl;
		cout << "Път: " << path << endl;
		cout << "Файл: " << file << endl;

	}
}