#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

struct node
{
    string data[6];
    node *next;

}*head;

void add(string  b)
{
    ifstream file;
    file.open(("kambing" + b +".txt").c_str());

    if(head == 0)
    {
        head = new node;

        for(int i = 0; i<5; i++)
        {
            file >> std::ws;
            getline(file, head->data[i]);
        }
        //head -> data = n;
        head -> next = NULL;
    }

    else
    {
        node *nNode;
        nNode = new node;
        //nNode -> data = n;
        node *temp;
        temp = head;
        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }

        for(int i = 0; i<5; i++)
        {
            file >> std::ws;
            getline(file, nNode->data[i]);
        }

        temp -> next = nNode;
        nNode -> next = NULL;
    }

    file.close();
}

void display()
{

    int count = 0;
    node *temp;
    temp = head;

    while(temp)
    {
        count++;
        for(int i=0; i<5; i++)
        {
            cout << temp -> data[i] << endl;
        }

        temp = temp -> next;
        cout << "\n\n";
    }

}

void addfile()
{
    ofstream file;
    string c[6];

    cout << "name: ";
    cin >> std::ws;
    getline(cin, c[0]);

    cout << "age: ";
    cin >> std::ws;
    getline(cin, c[1]);

    cout << "gender: ";
    cin >> std::ws;
    getline(cin, c[2]);

    cout << "colour: ";
    cin >> std::ws;
    getline(cin, c[3]);

    cout << "ada apa?: ";
    cin >> std::ws;
    getline(cin, c[4]);

    ifstream file1;
    int k = 1;
    char a[33];
    string b;

    while(1)
    {
        b = itoa(k, a, 10);
        file1.open(("kambing" + b +".txt").c_str());

        if(file1.is_open())
        {
            file1.close();
        }
        else
        {
            break;
        }
        k++;

    }

    b = itoa(k, a, 10);
    file.open(("kambing" + b +".txt").c_str());

    for(int i=0; i<5; i++)
    {
        file << c[i] << endl;
    }
    file.close();
}

int main()
{

    ifstream file;
    int k = 1;
    char a[33];
    string b;

    cout << "add new file\n\n";
    addfile();

    while(1)
    {
      b = itoa(k, a, 10);
      file.open(("kambing" + b +".txt").c_str());

      if(file.is_open())
      {
          add(b);
          file.close();
      }
      else
      {
          break;
      }
      k++;

    }

    display();

}
