#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include <cstdlib>

using namespace std;

struct accountDb
{
    string username, password, email;
    accountDb *next;
}*head;

void add(string ,string , string);
string readAccountKeBerapa();
void readUntukLinkedList();
void addDalamLinkedList(string );
bool untukLogin(string ,string );

int main()
{
    string uname, pass, email;
    int choice;

    readUntukLinkedList();

    cout << "Pilih\n1. Sign Up\n2. Login\nChoice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "Sign Up a New Account\n";
        cout << "Username: ";
        cin >> uname;
        cout << "Password: ";
        cin >> pass;
        cout << "Email: ";
        cin >> email;

        add(uname, pass, email);
        break;

    case 2:
        cout << "Username: ";
        cin >> uname;
        cout << "Password: ";
        cin >> pass;
        if(untukLogin(uname, pass) == true)
        {
            cout << "\n\nSuccessfully Login\n";
        }
        else
        {
            cout << "\n\nLogin Not Successfully\n";
        }

        break;
    }




}

void add(string userN, string pas, string em)
{
    ofstream file;
    string b = readAccountKeBerapa();

    file.open(("account"+b+".txt").c_str());

    if(head == 0)
    {
        head = new accountDb;
        head->username = userN;
        head->password = pas;
        head->email = em;

        file << head->username << endl;
        file << head->password << endl;
        file << head->email;

        file.close();

    }

    else
    {
        accountDb *temp, *newAccDb;

        newAccDb = new accountDb;
        temp = head;

        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }

        newAccDb->username = userN;
        newAccDb->password = pas;
        newAccDb->email = em;

        file << newAccDb->username << endl;
        file << newAccDb->password << endl;
        file << newAccDb->email;

        file.close();

        temp->next = newAccDb;
        newAccDb->next= NULL;
    }

}

string readAccountKeBerapa()
{
    ifstream file;
    int k = 1;
    char a[33];
    string b;

    while(1)
    {
      b = itoa(k, a, 10);
      file.open(("account" + b +".txt").c_str());

      if(file.is_open())
      {
          file.close();
      }
      else
      {
          break;
      }
      k++;

    }

    return itoa(k, a, 10);
}

void readUntukLinkedList()
{
    ifstream file;
    int k = 1;
    char a[33];
    string b;

    while(1)
    {
      b = itoa(k, a, 10);
      file.open(("account" + b +".txt").c_str());

      if(file.is_open())
      {
          addDalamLinkedList(b);
          file.close();
      }
      else
      {
          break;
      }
      k++;

    }

}

void addDalamLinkedList(string  b)
{
    ifstream file;
    file.open(("account" + b +".txt").c_str());

    if(head == 0)
    {
        head = new accountDb;

        file >> std::ws;
        getline(file, head->username);
        getline(file, head->password);
        getline(file, head->email);

        head -> next = NULL;
    }

    else
    {
        accountDb *nNode;
        nNode = new accountDb;

        accountDb *temp;
        temp = head;
        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }


        file >> std::ws;
        getline(file, nNode->username);
        getline(file, nNode->password);
        getline(file, nNode->email);

        temp -> next = nNode;
        nNode -> next = NULL;
    }

    file.close();
}

bool untukLogin(string a, string b)
{
    bool login = false;
    accountDb *temp;
    temp = head;


    while(temp)
    {
        if(a == temp->username && b == temp->password)
        {
            login = true;
            break;
        }

        temp = temp -> next;
    }

    return login;
}
