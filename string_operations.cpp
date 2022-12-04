#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int length(string s)
{
    int count=0;

    for (int i = 0; s[i]!='\0'; i++)
    {
        count++;
    }
    return count;
}

void change(string s)
{
    for (int i = 0;s[i]!='\0'; i++)
    {
        s[i]+=32; //--->Changing uppercase to lowercase
    }
    cout<<s<<endl;
}

void reverse(string s)
{
    int l = length(s);

    for (int  i = l-1; i >=0; i--)
    {
       cout<<s[i];
    }
    
}
void duplicates(string s)
{
    int arr[26]={0};

    for(int i=0;s[i]!='\0';i++)
    arr[s[i]-97]++;

    for (int i = 0; i < 26; i++)
    {
        if(arr[i]>1)
        cout<<char(i+97)<<" "<<arr[i]<<endl;
    }
    
}

void IsAnagram(string a,string b)
{
    if(a.length()!=b.length())
    cout<<"Not an anagram!!"<<endl;

    else
    {
        int H[26]={0};

        for(int i=0;a[i]!='\0';i++)
        H[a[i]-97]++;

        for (int i = 0;b[i]!='\0'; i++)
         H[b[i]-97]--;

         int count=0;

         for (int i = 0; i < 26; i++)
         {
             if(H[i]==-1)
             count++;
         }
         
        if(count!=0)
        cout<<"Not an anagram!!"<<endl;

        else
        cout<<"Is anagram!!"<<endl;
        
    }
}

void permute(string s,int l,int h)
{
    if(l==h)
    cout<<s<<endl;

    else
    {
        for (int i = l; i <=h; i++)
        {
            swap(s[i],s[l]);
            permute(s,l+1,h);
            swap(s[i],s[l]);
        }
        
    }
}

int main()
{
    string s="medical";
    string t="decimak";

    permute("ABC",0,3);
    return 0;
}