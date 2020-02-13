#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        string a,b,c;
        cin>>a>>b>>c;
        int l=a.length();
        int cnt = 0;
        for(int i=0;i<l;i++)
        {
            if(b[i]==c[i]||c[i]==a[i])
                cnt++;
        }
        if(cnt==l)
        {
            cout<<"Yes"<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        }
    }
}
