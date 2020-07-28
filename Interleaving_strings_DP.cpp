#include<bits/stdc++.h>
using namespace std;

bool isInterleave(string A, string B, string C)
{
    int n=A.length();
    int m=B.length();
    if(m+n!=C.length())
        return 0;
    bool dp[n+1][m+1];
    int i,j;
    //intialisation
    memset(dp,false,sizeof(dp));
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            if(i==0 && j==0)
                dp[i][j]=true;
            else if(i==0)
            {
                if(B[j-1]==C[j-1])
                    dp[i][j]=dp[i][j-1];
            }
            else if(j==0)
            {
                if(A[i-1]==C[i-1])
                    dp[i][j]=dp[i-1][j];
            }
            else if(A[i-1]==C[i+j-1] && B[j-1]!=C[i+j-1])
                dp[i][j]=dp[i-1][j];
            else if(B[j-1]==C[i+j-1] && A[i-1]!=C[i+j-1])
                dp[i][j]=dp[i][j-1];
            else if(A[i-1]==C[i+j-1] && B[j-1]==C[i+j-1])
                dp[i][j]=(dp[i-1][j] || dp[i][j-1]);
        }
    }
    return dp[n][m];
} 
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string a,b,c;
        cin>>a;
        cin>>b;
        cin>>c;
        cout<<isInterleave(a,b,c)<<endl;
    }
    return 0;
}