#include<iostream>

using namespace std;

class Toeplitz_matrix
{
    int arr[10];
    int n;

    public:

    Toeplitz_matrix(int a)
    {
        this->n=a;
    }

    void set(int i,int j,int x);
    int get(int i,int j);
    void display();
};

void Toeplitz_matrix::set(int i,int j,int x)
{
    if(i<=j)
    arr[j-i]=x;

    else
    arr[n + i - j - 1]=x;

}

int Toeplitz_matrix::get(int i,int j)
{
    if(i<=j)
    return arr[j-i];

    else
    return arr[n+i-j-1];
}

void Toeplitz_matrix::display()
{
    for(int i=1;i<=n;i++)
    {
        for (int j = 1; j <=n; j++)
        {
            if(i<=j)
            cout<<arr[j-i]<<" ";

            else
            cout<<arr[n+i-j-1]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    Toeplitz_matrix tm(4);
    tm.set(1,1,6);tm.set(1,2,3);tm.set(1,3,9);tm.set(1,4,5);
    tm.set(2,1,4);tm.set(3,1,6);tm.set(4,1,8);

    tm.display();
    return 0;
}