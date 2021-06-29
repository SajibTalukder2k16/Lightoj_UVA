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
#define pb push_back
int main()
{
    int test;
    cin>>test;
    for(int cs=1;cs<=test;cs++)
    {
        string str;
        cin>>str;
        cout<<"Case "<<cs<<": ";
        if(str[4]=='s')
        {
            cout<<str<<endl;
        }
        else
        {
            for(int i=0;i<4;i++)
                cout<<str[i];
            cout<<'s';
            int len=str.length();
            for(int i=4;i<len;i++)
                cout<<str[i];
            cout<<endl;
        }
    }
}
