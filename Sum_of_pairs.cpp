#include<iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j,sum=0;
        cin>>n;
        int a[n];
        for(i=0;i<n;i++)
            cin>>a[i];
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if((abs(a[j]-a[i]))>1)
                {
                    sum+=a[j]-a[i];
                }
                else if((abs(a[j]-a[i]))<=1)
                {
                    sum+=0;
                }
            }
        }
        cout<<sum<<"\n";
    }
    return 0;
}