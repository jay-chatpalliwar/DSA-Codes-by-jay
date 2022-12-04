#include<iostream>
using namespace std;

class Symmetric_matrix
{
    int arr[10];
    int n;

    public:

    Symmetric_matrix(int a)
    {
        this->n=a;
    }

    void set(int i,int j,int x);
    int get(int i,int j);
    void display();
};

void Symmetric_matrix::set(int i,int j,int x)
{
    if(i>=j)
    arr[i*(i-1)/2 + j-1]=x;

}

int Symmetric_matrix::get(int i,int j)
{
    if(i>=j)
    return arr[i*(i-1)/2 + j-1];

    else
    return arr[j*(j-1)/2 + i-1];
}

void Symmetric_matrix::display()
{
    for(int i=1;i<=n;i++)
    {
        for (int j = 1; j <=n; j++)
        {
            if(i>=j)
            cout<<arr[i*(i-1)/2 + j-1]<<" ";

            else
            cout<<arr[j*(j-1)/2 + i-1]<<" ";

        }
        cout<<endl;
    }
}

int main()
{
    Symmetric_matrix lt(3);

    lt.set(1,1,1);lt.set(2,1,2);lt.set(2,2,3);lt.set(3,1,4);
    lt.set(3,2,5);lt.set(3,3,6);

    lt.display();
    
    return 0;
}