#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{
    ifstream file;
    int k = 1;
    char a[33];
    string b,c,sel;

    cout << "\nPlease select which patient to discharge:\npatient: ";
    cin >> std::ws;
    getline(cin, sel);

    remove(("patient"+ sel +".txt").c_str());

    // ka.open((id+ "withhistory.txt").c_str());

    while(1)
    {
        b = itoa(k, a, 10);
        file.open(("patient"+ b +".txt").c_str());
        if( file.is_open() )
        {
            cout << "success for patient " << k << endl;
            file.close();
        }

        else
        {
            cout << "failed to open file patient " << k << endl;
            b = itoa(k+1, a, 10);
            file.open(("patient"+ b +".txt").c_str());
            if( file.is_open() )
            {
                c = itoa(k, a, 10);
                cout << c<< endl << b;
                file.close();
                rename(("patient"+ b +".txt").c_str(), ("patient"+ c +".txt").c_str());
            }

            else
            {
                break;
            }
        }
        k++;
    }

}
