#include <bits/stdc++.h>
using namespace std;

struct Node //-->Self Referential Structure
{
    int data;
    struct Node *next;
} *first = NULL, *second = NULL, *third = NULL;

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

void Create1(int arr[], int n)
{
    second = new Node;
    struct Node *t, *last;
    second->data = arr[0];
    second->next = NULL;
    last = second;
    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = arr[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void Display(struct Node *p)
{
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void RDisplay(struct Node *p)
{
    if (p != NULL)
    {
        RDisplay(p->next); //---->Displaying Linked list in reverse
        // order.....
        cout << p->data << " ";
    }
    // cout<<endl;
}

int Count(struct Node *p)
{
    int c = 0;
    while (p)
    {
        c++;
        p = p->next;
    }
    return c;
}

int RCount(struct Node *p)
{
    if (!p)
        return 0;

    return RCount(p->next) + 1;
}

int Sum(struct Node *p)
{
    int sum = 0;

    while (p)
    {
        sum += p->data;
        p = p->next;
    }
    return sum;
}

int RSum(struct Node *p)
{
    if (!p)
        return 0;

    return RSum(p->next) + p->data;
}

int MaxNum(struct Node *p)
{
    int maxnum = INT_MIN;

    while (p != NULL)
    {
        if (p->data > maxnum)
            maxnum = p->data;
        p = p->next;
    }

    return maxnum;
}

int RMaxNum(struct Node *p)
{
    int x = 0;
    if (p == 0)
        return INT_MIN;

    x = RMaxNum(p->next);

    return x > p->data ? x : p->data;
}

bool Search(struct Node *p, int key)
{
    while (p)
    {
        if (p->data == key)
        {
            return true;
            break;
        }

        p = p->next;
    }
    return false;
}

bool RSearch(struct Node *p, int key)
{
    if (!p)
        return false;

    if (p->data == key)
        return true;

    else
        RSearch(p->next, key);
}

void Insert(struct Node *p, int index, int x)
{
    if (index < 0 || index > Count(p))
        return;

    struct Node *t;
    t = new struct Node;

    t->data = x;

    if (index == 0)
    {
        t->next = first;
        first = t;
    }

    else
    {
        for (int i = 0; i < index - 1; i++)
            p = p->next;
        t->next = p->next;
        p->next = t;
    }
}

void InsertLast(struct Node *p, int key)
{
    struct Node *t, *last;
    t = new Node;
    while (p)
    {
        last = p;
        p = p->next;
    }

    t->data = key;
    t->next = NULL;
    last->next = t;
    last = t;
}

void Delete(struct Node *p, int index)
{
    struct Node *q = NULL;
    int x;

    if (index == 1)
    {
        q = first;
        first = first->next;
        x = q->data;

        delete q;
    }

    else
    {
        for (int i = 0; i < index - 1 && p; i++)
        {
            q = p;
            p = p->next;
        }

        if (p)
        {
            q->next = p->next;
            x = p->data;
            delete p;
        }
    }
    cout << "Deleted data = " << x << endl;
    Display(first);
    cout << endl;
}

bool IsSorted(struct Node *p)
{
    int x = -32678;

    while (p)
    {
        if (p->data >= x)
        {
            x = p->data;
            p = p->next;
        }

        else
            return false;
    }
    return true;
}

void RemoveDuplicates(struct Node *p)
{

    struct Node *q, *t;
    q = p->next;
    t = p;

    while (q)
    {
        if (p->data != q->data)
        {
            p = q;
            q = q->next;
        }

        else
        {
            p->next = q->next;
            delete q;
            q = p->next;
        }
    }
    Display(t);
}

void ReverseLL(struct Node *p)
{
    struct Node *q;
    q = p;
    int arr[10]; //----->Auxiliary array
    int i = 0;
    while (p)
    {
        arr[i++] = p->data;
        p = p->next;
    }
    p = q;
    i--;
    while (p)
    {
        p->data = arr[i--];
        p = p->next;
    }

    Display(q);
}

void ReverseLinks(struct Node *p)
{
    struct Node *q = NULL, *r = NULL;
    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
    Display(first);
}

void Reverse(struct Node *q, struct Node *p)
{
    if (p)
    {
        Reverse(p, p->next);
        p->next = q;
    }
    else
        first = q;
}

void Concatenate(struct Node *p, struct Node *q)
{
    while (p->next != NULL)
        p = p->next;

    p->next = q;
}

void Merge(struct Node *p, struct Node *q)
{
    struct Node *last;
    if (p->data < q->data)
    {
        third = last = p;
        p = p->next;
        third->next = NULL;
    }
    else
    {
        third = last = q;
        q = q->next;
        third->next = NULL;
    }
    while (p && q)
    {
        if (p->data < q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }
    if (p)
        last->next = p;
    if (q)
        last->next = q;
}

bool isLoop(struct Node *f)
{
    struct Node *p, *q;
    p = q = f;
    do
    {
        p = p->next;
        q = q->next;
        q = (q != NULL) ? q->next : NULL;
    } while (p && q && p != q);

    return (p == q) ? true : false;
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

int Length(struct Node *p)
{
    struct Node *q=p;
    int count=0;
    do{
        count++;
        p=p->next;
    }while(p!=q);
    return count;
}

void InsertCir(struct Node *p,int index,int x)
{
    if(index<0 || index>Length(p))
    return;

    struct Node *t,*q=p;
    if(index==0)
    {
        t=new Node;
        t->data=x;

        if(p==NULL)
        {
            p=t;
            p->next=p;
        }

        else
        {
            while(p->next!=q)
            p=p->next;

            p->next=t;
            t->next=q;
            q=t;
            first=t;
        }
    }

    else
    {
        t=new Node;
        t->data=x;

        for(int i=0;i<index-1;i++)
        p=p->next;

        t->next=p->next;
        p->next=t;
    }
}

int DeleteCir(struct Node *p,int index)
{
    if(index<0||index>Length(p))
    return -1;

    struct Node *q;
    int x=0;

    if(index==1)
    {
       x=first->data;

       while(p->next!=first)
       p=p->next;

       if(p==first)
       {
           delete first;
           first=NULL;
       }

       else
       {
           p->next=first->next;
           delete first;
           first=p->next;
       }
    }

    else
    {
        for(int i=0;i<index-2;i++)
        p=p->next;

        q=p->next;

        x=q->data;
        p->next=q->next;
        delete q;
    }

    return x;
}
int main()
{
    //     int arr[] = {21, 23, 34, 54, 54, 32};
    //     Create(arr, 6);
    //    Display(first);
    //    RDisplay(first);
    //    cout<<endl;
    //    cout<<Count(first)<<endl;
    //    cout<<RCount(first)<<endl;
    //    cout<<Sum(first)<<endl;
    //    cout<<RSum(first)<<endl;
    //    cout<<MaxNum(first)<<endl;
    //    cout<<RMaxNum(first)<<endl;
    //    cout<<Search(first,30)<<endl;
    //    cout<<RSearch(first,30)<<endl;
    // Insert(first, 0, 10);
    // Insert(first, 1, 20);
    // Insert(first, 2, 30);
    // Insert(first, 3, 40);
    // Insert(first, 0, 5);
    // Insert(first, 2, 15);
    // InsertLast(first,100);
    // InsertLast(first,200);
    // Delete(first, 3);
    // Delete(first, 1);
    // cout<<IsSorted(first)<<endl;
    // RemoveDuplicates(first);
    // ReverseLL(first);

    // int n;
    // cin >> n;
    // int arr[n];
    // for (int i = 0; i < n; i++)
    //     cin >> arr[i];

    // Create(arr, n,first);
    // ReverseLL(first);
    // ReverseLinks(first);
    // struct Node *q = NULL;
    // Reverse(q, first);
    // Display(first);

    int a[5] = {12, 32, 43, 56, 67};
    // int b[4] = {1, 2, 3, 4};
    Create(a, 5);
    // Create1(b, 4);
    // Concatenate(first,second);
    // Display(first);

    // Merge(first, second);
    // Display(third);

    // struct Node *t1, *t2;
    // t1 = first->next->next->next;
    // t2 = first->next->next->next->next;
    // t2->next = t1;
    // cout << isLoop(first) << endl;

    CreateCir(first);
    // DisplayCir(first);
    // cout<<endl;
    // RDisplayCir(first);
    // cout<<Length(first)<<endl;
    // InsertCir(first,7,100);
    // DisplayCir(first);
    int k=DeleteCir(first,10);
    cout<<k<<endl;
    DisplayCir(first);

    return 0;
}