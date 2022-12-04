#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *Top = NULL;

void Display()
{
    struct Node *q = Top;
    while (q)
    {
        cout << q->data << " ";
        q = q->next;
    }
}
void push(int x)
{
    struct Node *t;
    t = new Node;
    if (t == NULL)
        return;

    t->data = x;
    t->next = Top;
    Top = t;
}

int pop()
{
    if (Top == NULL)
        return -1;

    struct Node *q;
    q = Top;

    int x = Top->data;
    Top = Top->next;
    delete q;
    return x;
}

int Peek(int index)
{
    struct Node *q = Top;
    for (int i = 0; i < index - 1 && q != NULL; i++)
        q = q->next;

    if (q)
        return q->data;

    return -1;
}

int StackTop()
{
    if (!Top)
        return -1;

    else
    {
        int x = Top->data;
        return x;
    }
}

bool IsEmpty()
{
    if (!Top)
        return true;

    return false;
}

bool IsFull()
{
    struct Node *q;
    q = new Node;

    if (q == NULL)
    {
        delete q;
        return true;
    }

    else
    {
        delete q;
        return false;
    }
}

int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    pop();
    pop();
    push(100);
    push(200);
    // cout<<Peek(3)<<endl;
    cout << StackTop() << endl;
    Display();
    return 0;
}