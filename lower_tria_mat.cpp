#include<iostream>
using namespace std;

class Lower_Triangular
{
    int arr[10];
    int n;

    public:

    Lower_Triangular(int a)
    {
        this->n=a;
    }

    void set(int i,int j,int x);
    int get(int i,int j);
    void display();
};

void Lower_Triangular::set(int i,int j,int x)
{
    if(i>=j)
    arr[i*(i-1)/2 + j-1]=x;
}

int Lower_Triangular::get(int i,int j)
{
    if(i>=j)
    return arr[i*(i-1)/2 + j - 1];

    else
    return 0;
}

void Lower_Triangular::display()
{
    for(int i=1;i<=n;i++)
    {
        for (int j = 1; j <=n; j++)
        {
            if(i>=j)
            cout<<arr[i*(i-1)/2 + j - 1]<<" ";

            else
            cout<<0<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    Lower_Triangular lt(3);

    lt.set(1,1,1);lt.set(2,1,2);lt.set(2,2,3);lt.set(3,1,4);
    lt.set(3,2,5);lt.set(3,3,6);

    lt.display();
    
    return 0;
}