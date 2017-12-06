#include <iostream>
#include <cstdlib>

using namespace std;

struct node
{
    int data;
    node *next;
}*head;

void add(int n)
{
    if(head == 0)
    {
        head = new node;
        head -> data = n;
        head -> next = NULL;
    }

    else
    {
        node *nNode;
        nNode = new node;
        nNode -> data = n;
        node *temp;
        temp = head;
        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = nNode;
        nNode -> next = NULL;
    }
}

void del()
{
    node *temp;
    temp = head;

    while(temp -> next -> next != NULL)
        temp = temp -> next;

    temp -> next = NULL;
}

void display()
{
    int count = 0;
    node *temp;
    temp = head;

    while(temp)
    {
        count++;
        cout << temp -> data << endl;
        temp = temp -> next;
        /*if(temp -> next == NULL)
        {
            cout << temp -> data << endl;
            break;
        }*/
    }
    cout << "\nNumber of Linked List = " << count << endl;
}

void clearNode()
{
    head = new node;
    head -> data = 0;
    head -> next = NULL;
}

int main()
{
    int a;
    char y;

    START:


    cout << "Enter value -1 to stop inputting the data\n";

    while(1)
    {
        cout << "input int: ";
        cin >> a;

        if(a == -1)
        {
            break;
        }
        add(a);
    }

    cout << "The input data\n\n";
    display();

    cout << "Do you wish to delete the last number?(y/n): ";
    cin >> y;

    if(y == 'y' || y == 'Y')
    {
        cout << "\n\nDeleting.......\n";
        del();
        cout << "\nThe input data\n\n";
        display();
        cout << "\n\nUse this program again?(y/n)";
        cin >> y;
        if(y == 'y' || y == 'Y')
        {
            cout << "\n\n";
            system("pause");
            system("cls");
            clearNode();
            goto START;
        }
         else if(y == 'n' || y == 'N')
         {
             return 0;
         }
    }

    else if(y == 'n' || y == 'N')
    {
        cout << "\n\n";
        system("pause");
        system("cls");
        cout << "\n\nUse this program again?(y/n)";
        cin >> y;
        if(y == 'y' || y == 'Y')
        {
            cout << "\n\n";
            system("pause");
            system("cls");
            clearNode();
            goto START;
        }
         else if(y == 'n' || y == 'N')
         {
             return 0;
         }
    }

}
