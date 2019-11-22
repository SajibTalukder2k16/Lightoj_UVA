#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,k;
    cin>>n>>k;
    ll rounding = powl(10,k);
    ll gcd =__gcd(rounding,n);
    cout<<(rounding*n)/gcd<<endl;
}
