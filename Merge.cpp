#include <bits/stdc++.h>
using namespace std;
#define ll long long int

struct Array
{
    int A[20];
    int size;
    int length;
}typedef arry;

void display(arry arr)
{
    int i=0;

    for(i;i<arr.length;i++)
    cout<<arr.A[i]<<" ";
}
void Merge(arry arr1,arry arr2,arry *arr3)
{
    int i=0,j=0,k=0;

    while(i<arr1.length && j<arr2.length)
    {
        if(arr1.A[i]<arr2.A[j])
        arr3->A[k++]=arr1.A[i++];

        else
        arr3->A[k++]=arr2.A[j++];
    }

    for(;i<arr1.length;i++)
    arr3->A[k++]=arr1.A[i];

    for(;j<arr2.length;j++)
    arr3->A[k++]=arr2.A[j];

    arr3->length=arr1.length+arr2.length;
    arr3->size=20;

}

int main()
{
    arry arr1={{2,3,5,8,9,10},10,6};
    arry arr2={{4,6,7,12,15,20},10,6};
    arry arr3;

    Merge(arr1,arr2,&arr3);

    display(arr3);
    cout<<endl;

    cout<<arr3.length<<" "<<arr3.size<<endl;

    return 0;
}