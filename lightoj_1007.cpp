#include<bits/stdc++.h>
using namespace std;
#define mx 5000001
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    vector<unsigned long long>euler(mx);
    euler[1]=1;
    for(int i=2;i<mx;i++)
    {
        euler[i]=i-1;
    }
    for(int i=2;i<mx;i++)
    {
        for(int j=i+i;j<mx;j+=i)
        {
            euler[j]=euler[j]-euler[i];
        }
    }
    euler[0]=0;
    for(int i=1;i<mx;i++)
    {
        euler[i] = euler[i]*euler[i];
        euler[i] = euler[i]+euler[i-1];
    }
    int test,cs;
    cin>>test;
    int a,b;
    for(cs=1;cs<=test;cs++)
    {
        cin>>a>>b;
        a--;
        cout<<"Case "<<cs<<": "<<euler[b]-euler[a]<<endl;
    }
}
