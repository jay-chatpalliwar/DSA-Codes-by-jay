#include <bits/stdc++.h>
using namespace std;

struct Stack
{
    int Top;
    int size;
    int *s;
};

void Display(struct Stack st)
{
    for (int i = st.Top; i >= 0; i--)
    {
        cout << st.s[i] << " ";
    }
}

void push(struct Stack *st, int x)
{
    if (st->Top != st->size - 1)
    {
        st->Top++;
        st->s[st->Top] = x;
    }

    else
        cout << "Stack overflow!\n";
}

int pop(struct Stack *st)
{
    if (st->Top == -1)
        return -1;

    else
    {
        int x = st->s[st->Top];
        st->Top--;
        st->size--;

        return x;
    }
}

int peek(struct Stack st, int index)
{
    if (st.Top - index + 1 < 0)
        return -1;

    else
    {
        int x = st.s[st.Top - index + 1];

        return x;
    }
}

int stackTop(struct Stack st)
{
    if (st.Top == -1)
        return -1;

    else
        return st.s[st.Top];
}

bool isEmpty(struct Stack st)
{
    if (st.Top == -1)
        return true;

    return false;
}

bool isFull(struct Stack st)
{
    if (st.Top == st.size - 1)
        return true;

    return false;
}

int main()
{
    struct Stack st;

    cin >> st.size;
    st.s = new int[st.size];
    st.Top = -1;

    push(&st, 10);
    push(&st, 20);
    push(&st, 30);
    push(&st, 40);
    // int x= pop(&st);
    // cout<<x<<endl;

    // int x=peek(st,3);
    // cout<<x<<endl;
    // cout<<stackTop(st)<<endl;
    Display(st);
    // cout << endl;
    // cout << isFull(st) << endl;
    // cout << isEmpty(st) << endl;

    return 0;
}