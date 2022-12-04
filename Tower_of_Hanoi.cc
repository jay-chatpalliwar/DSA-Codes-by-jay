#include<bits/stdc++.h>
using namespace std;

void TOH(int n,int a=1,int b=2,int c=3)
{
    if(n>0)
    {
        TOH(n-1,a,c,b);
        printf("%d to %d\n",a,c);
        TOH(n-1,b,a,c);
    }
}

int main()
{
    int n;
    cin>>n;
    TOH(n);
    return 0;
}