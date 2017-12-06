#include <iostream>
#include <iomanip>
#include <cstring>
#include <locale>

using namespace std;


int main()
{
    string nama;
    cout << "Masuk nama mung!: ";
    getline(cin, nama);

    cout << "\n\n";
    for(int i=0; i<nama.length(); i++)
    cout << toupper(nama[i], locale());

}
