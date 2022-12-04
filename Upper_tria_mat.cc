//----->Used ROW MAJOR MAPPING******
#include<bits/stdc++.h>
using namespace std;

class Upper_Triangular
{
    int arr[10];
    int n;

    public:

    Upper_Triangular(int a)
    {
        this->n=a;
    }

    void set(int i,int j,int x);
    int get(int i,int j);
    void display();
};

void Upper_Triangular::set(int i,int j,int x)
{
    if(i<=j)
    arr[(i-1)*n-(i-1)*(i-2)/2 + j-i]=x;
}

int Upper_Triangular::get(int i,int j)
{
    if(i<=j)
    return arr[(i-1)*n-(i-1)*(i-2)/2 + j-i];

    else
    return 0;
}

void Upper_Triangular::display()
{
    for (int i = 1; i <=n; i++)
    {
        for (int j = 1; j <=n; j++)
        {
            if(i<=j)
            cout<<arr[(i-1)*n-(i-1)*(i-2)/2 + j-i]<<" ";

            else
            cout<<0<<" ";
        }
        cout<<endl;
    }
    
}

int main()
{
    Upper_Triangular ut(4);

    ut.set(1,1,1);ut.set(1,2,2);ut.set(1,3,3);ut.set(1,4,4);
    ut.set(2,2,5);ut.set(2,3,6);ut.set(2,4,7);ut.set(3,3,8);
    ut.set(3,4,9);ut.set(4,4,10);

    cout<<ut.get(2,4)<<endl;
    ut.display();
    return 0;
}