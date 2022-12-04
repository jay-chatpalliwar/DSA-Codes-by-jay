#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
}*first;

int Count(struct Node *p)
{
    int count=0;

    while(p!=NULL)
    {
        count++;
        p=p->next;
    }
    return count;
}

void Insert(struct Node *p,int index,int x)
{
    if(index<0 || index > Count(p))
    return;

    struct Node *t,*a;
    t=new struct Node;

    t->data=x;

    if(index==0)
    {
        t->next=first;
        first=t;
    }

    else
    {a=first;
    for(int i=0;i<index-1;i++)
    a=a->next;
    t->next=a->next;
    a->next=t;
    }
}

void Display(struct Node *p)
{
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
}

int main()
{
    Insert(first,0,10);
    Insert(first,1,20);
    Insert(first,2,30);
    Insert(first,3,40);
    Insert(first,0,5);
    Display(first);
    return 0;
}