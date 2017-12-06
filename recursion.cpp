#include <iostream>
#include <cmath>

using namespace std;

int func(int );

int main()
{
    int n, sum;

    cout << "Input integer: ";
    cin >> n;
    sum= func(n);

    cout << sum;
    return 0;
}

int func(int a)
{
    int sum =0;

    if(a==0)
    {
        cout << endl;
        return 1;
    }

    else
    {
        cout << a << "*";
        return a*func(a-1);
    }
}
