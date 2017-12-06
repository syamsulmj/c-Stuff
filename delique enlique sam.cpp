#include <iostream>
#include <cstdlib>

using namespace std;

struct node
{
    int data;
    node *next;
}*head,*rear;

void enqueue(int , int &);
int dequeue();
void display();
bool ifEmpty();

int main()
{
    int ticket = 1000, customer, x;

    cout<<"-------------------------------------------------"<<endl;
    cout<<"             WELCOME TO SYUKUR BANK              "<<endl;
    cout<<"-------------------------------------------------"<<endl;

    while(1)
    {
        cout<<"\nPlease enter how many customers: ";
        cin>>customer;

        enqueue(customer, ticket);

        while(1)
        {
            cout << "\nPLEASE SELECT WHICH ACTION\n1. Call Next Customer\n2. Display Remaining Customers\n3. Add More Customers\n4. Exit\nSELECT: ";
            cin >> x;

            switch(x)
            {
            case 1:
                if(head->data == NULL)
                {
                    cout << "\n\nThere's No More Customers Left.\n\n";
                }
                else
                {
                    cout << "\n\nCalling Customer Number: " << dequeue() << "\n\n";
                }

                system("pause");
                system("cls");
                break;
            case 2:
                cout << "\n\nRemaining Customer Numbers:\n";
                display();
                system("pause");
                system("cls");
                break;
            case 3:
                system("pause");
                system("cls");
                break;
            case 4:
                return 0;
            }
            if(x == 3)
            {
                break;
            }
        }
    }



    return 0;
}

void enqueue(int n, int &a)
{
    for(int i= 0; i<n; i++)
    {
        if(ifEmpty())
        {
            head = new node;
            head -> data = a;
            head -> next = NULL;
        }

        else
        {
            node *nNode;
            nNode = new node;
            nNode -> data = a+1;
            a++;
            node *temp;
            temp = head;
            while(temp -> next != NULL)
            {
                temp = temp -> next;
            }
            temp -> next = nNode;
            nNode -> next = NULL;
            rear = nNode;
        }
    }

}

int dequeue()
{
    node *temp;
    if(head->next == NULL)
    {
        if(head->data != NULL)
        {
            temp = new node;
            temp->data = NULL;
            temp->next = NULL;
            head = temp;
            return rear->data;
        }
        else
            return 0;
    }
    else
    {
        temp = head->next;
        delete head;
        head = temp;
        return head->data-1;
    }



}

void display()
{
    int count = 0;
    node *temp;
    temp = head;

    while(temp)
    {
        count++;
        if(head->data == NULL)
        {
            cout << "\n\n\n";
        }
        else
        {
            cout << temp -> data << endl;
        }
        temp = temp -> next;

    }

    if(head->data == NULL)
    {
        cout << "\nNumber of Customers Remaining = " << count-1 << endl;
        cout << "Current Number: N/A" << endl;
    }
    else
    {
        cout << "\nNumber of Customers Remaining = " << count << endl;
        cout << "Current Number: " << head->data << endl;
    }

}

bool ifEmpty()
{
    if (head == NULL)
        return 1;
    else
        return 0;
}
