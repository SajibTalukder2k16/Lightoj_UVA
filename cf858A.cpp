#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,k;
    cin>>n>>k;
    ll rounding= powl(10,k);
    int cntfive=0;
    ll temp=n;
    if(n%rounding==0)
    {
        cout<<n<<endl;
        return 0;
    }
    while(temp%5==0)
    {
        temp/=5;
        cntfive++;
    }

    int needfive =0;
    if(k>cntfive)
        needfive=k-cntfive;
    //cout<<needfive<<endl;
    temp = 1;
    while(needfive--)
        temp*=5;
    ll value=n*temp;
    //cout<<value<<endl;
    ll maxtwo=n;
    ll two=1;
    while(true)
    {
        temp=value*two;
        if(temp%rounding==0)
        {
            cout<<temp<<endl;
            break;
        }
        //cout<<value<<" "<<two<<" "<<value*two<<endl;
        two*=2;
    }
    //cout<<value<<" "<<two<<endl;
}
