#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;
#define fastread     ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fileRead freopen("input.txt","r",stdin);
#define fileWrite freopen("output.txt","w",stdout);
#define ll long long
#define mp make_pair
#define mod 1000000007
#define pi 3.141593
string a,b,c;
#define m 51
int dp[m][m][m];
int lcs(int i,int j,int k)
{
    if(i==a.length()||j==b.length()||k==c.length())
        return 0;
    if(dp[i][j][k]!=-1)
        return dp[i][j][k];
    if(a[i]==b[j] && b[j]==c[k])
        return dp[i][j][k]=1+lcs(i+1,j+1,k+1);
    else
        return dp[i][j][k]=max(lcs(i,j,k+1),max(lcs(i,j+1,k),lcs(i+1,j,k)));
}
int main()
{
    int test;
    cin>>test;
    for(int cs=1;cs<=test;cs++)
    {
        memset(dp,-1,sizeof dp);
        cin>>a>>b>>c;
        cout<<"Case "<<cs<<": "<<lcs(0,0,0)<<endl;
    }
}
