#include <iostream>

using namespace std;


int size = 10;
int top = -1;
int st[10];


int pop()
{
    int x = st[top];
    top--;
    return x;
}

int isEmpty()
{
    if(top == -1)
        return 1;
    else
        return 0;
}

int isFull()
{
    if(!isEmpty())
    {
        if(top == size-1)
            return 1;

        else
            return 0;
    }
}

void push(int n)
{
    if(!isFull())
    {
        top++;
        st[top] = n;
    }
    else
        cout << "\nStack is full, push is not allowed\n\n";


}

void read()
{
    for(int i=0; i<size; i++)
    {
        if(st[i] == NULL)
        {
            break;
        }
        cout << "stack " << i+1 << " = " << st[i] << endl;
    }
}


int main()
{
    int a = 10;

    for(int i= 0; i<10; i++)
    {
        push(a);
        cout << a << " has been pushed to the stack\n";
        a += 20;
    }
    push(10);
    pop();
    push(10);
    read();

    return 0;


}
