#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string txt;
    cout << "type something to save: ";
    getline(cin, txt);

    ofstream out("data.txt");
    out << txt;
    out.close();
    cout << "saved to data.txt\n";

    cout << "\nreading back...\n";
    ifstream in("data.txt");
    string line;
    while (getline(in, line)) cout << line << "\n";
    in.close();

    cout << "\nall done.\n";
}