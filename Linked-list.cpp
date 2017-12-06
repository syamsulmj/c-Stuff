#include <iostream>
#include <cstdlib>

using namespace std;

struct node
{
    int data;
    node *next;
};

int main()
{
    node *first;
    first = new node; //c++-lang
    //first = (node*)malloc(sizeof(node)); // untuk c-lang
    first -> data = 10;
    first -> next = NULL;
    node *second;
    second = new node;
    second -> data = 20;
    second -> next = NULL;
    first -> next = second;
    node *third;
    third = new node;
    third -> data = 20;
    third -> next = NULL;
    second -> next = third;

    cout<<first<<endl;
    cout<<first->data<<endl;
    cout<<first->next<<endl;

    cout<<second<<endl;
    cout<<second->data<<endl;
    cout<<second->next<<endl;

    cout<<third<<endl;
    cout<<third->data<<endl;
    cout<<third->next<<endl;

}
