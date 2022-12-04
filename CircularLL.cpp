#include<iostream>
using namespace std;

struct Node //-->Self Referential Structure
{
    int data;
    struct Node *next;
} *first = NULL;

void Create(int arr[], int n)
{
    first = new Node;
    struct Node *t, *last;
    first->data = arr[0];
    first->next = NULL;
    last = first;
    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = arr[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void CreateCir(struct Node *p)
{
    struct Node *q;
    q=p;
    while(p->next!=NULL)
    p=p->next;

    p->next=q;
}

void DisplayCir(struct Node *p)
{
    do
    {
        cout<<p->data<<" ";
        p=p->next;
    } while (p!=first);
}

void RDisplayCir(struct Node *p)
{
    static int count=0;
    if(p!=first || count==0)
    {
        count=1;
        cout<<p->data<<" ";
        RDisplayCir(p->next);
    }
}

int main()
{
    int A[]={3,6,2,7,9,10};
    Create(A,6);
    CreateCir(first);
    DisplayCir(first);
    return 0;
}