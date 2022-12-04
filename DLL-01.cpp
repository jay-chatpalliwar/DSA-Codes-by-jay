#include <bits/stdc++.h>
using namespace std;

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
} *first = NULL;

void Create(int arr[], int n)
{
    struct Node *t, *last;
    first = new Node;
    first->prev = first->next = NULL;
    first->data = arr[0];
    last = first;

    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = arr[i];
        t->prev = last;
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

void Display(struct Node *p)
{
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int Length(struct Node *p)
{
    int len = 0;
    while (p)
    {
        len++;
        p = p->next;
    }
    return len;
}

void Insert(struct Node *p, int x, int index)
{
    if (index < 0 || index > Length(p))
        return;

    struct Node *t;
    t = new Node;
    t->data = x;
    if (index == 0)
    {
        t->prev = first->prev;
        t->next = first;
        first->prev = t;
        first = t;
    }

    else
    {
        for (int i = 0; i < index - 1; i++)
            p = p->next;

        t->next = p->next;
        t->prev = p;
        if (p->next)
            p->next->prev = t;
        p->next = t;
    }
}

int Delete(struct Node *p, int index)
{
    if (index < 0 || index > Length(p))
        return -1;

    int x;
    for (int i = 0; i < index; i++)
        p = p->next;

    x = p->data;
    p->prev->next = p->next;
    if (p->next)
        p->next->prev = p->prev;
    delete p;
    return x;
}

void Reverse(struct Node *p)
{
    struct Node *temp;

    while (p != NULL)
    {
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->prev;

        if (p != 0 && p->next == 0)
            first = p;
    }
    Display(first);
}

void CreateCir(struct Node *p)
{
    struct Node *q = p;
    while (p->next != 0)
        p = p->next;

    p->next = q;
    q->prev = p;
}

void DisplayCir(struct Node *p)
{
    struct Node *q = p;
    do
    {
        cout << p->data << " ";
        p = p->next;
    } while (p != q);
}

void RDisplayCir(struct Node *p)
{
    static int x = 0;
    struct Node *q = p;
    if (x == 1 && p == q)
        return;

    else
    {
        cout << p->data << " ";
        x = 1;
        RDisplayCir(p->next);
    }
}
int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60, 70};

    Create(arr, 7);
    // Display(first);
    // cout<<Length(first)<<endl;
    // Insert(first,100,6);
    // Display(first);
    // cout << Delete(first, 4) << endl;
    // Display(first);
    // Reverse(first);
    CreateCir(first);
    // DisplayCir(first);
    RDisplayCir(first);

    return 0;
}