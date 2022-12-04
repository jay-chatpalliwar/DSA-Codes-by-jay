#include <bits/stdc++.h>
using namespace std;
#define JAY main

class Term
{
public:
    int coef;
    int exp;
};

class Polynomial
{
public:
    int n;
    Term *t;

    // Polynomial()
    // {
    //     int a;
    //     cout << "Enter the no. of terms in the polynomial :" << endl;
    //     cin >> a;
    //     this->n = a;
    //     t = new Term[this->n];
    // }

    Polynomial(int a)
    {
        this->n = a;
        t = new Term[this->n];
    }

    ~Polynomial()
    {
        delete[] t;
    }
    void create()
    {
        cout << "Enter terms in the polynomial :\n";
        for (int i = 0; i < n; i++)
        {
            cin >> t[i].coef >> t[i].exp;
        }
    }
    void display()
    {
        cout << "Displaying the polynomial :\n";
        for (int i = 0; i < n; i++)
            cout << t[i].coef << "y^" << t[i].exp << "+";
        cout << endl;
    }

    void evaluate(int x)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += t[i].coef * pow(x, t[i].exp);

        cout << "The value of polynomial at x=" << x << " is :" << sum;
    }
};

Polynomial *sum(Polynomial p1,Polynomial p2)
{
    Polynomial *sum;

    sum=new Polynomial(p1.n + p2.n);
    sum->t=new Term[p1.n + p2.n];

    int i,j,k;
    i=j=k=0;
    while(i<p1.n|| j<p2.n)
    {
        if(p1.t[i].exp>p2.t[j].exp)
        sum->t[k++]=p1.t[i++];

        else if(p1.t[i].exp>p2.t[j].exp)
        sum->t[k++]=p2.t[j++];

        else
        {
            sum->t[k].exp=p1.t[i].exp;
            sum->t[k++].coef=p1.t[i++].coef + p2.t[j++].coef;
        }
    }
    for(;i<p1.n;i++)sum->t[k++]=p1.t[i];
    for(;j<p2.n;j++)sum->t[k++]=p2.t[j];

    sum->n=k;
    return sum;
    // delete sum;
    // delete []sum->t;
}
int JAY()
{
    Polynomial p1(2),p2(2),*p3;
    p1.create();
    p2.create();
    p3=sum(p1,p2);
    p3->display();
    p1.~Polynomial();
    p2.~Polynomial();
    p3->~Polynomial();
}