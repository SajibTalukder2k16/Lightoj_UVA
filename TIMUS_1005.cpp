#include<bits/stdc++.h>
using namespace std;
#define fastread     ios_base::sync_with_stdio(false);cin.tie(NULL);
int weight[21];
int n;
int foo(int pos,int first,int second)
{
    if(pos==n)
        return abs(first-second);
    int profit1=foo(pos+1,first+weight[pos],second);
    int profit2= foo(pos+1,first,second+weight[pos]);
    return min(profit1,profit2);
}
int main()
{
    fastread
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>weight[i];
    cout<<foo(0,0,0)<<endl;
}
