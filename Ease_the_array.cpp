#include<iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n],i;
        for(i=0;i<n;i++)
            cin>>a[i];
        int count=0;
        for(i=0;i<n-1;i++)
        {
            if(a[i] && a[i+1]==a[i] && a[i+1])
            {
                a[i]*=2;
                a[i+1]=0;
            }
        }
        for(i=0;i<n;i++)
            if(!a[i])
                count++;
        int k=0;
        for(i=0;i<n;i++)
        {
            if(a[i])
                a[k++]=a[i];
        }
        for(i=n-count;i<n;i++)
            a[i]=0;
        for(i=0;i<n;i++)
            cout<<a[i]<<" ";
        cout<<"\n";
    }
    return 0;
}